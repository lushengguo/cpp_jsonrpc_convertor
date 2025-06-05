#pragma once 

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <mutex>
#include <thread>
#include <chrono>
#include <future>
#include "client.h"
#include "define.h"
#include "interface.h"
#include "jsonrpc.h"
#include "server.h"

using namespace std::chrono_literals;

std::unique_ptr<plugin_rpc_server> server;
std::unique_ptr<executor_rpc_client> client;
std::once_flag init_flag_;

class RpcTestFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        std::call_once(init_flag_, []() {
            // Start plugin RPC server on port 18080
            server = std::make_unique<plugin_rpc_server>();
            std::thread run1([]() { server->start(18080); });
            run1.detach();

            std::this_thread::sleep_for(100ms); // Allow servers to start

            // Create clients
            client = std::make_unique<executor_rpc_client>("127.0.0.1", 18080);

            // Wait for connections to establish
            std::this_thread::sleep_for(100ms);
        });
    }

    void TearDown() override { }
};

static unsigned int seed = 12345; // Fixed seed for reproducible tests

// Simple LCG random number generator for cross-platform compatibility
unsigned char GetRandomByte()
{
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return (unsigned char)(seed % 256);
}

// Function to fill any struct with random bytes
template <typename T>
void FillWithRandomBytes(T& s)
{
    unsigned char* ptr = reinterpret_cast<unsigned char*>(&s);
    for (size_t i = 0; i < sizeof(T); ++i) {
        ptr[i] = GetRandomByte();
    }
}

template <typename T>
T random_value()
{
    T s;
    FillWithRandomBytes(s);
    return s;
}