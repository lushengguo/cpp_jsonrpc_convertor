import os
import regex

import subprocess


def format_cpp_code(content, style="Google"):
    """Format C++ code using clang-format"""
    try:
        result = subprocess.run(
            ["clang-format", f"--style={style}"],
            input=content,
            text=True,
            capture_output=True,
            check=True,
        )
        return result.stdout
    except subprocess.CalledProcessError as e:
        raise RuntimeError(f"clang-format failed: {e.stderr}")
    except FileNotFoundError:
        raise RuntimeError("clang-format not found. Please install clang-format.")

index = 0
def stable_unique_suffix():
    global index
    index += 1
    return str(index)

def type_remove_const_and_pointer(type_str):
    """Remove 'const' and '*' from the type string."""
    type_str = type_str.replace("const ", "")
    type_str = type_str.replace("*", "")
    return type_str.strip()


class Variable:
    def __init__(self, name, type, ouput_rank_index, return_type):
        self._name = name
        self._type = type
        self._ouput_rank_index = ouput_rank_index
        self._function_return_type = type_remove_const_and_pointer(return_type)
        self._unformat_vector_name = None
        self._unformat_pointer_name = None

    def __str__(self):
        return f"{self._type} {self._name}"

    def type_in_json(self):
        if self.is_pointer():
            return "std::string"
        elif self._type == "LPCSTR":
            return "std::string"
        return self._type

    def name_in_json(self):
        if self.is_pointer():
            return f"{self._name}_format"
        return self._name

    def is_pointer(self):
        return self._type.find("*") != -1

    def is_const(self):
        return self._type.find("const ") != -1

    def is_output(self):
        return self.is_pointer() and not self.is_const()

    def from_signature_input_parameter(input, ouput_rank_index, return_type):
        # find last '[\w_]+'
        # This regex matches a valid C++ identifier (variable name)
        match = regex.search(r"[\w_]+$", input)
        if not match:
            raise ValueError("Invalid input parameter format")
        # Extract the variable name
        variable_name = match.group(0)
        type = input[: match.start()].strip()
        return Variable(variable_name, type, ouput_rank_index, return_type)

    def client_side_serialize(self):
        # in my requirment, struct type only pass by pointer
        if self.is_pointer():
            return f"::rpc_format({self._name})"
        elif self._type == "LPCSTR":
            return f"{self._name} ? std::string({self._name}) : std::string()"
        return f"{self._name}"

    def server_side_serialize(self):
        if self.is_pointer():
            return f"::rpc_format({self.unformat_pointer_name()})"
        elif self._type == "LPCSTR":
            return f"{self._name} ? std::string({self._name}) : std::string()"
        return self._name

    def tuple_index(self, consider_function_return_type):
        tuple_index = self._ouput_rank_index
        if (
            not consider_function_return_type
        ):  # have to consider return type placeholder
            if self._function_return_type != "void":
                tuple_index += 1
        return tuple_index

    def deserialize_client_side(self, consider_function_return_type):
        ouput_rank_index = self.tuple_index(consider_function_return_type)

        return f"""
            auto {self.unformat_vector_name()} = ::rpc_parse<{type_remove_const_and_pointer(self._type)}>(
                std::get<{ouput_rank_index}>(rpc_result));
            {self._type} {self.unformat_pointer_name()} = {self.unformat_vector_name()}.data();
        """

    def deserialize_server_side(self, consider_function_return_type):
        ouput_rank_index = self.tuple_index(consider_function_return_type)

        return f"""
            auto {self.unformat_vector_name()} = ::rpc_parse<{type_remove_const_and_pointer(self._type)}>(
                {self.name_in_json()});
            {self._type} {self.unformat_pointer_name()} = {self.unformat_vector_name()}.data();
        """

    def unformat_vector_name(self):
        if self._unformat_vector_name is not None:
            return self._unformat_vector_name
        self._unformat_vector_name = f"{self._name}_vector_{stable_unique_suffix()}"
        return self._unformat_vector_name

    def unformat_pointer_name(self):
        if self._unformat_pointer_name is not None:
            return self._unformat_pointer_name
        self._unformat_pointer_name = f"{self._name}_ptr_{stable_unique_suffix()}"
        return self._unformat_pointer_name

    def input_name_in_test(self):
        return self._name + "_input"

    def output_name_in_test(self):
        return self._name + "_output"

    def initialize_self_in_test(self, is_input):
        name = self.input_name_in_test() if is_input else self.output_name_in_test()
        if self._type == "LPCSTR":
            return f'{self._type} {name} = "abcdefg";'
        elif self.is_pointer():
            return f"{type_remove_const_and_pointer(self._type)} {name} = random_value<{type_remove_const_and_pointer(self._type)}>();"
        else:
            return f"{self._type} {name} = random_value<{type_remove_const_and_pointer(self._type)}>();"


