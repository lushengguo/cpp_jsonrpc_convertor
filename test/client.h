
#pragma once
#include "client.h"
#include "define.h"
#include "functional"
#include "jsonrpc.h"
#include "server.h"

class executor_rpc_client : public json_rpc_client {
 public:
  executor_rpc_client(std::string rpc_server_ip, unsigned short rpc_server_port)
      : json_rpc_client(rpc_server_ip, rpc_server_port) {}

  void MtSrvAbout_Rpc(testA* info) override final;
  int MtSrvStartup_Rpc() override final;
  void MtSrvCleanup_Rpc() override final;
  int MtSrvPluginCfgAdd_Rpc(const testA* cfg) override final;
  int MtSrvPluginCfgSet_Rpc(const testA* values,
                            const int total) override final;
  int MtSrvPluginCfgDelete_Rpc(LPCSTR name) override final;
  int MtSrvPluginCfgGet_Rpc(LPCSTR name, testA* cfg) override final;
  int MtSrvPluginCfgNext_Rpc(const int index, testA* cfg) override final;
  int MtSrvPluginCfgTotal_Rpc() override final;
  void MtSrvTradeRequestApply_Rpc(testA* request,
                                  const int isdemo) override final;
  int MtSrvTradeStopsFilter_Rpc(const testA* group, const testA* symbol,
                                const testA* trade) override final;
  int MtSrvTradeStopsApply_Rpc(const testA* user, const testA* group,
                               const testA* symbol, testA* trade,
                               const int isTP) override final;
  int MtSrvTradePendingsFilter_Rpc(const testA* group, const testA* symbol,
                                   const testA* trade) override final;
  int MtSrvTradePendingsApply_Rpc(const testA* user, const testA* group,
                                  const testA* symbol, const testA* pending,
                                  testA* trade) override final;
  int MtSrvTradeStopoutsFilter_Rpc(const testA* group, const testA* symbol,
                                   const int login, const double equity,
                                   const double margin) override final;
  int MtSrvTradeStopoutsApply_Rpc(const testA* user, const testA* group,
                                  const testA* symbol,
                                  testA* stopout) override final;
  void MtSrvTradesAddRequest_Rpc(testA* trade, const testA* request,
                                 const testA* user, const testA* symbol,
                                 const int mode) override final;
  int MtSrvTradeTransaction_Rpc(testA* trade, testA* user,
                                testA* request_id) override final;
  void MtSrvTradeCommission_Rpc(testA* trade, const testA* Sec,
                                const testA* Grp) override final;
  int MtSrvTradeCommissionAgent_Rpc(testA* trade, const testA* sec,
                                    const testA* info) override final;
  void MtSrvHistoryTickApply_Rpc(const testA* symbol,
                                 testA* inf) override final;
};

