add_requires("conan::packio/2.6.0#ad3ece32b4985b5969d64e8b3b5f45d0", { alias = "packio", debug = is_mode("debug"), configs = {settings = "compiler.cppstd=17", options={"packio/*:boost_json=True"}}})
add_requires("conan::gtest/1.14.0#25e2a474b4d1aecf5ff4f0555dcdf72c", { alias = "gtest" })
add_requires("conan::cppcodec/0.2", { alias = "cppcodec", debug = is_mode("debug") })
add_requires("conan::spdlog/1.15.1#92e99f07f134481bce4b70c1a41060e7", { alias = "spdlog" ,configs = {options={"spdlog/*:header_only = True"}}}) 

set_languages("c++20")

target "test"
set_kind("binary")
add_packages("packio", "gtest", "cppcodec", "spdlog")
add_files("*.cpp")