class Method:
    def __init__(self, name, return_type, args):
        self._name = name
        self._return_type = return_type
        self._args = args
        self._rpc_internal_name = f"{name}_{stable_unique_suffix()}"

    def __str__(self):
        return f"{self._return_type} {self._name}({self.arg_list()});"

    def jsonrpc_return_type(self):
        return_type = "std::tuple<"
        if self._return_type != "void":
            return_type += f"{self._return_type}, "
        for arg in self._args:
            if arg.is_output():
                return_type += f"{arg.type_in_json()}, "
        if return_type == "std::tuple<":
            return "void"
        return return_type[:-2] + ">"

    def from_signature(signature):
        return_type = signature[: signature.find(" ")]
        name_start = signature.find(" ") + 1
        name_end = signature.find("(")
        name = signature[name_start:name_end].strip()
        args_str = signature[name_end + 1 : signature.rfind(")")].strip()
        args = []
        if args_str:
            ouput_rank_index = 0
            args_list = args_str.split(",")
            for arg in args_list:
                arg = arg.strip()
                if arg:
                    args.append(
                        Variable.from_signature_input_parameter(
                            arg, ouput_rank_index, return_type
                        )
                    )
                    if args[-1].is_output():
                        ouput_rank_index += 1
        return Method(name, return_type, args)

    def return_type_is_void(self):
        return self._return_type.strip() == "void"

    def callback_name(self):
        return f"{self._rpc_internal_name}_callback_"

    def arg_list(self):
        return ", ".join(str(arg) for arg in self._args)