inline void executor_rpc_client::MtSrvAbout_Rpc(testA* info) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvAbout_G7DX", std::make_tuple(::rpc_format(info)),
        net::use_future);
    future.get().result;

    auto info_vector_OVQQ = ::rpc_parse<testA>(rpc_result.get<0>());
    testA* info_ptr_reqA = info_vector_OVQQ.data();
    if (info) memcpy(info, info_ptr_reqA, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvStartup_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvStartup_E0gE", net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvCleanup_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvCleanup_PKHr", net::use_future);
    future.get().result;

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvPluginCfgAdd_Rpc(const testA* cfg) {
  try {
    auto future = packio_client_->async_call("MtSrvPluginCfgAdd_CbA0",
                                             std::make_tuple(::rpc_format(cfg)),
                                             net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgSet_Rpc(const testA* values,
                                                      const int total) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgSet_tifQ", std::make_tuple(::rpc_format(values), total),
        net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgDelete_Rpc(LPCSTR name) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgDelete_vkKH",
        std::make_tuple(name ? std::string(name) : std::string()),
        net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgGet_Rpc(LPCSTR name, testA* cfg) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgGet_WMtN",
        std::make_tuple(name ? std::string(name) : std::string(),
                        ::rpc_format(cfg)),
        net::use_future);
    auto rpc_result = future.get().result;

    auto cfg_vector_3jXw = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* cfg_ptr_DxgR = cfg_vector_3jXw.data();
    if (cfg) memcpy(cfg, cfg_ptr_DxgR, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgNext_Rpc(const int index,
                                                       testA* cfg) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgNext_9LGj", std::make_tuple(index, ::rpc_format(cfg)),
        net::use_future);
    auto rpc_result = future.get().result;

    auto cfg_vector_Sc1A = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* cfg_ptr_dTeS = cfg_vector_Sc1A.data();
    if (cfg) memcpy(cfg, cfg_ptr_dTeS, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgTotal_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvPluginCfgTotal_cffM", net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvTradeRequestApply_Rpc(testA* request,
                                                            const int isdemo) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeRequestApply_yL5z",
        std::make_tuple(::rpc_format(request), isdemo), net::use_future);
    future.get().result;

    auto request_vector_Lo7X = ::rpc_parse<testA>(rpc_result.get<0>());
    testA* request_ptr_qu1X = request_vector_Lo7X.data();
    if (request) memcpy(request, request_ptr_qu1X, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeStopsFilter_Rpc(const testA* group,
                                                          const testA* symbol,
                                                          const testA* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopsFilter_l8h6",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol),
                        ::rpc_format(trade)),
        net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvTradeStopsApply_Rpc(const testA* user,
                                                         const testA* group,
                                                         const testA* symbol,
                                                         testA* trade,
                                                         const int isTP) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopsApply_oFkn",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(trade), isTP),
        net::use_future);
    auto rpc_result = future.get().result;

    auto trade_vector_tW24 = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* trade_ptr_tPdx = trade_vector_tW24.data();
    if (trade) memcpy(trade, trade_ptr_tPdx, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvTradePendingsFilter_Rpc(
    const testA* group, const testA* symbol, const testA* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradePendingsFilter_0RQG",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol),
                        ::rpc_format(trade)),
        net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvTradePendingsApply_Rpc(
    const testA* user, const testA* group, const testA* symbol,
    const testA* pending, testA* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradePendingsApply_p9q6",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(pending),
                        ::rpc_format(trade)),
        net::use_future);
    auto rpc_result = future.get().result;

    auto trade_vector_v9pm = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* trade_ptr_3Hc2 = trade_vector_v9pm.data();
    if (trade) memcpy(trade, trade_ptr_3Hc2, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvTradeStopoutsFilter_Rpc(
    const testA* group, const testA* symbol, const int login,
    const double equity, const double margin) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopoutsFilter_zpw6",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol), login,
                        equity, margin),
        net::use_future);
    auto rpc_result = future.get().result;

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvTradeStopoutsApply_Rpc(const testA* user,
                                                            const testA* group,
                                                            const testA* symbol,
                                                            testA* stopout) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopoutsApply_7mFc",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(stopout)),
        net::use_future);
    auto rpc_result = future.get().result;

    auto stopout_vector_dwlL = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* stopout_ptr_5cpw = stopout_vector_dwlL.data();
    if (stopout) memcpy(stopout, stopout_ptr_5cpw, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvTradesAddRequest_Rpc(testA* trade,
                                                           const testA* request,
                                                           const testA* user,
                                                           const testA* symbol,
                                                           const int mode) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradesAddRequest_RkK3",
        std::make_tuple(::rpc_format(trade), ::rpc_format(request),
                        ::rpc_format(user), ::rpc_format(symbol), mode),
        net::use_future);
    future.get().result;

    auto trade_vector_cqA1 = ::rpc_parse<testA>(rpc_result.get<0>());
    testA* trade_ptr_ZU2b = trade_vector_cqA1.data();
    if (trade) memcpy(trade, trade_ptr_ZU2b, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeTransaction_Rpc(testA* trade,
                                                          testA* user,
                                                          testA* request_id) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeTransaction_c7kx",
        std::make_tuple(::rpc_format(trade), ::rpc_format(user),
                        ::rpc_format(request_id)),
        net::use_future);
    auto rpc_result = future.get().result;

    auto trade_vector_Kq2m = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* trade_ptr_QSHl = trade_vector_Kq2m.data();
    if (trade) memcpy(trade, trade_ptr_QSHl, sizeof(testA));
    auto user_vector_aJqW = ::rpc_parse<testA>(rpc_result.get<2>());
    testA* user_ptr_zL87 = user_vector_aJqW.data();
    if (user) memcpy(user, user_ptr_zL87, sizeof(testA));
    auto request_id_vector_RCLH = ::rpc_parse<testA>(rpc_result.get<3>());
    testA* request_id_ptr_EfnR = request_id_vector_RCLH.data();
    if (request_id) memcpy(request_id, request_id_ptr_EfnR, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvTradeCommission_Rpc(testA* trade,
                                                          const testA* Sec,
                                                          const testA* Grp) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeCommission_MeFx",
        std::make_tuple(::rpc_format(trade), ::rpc_format(Sec),
                        ::rpc_format(Grp)),
        net::use_future);
    future.get().result;

    auto trade_vector_fpfW = ::rpc_parse<testA>(rpc_result.get<0>());
    testA* trade_ptr_9Qxc = trade_vector_fpfW.data();
    if (trade) memcpy(trade, trade_ptr_9Qxc, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeCommissionAgent_Rpc(
    testA* trade, const testA* sec, const testA* info) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeCommissionAgent_YGkX",
        std::make_tuple(::rpc_format(trade), ::rpc_format(sec),
                        ::rpc_format(info)),
        net::use_future);
    auto rpc_result = future.get().result;

    auto trade_vector_qENz = ::rpc_parse<testA>(rpc_result.get<1>());
    testA* trade_ptr_zX8a = trade_vector_qENz.data();
    if (trade) memcpy(trade, trade_ptr_zX8a, sizeof(testA));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvHistoryTickApply_Rpc(const testA* symbol,
                                                           testA* inf) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvHistoryTickApply_IbhS",
        std::make_tuple(::rpc_format(symbol), ::rpc_format(inf)),
        net::use_future);
    future.get().result;

    auto inf_vector_UR8F = ::rpc_parse<testA>(rpc_result.get<0>());
    testA* inf_ptr_BOjZ = inf_vector_UR8F.data();
    if (inf) memcpy(inf, inf_ptr_BOjZ, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}
