#pragma once 

#include <cppcodec/base64_rfc4648.hpp>
#include <spdlog/spdlog.h>

struct testA {
    int a;
    double b;
};

struct testB {
    int c;
    double d;
};

template <typename any_pod_type>
inline std::string rpc_format(const any_pod_type* p)
{
    if (not p)
        return "";

    return cppcodec::base64_rfc4648::encode((uint8_t*)p, sizeof(any_pod_type));
}

template <typename any_pod_type>
inline std::string rpc_format(const any_pod_type* p, size_t len)
{
    if (not p or len == 0)
        return "";

    return cppcodec::base64_rfc4648::encode((uint8_t*)p, sizeof(any_pod_type) * len);
}

template <typename any_pod_type>
inline std::vector<any_pod_type> rpc_parse(const std::string& str)
{
    try {
        std::vector<any_pod_type> vector;
        if (str.empty()) {
            return vector;
        }
        auto decoded = cppcodec::base64_rfc4648::decode(str);
        vector.resize(decoded.size() / sizeof(any_pod_type));
        memcpy(vector.data(), decoded.data(), decoded.size());
        return vector;
    } catch (const std::exception& e) {
        SPDLOG_ERROR("Failed to decode base64 string: {}", e.what());
        return {};
    }
}