class RpcGenerator:

    def __init__(
        self,
        methods,
        interface_class_name,
        server_class_name,
        client_class_name,
        method_prefix="",
        method_suffix="_Rpc",
    ):
        self._methods = methods
        self._server_class_name = server_class_name
        self._client_class_name = client_class_name
        self._method_prefix = method_prefix
        self._method_suffix = method_suffix
        self._interface_class_name = interface_class_name

    def method_name(self, method):
        return f"{self._method_prefix}{method._name}{self._method_suffix}"

    def generate_interface_class_body(self):
        method_list = []
        for method in self._methods:
            method_list.append(
                f"virtual {method._return_type} {self.method_name(method)}({method.arg_list()}) = 0;"
            )

        body = f"""
        class {self._interface_class_name} {{
        public:
            {''.join(method_list)}
        }};\n\n
        """
        return "#pragma once\n" + body

    def generate_client_class_body(self):
        method_list = []
        for method in self._methods:
            method_list.append(
                f"{method._return_type} {self.method_name(method)}({method.arg_list()}) override final;"
            )

        body = f"""
        class {self._client_class_name} : public json_rpc_client, public {self._interface_class_name} {{
        public:
            {self._client_class_name}(std::string rpc_server_ip, unsigned short rpc_server_port)
                : json_rpc_client(rpc_server_ip, rpc_server_port){{}}
            
            {''.join(method_list)}
        }};\n\n
        """
        return body

    def make_tuple_identifier(self, input_parameter):
        return "" if input_parameter == "" else f"std::make_tuple({input_parameter})"

    def generate_client_side_code(self):
        includes = """
            #pragma once
            #include "define.h"
            #include "jsonrpc.h"
            #include "client.h"
            #include "server.h"
            #include "interface.h"
            #include <functional>
        """
        body = ""
        for method in self._methods:
            deserialize_body = ""
            for arg in method._args:
                if not arg.is_output():
                    continue
                d_body = arg.deserialize_client_side(False)
                deserialize_body += d_body
                deserialize_body += f"if({arg._name})memcpy({arg._name}, {arg.unformat_pointer_name()}, sizeof({type_remove_const_and_pointer(arg._type)}));"

            body += f"inline {method._return_type} {self._client_class_name}::{self.method_name(method)}({method.arg_list()}) {{\n"
            make_tuple_part = self.make_tuple_identifier(
                ", ".join(arg.client_side_serialize() for arg in method._args)
            )
            make_tuple_part = f",{make_tuple_part}" if len(make_tuple_part) > 0 else ""

            parse_future_part = ""
            if method.jsonrpc_return_type() == "void":
                parse_future_part = "future.get();"
            else:
                parse_future_part = f"""
                    auto future_result = future.get().result;
                    auto rpc_result = boost::json::value_to<{method.jsonrpc_return_type()}>(future_result);
                """

            body += f"""
            try{{
                auto future = packio_client_->async_call("{method._rpc_internal_name}"{make_tuple_part}, net::use_future);
                {parse_future_part}
                {deserialize_body}
                
                {"" if method.return_type_is_void() else f"return std::get<0>(rpc_result);"}
            }} catch (const std::exception& e) {{
                SPDLOG_CRITICAL("RPC call failed: {{}}", e.what());
                {"" if method.return_type_is_void() else "return -1;"}  
            }}"""
            body += "}\n\n"
        return includes + self.generate_client_class_body() + body

    def generate_server_class_body(self):
        callback_list = []
        for method in self._methods:
            types = ", ".join(f"{arg._type}" for arg in method._args)
            callback_list.append(
                f"std::function<{method._return_type}({types})> {method.callback_name()};"
            )
        body = f"""
        class {self._server_class_name} : public json_rpc_server {{
        public:
            bool register_method() override final;
            {''.join(callback_list)}
        }};\n\n
        """
        return body

    def generate_server_side_code(self):
        includes = """
            #pragma once
            #include "define.h"
            #include "jsonrpc.h"
            #include "client.h"
            #include "server.h"
            #include "interface.h"
            #include <functional>
        """
        body = f"inline bool {self._server_class_name}::register_method(){{"
        for method in self._methods:
            args_str = ", ".join(
                f"{arg.type_in_json()} {arg.name_in_json()}" for arg in method._args
            )
            service_body = ""
            callback_input_list = []
            for arg in method._args:
                if arg.is_pointer():
                    service_body += arg.deserialize_server_side(True)
                    callback_input_list.append(arg.unformat_pointer_name())
                elif arg._type == "LPCSTR":
                    callback_input_list.append(arg.name_in_json() + ".c_str()")
                else:
                    callback_input_list.append(arg.name_in_json())

            callback_part = (
                f"{method.callback_name()}({', '.join(callback_input_list)})"
            )
            if method._return_type != "void":
                service_body += f"""
                    auto result = {callback_part};
                """
            else:
                service_body += f"""
                    {callback_part};
                """

            make_tuple_part = "\nstd::make_tuple("
            if method._return_type != "void":
                make_tuple_part += f"result,"
            make_tuple_part += ",".join(
                f"{arg.server_side_serialize()}"
                for arg in method._args
                if arg.is_output()
            )
            make_tuple_part += ");"

            make_tuple_part = make_tuple_part.strip()
            if make_tuple_part == "std::make_tuple();":
                make_tuple_part = ""
            else:
                make_tuple_part = "return " + make_tuple_part
            make_tuple_part = make_tuple_part.replace(",)", ")")

            return_identifier = (
                f"-> {method.jsonrpc_return_type()}"
                if method.jsonrpc_return_type() != "void"
                else ""
            )

            body += f"""
                dispatcher()->add("{method._rpc_internal_name}",[this]({args_str}){return_identifier}
                {{{service_body}{make_tuple_part}}});
            """

        body += "return true;}\n"

        return includes + self.generate_server_class_body() + body

    def generate_test_code(self):
        body = """
        #include <gtest/gtest.h>
        #include "define.h"
        #include "jsonrpc.h"
        #include "client.h"
        #include "server.h"
        #include "interface.h"
        #include <functional>
        #include "test_helper.h"
        """
        for method in self._methods:
            first_argument = "RpcTestFixture"
            second_argument = method._rpc_internal_name
            body += f"TEST_F({first_argument}, {second_argument}) {{\n"

            body += "// input parameters\n"
            for arg in method._args:
                body += arg.initialize_self_in_test(True)

            body += "\n\n// output parameters\n"
            for arg in method._args:
                if arg.is_output():
                    body += arg.initialize_self_in_test(False)

            if method._return_type != "void":
                body += f"\n\n// return value\n"
                body += f"{method._return_type} rpc_result_output = 1;\n"

            args_str = ", ".join(str(arg) for arg in method._args)
            callback_body = ""

            body += f"\n\n// diy callback\n"
            callback_body = "// check input\n"
            for arg in method._args:
                first_argument = "&" + arg.input_name_in_test()
                second_argument = arg._name if arg.is_pointer() else "&" + arg._name
                callback_body += f"EXPECT_EQ(memcmp({first_argument}, {second_argument}, sizeof({arg._type.replace('*', '')})), 0);\n"

            callback_body += "\n\n// assign output\n"
            for arg in method._args:
                if arg.is_output():
                    first_argument = arg._name if arg.is_pointer() else "&" + arg._name
                    second_argument = "&" + arg.output_name_in_test()
                    callback_body += f"memcpy({first_argument}, {second_argument}, sizeof({arg._type.replace('*', '')}));\n"
            callback_body += "\n\n// return value\n"
            if method._return_type != "void":
                callback_body += f"return rpc_result_output;\n"

            body += f"server->{method.callback_name()} = [&]({args_str}){{\n{callback_body}}};\n"

            body += f"\n\n// call the RPC method\n"
            body += "" if method.return_type_is_void() else f"auto rpc_result = "
            body += f"client->{self.method_name(method)}({', '.join((("&" if arg.is_pointer() else "") + arg.input_name_in_test()) for arg in method._args)});\n"

            body += f"\n\n// check the result\n"
            if method._return_type != "void":
                body += f"EXPECT_EQ(rpc_result, rpc_result_output);\n"
            for arg in method._args:
                if arg.is_output():
                    first_argument = "&" + arg.output_name_in_test()
                    second_argument = "&" + arg.input_name_in_test()
                    body += f"EXPECT_EQ(memcmp({first_argument}, {second_argument}, sizeof({arg._type.replace('*', '')})), 0);\n"

            body += f"}}\n\n"

        pattern = r'memcmp\(\s*&?(\w+),\s*&?(\w+),\s*sizeof\(LPCSTR\)\s*\)'
        replacement = r'strcmp(\1, \2)'
        body = regex.sub(pattern, replacement, body)

        body += """
        int main(int argc, char** argv) {
            ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }
        """
        return body


