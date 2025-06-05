#pragma once
#ifndef RPC_SERVER_HPP
#define RPC_SERVER_HPP

#include "net.h"

#include <packio/packio.h>
#include <boost/json.hpp>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>
#include <memory>

namespace net = boost::asio;
using namespace std::literals;

class json_rpc_server {
public:
    virtual bool register_method() { return false; }

    bool start(unsigned short port)
    {
        SPDLOG_INFO("rpc server launch on port:{}", port);
        net::ip::tcp::endpoint bind_ep { net::ip::make_address("0.0.0.0"), port };
        packio_server_ = packio::json_rpc::make_server(net::ip::tcp::acceptor { get_io_context(), bind_ep });

        if (not register_method())
            return false;

        packio_server_->async_serve_forever();
        return true;
    }

    auto dispatcher() { return packio_server_->dispatcher(); }

private:
    std::shared_ptr<packio::json_rpc::server<boost::asio::ip::tcp::acceptor, packio::json_rpc::dispatcher<>>>
        packio_server_;
};

class json_rpc_client {
public:
    json_rpc_client(std::string rpc_server_ip, unsigned short rpc_server_port)
    {
        start(rpc_server_ip, rpc_server_port);
    }
    ~json_rpc_client() { SPDLOG_INFO("client stop"); }

    std::shared_ptr<packio::json_rpc::client<boost::asio::ip::tcp::socket, packio::default_map>> packio_client_;

private:
    void start(std::string rpc_server_ip, unsigned short rpc_server_port)
    {
        net::ip::tcp::endpoint bind_ep { net::ip::make_address(rpc_server_ip), rpc_server_port };
        packio_client_ = packio::json_rpc::make_client(net::ip::tcp::socket { get_io_context() });
        packio_client_->socket().connect(bind_ep);
    }
};

#endif // RPC_SERVER_HPP