def read_interface_file(file_path):
    if not os.path.exists(file_path):
        raise FileNotFoundError(f"File {file_path} does not exist.")

    with open(file_path, "r") as file:
        content = file.read()

    return content


def handle_interface_content(content):
    methods = []
    lines = content.splitlines()

    for line in lines:
        line = line.strip()
        if not line or line.startswith("//"):
            continue  # Skip empty lines and comments
        if "(" in line and ")" in line:
            try:
                method = Method.from_signature(line)
                methods.append(method)
            except ValueError as e:
                print(f"Error parsing method signature '{line}': {e}")

    return methods


def entrance(
    interface_path, interface_class_name, client_class_name, server_class_name
):
    content = read_interface_file(interface_path)
    methods = handle_interface_content(content)

    rpc_generator = RpcGenerator(
        methods, interface_class_name, server_class_name, client_class_name
    )
    output = ""

    client_impl = rpc_generator.generate_client_side_code()
    output += "// client side code:\n" + format_cpp_code(client_impl)
    with open(f"./test/client.h", "w") as f:
        f.write(format_cpp_code(client_impl))

    server_impl = rpc_generator.generate_server_side_code()
    output += "// server side code:\n" + format_cpp_code(server_impl)
    with open(f"./test/server.h", "w") as f:
        f.write(format_cpp_code(server_impl))

    test_impl = rpc_generator.generate_test_code()
    output += "// test code:\n" + format_cpp_code(test_impl)
    with open(f"./test/test.cpp", "w") as f:
        f.write(format_cpp_code(test_impl))

    interface_impl = rpc_generator.generate_interface_class_body()
    output += "// interface class body:\n" + format_cpp_code(interface_impl)
    with open(f"./test/interface.h", "w") as f:
        f.write(format_cpp_code(interface_impl))

    print(output)


if __name__ == "__main__":
    entrance(
        "hooks_rpc_interface.h",
        "hooks_rpc_interface",
        "plugin_rpc_client",
        "executor_rpc_server",
    )
""
