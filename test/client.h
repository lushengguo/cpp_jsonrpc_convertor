
#pragma once
#include <functional>

#include "client.h"
#include "define.h"
#include "interface.h"
#include "jsonrpc.h"
#include "server.h"

class executor_rpc_client : public json_rpc_client, public hooks_rpc_interface {
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
        "MtSrvAbout_FaoY", std::make_tuple(::rpc_format(info)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto info_vector_nkGG = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* info_ptr_PtWY = info_vector_nkGG.data();
    if (info) memcpy(info, info_ptr_PtWY, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvStartup_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvStartup_Vp7x", net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvCleanup_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvCleanup_6g2V", net::use_future);
    future.get();

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvPluginCfgAdd_Rpc(const testA* cfg) {
  try {
    auto future = packio_client_->async_call("MtSrvPluginCfgAdd_uEVd",
                                             std::make_tuple(::rpc_format(cfg)),
                                             net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgSet_Rpc(const testA* values,
                                                      const int total) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgSet_gGRa", std::make_tuple(::rpc_format(values), total),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgDelete_Rpc(LPCSTR name) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgDelete_uu7C",
        std::make_tuple(name ? std::string(name) : std::string()),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgGet_Rpc(LPCSTR name, testA* cfg) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgGet_3GCs",
        std::make_tuple(name ? std::string(name) : std::string(),
                        ::rpc_format(cfg)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto cfg_vector_Cxuy = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* cfg_ptr_w8Iw = cfg_vector_Cxuy.data();
    if (cfg) memcpy(cfg, cfg_ptr_w8Iw, sizeof(testA));

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgNext_Rpc(const int index,
                                                       testA* cfg) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgNext_bAVb", std::make_tuple(index, ::rpc_format(cfg)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto cfg_vector_BSPh = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* cfg_ptr_iHU1 = cfg_vector_BSPh.data();
    if (cfg) memcpy(cfg, cfg_ptr_iHU1, sizeof(testA));

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgTotal_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvPluginCfgTotal_r2W1", net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvTradeRequestApply_Rpc(testA* request,
                                                            const int isdemo) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeRequestApply_XpuX",
        std::make_tuple(::rpc_format(request), isdemo), net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto request_vector_nloW = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* request_ptr_scno = request_vector_nloW.data();
    if (request) memcpy(request, request_ptr_scno, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeStopsFilter_Rpc(const testA* group,
                                                          const testA* symbol,
                                                          const testA* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopsFilter_wbtO",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol),
                        ::rpc_format(trade)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
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
        "MtSrvTradeStopsApply_lDzq",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(trade), isTP),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto trade_vector_byy2 = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_5U6F = trade_vector_byy2.data();
    if (trade) memcpy(trade, trade_ptr_5U6F, sizeof(testA));

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvTradePendingsFilter_Rpc(
    const testA* group, const testA* symbol, const testA* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradePendingsFilter_RwNh",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol),
                        ::rpc_format(trade)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
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
        "MtSrvTradePendingsApply_2XO4",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(pending),
                        ::rpc_format(trade)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto trade_vector_2RlP = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_L8dP = trade_vector_2RlP.data();
    if (trade) memcpy(trade, trade_ptr_L8dP, sizeof(testA));

    return std::get<0>(rpc_result);
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
        "MtSrvTradeStopoutsFilter_1Rnz",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol), login,
                        equity, margin),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<std::tuple<int>>(future_result);

    return std::get<0>(rpc_result);
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
        "MtSrvTradeStopoutsApply_hi0p",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(stopout)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto stopout_vector_yXPf = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* stopout_ptr_YxdM = stopout_vector_yXPf.data();
    if (stopout) memcpy(stopout, stopout_ptr_YxdM, sizeof(testA));

    return std::get<0>(rpc_result);
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
        "MtSrvTradesAddRequest_E0Tz",
        std::make_tuple(::rpc_format(trade), ::rpc_format(request),
                        ::rpc_format(user), ::rpc_format(symbol), mode),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto trade_vector_X2WE = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* trade_ptr_paw5 = trade_vector_X2WE.data();
    if (trade) memcpy(trade, trade_ptr_paw5, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeTransaction_Rpc(testA* trade,
                                                          testA* user,
                                                          testA* request_id) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeTransaction_wpvK",
        std::make_tuple(::rpc_format(trade), ::rpc_format(user),
                        ::rpc_format(request_id)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<
        std::tuple<int, std::string, std::string, std::string>>(future_result);

    auto trade_vector_w6vD = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_Dljk = trade_vector_w6vD.data();
    if (trade) memcpy(trade, trade_ptr_Dljk, sizeof(testA));
    auto user_vector_3JCA = ::rpc_parse<testA>(std::get<2>(rpc_result));
    testA* user_ptr_b8vi = user_vector_3JCA.data();
    if (user) memcpy(user, user_ptr_b8vi, sizeof(testA));
    auto request_id_vector_SHvF = ::rpc_parse<testA>(std::get<3>(rpc_result));
    testA* request_id_ptr_xxrJ = request_id_vector_SHvF.data();
    if (request_id) memcpy(request_id, request_id_ptr_xxrJ, sizeof(testA));

    return std::get<0>(rpc_result);
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
        "MtSrvTradeCommission_NaKR",
        std::make_tuple(::rpc_format(trade), ::rpc_format(Sec),
                        ::rpc_format(Grp)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto trade_vector_78xN = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* trade_ptr_0gC3 = trade_vector_78xN.data();
    if (trade) memcpy(trade, trade_ptr_0gC3, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeCommissionAgent_Rpc(
    testA* trade, const testA* sec, const testA* info) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeCommissionAgent_ZItd",
        std::make_tuple(::rpc_format(trade), ::rpc_format(sec),
                        ::rpc_format(info)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto trade_vector_fQoL = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_yqMo = trade_vector_fQoL.data();
    if (trade) memcpy(trade, trade_ptr_yqMo, sizeof(testA));

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline void executor_rpc_client::MtSrvHistoryTickApply_Rpc(const testA* symbol,
                                                           testA* inf) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvHistoryTickApply_Jy9x",
        std::make_tuple(::rpc_format(symbol), ::rpc_format(inf)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto inf_vector_Q3H9 = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* inf_ptr_7aXK = inf_vector_Q3H9.data();
    if (inf) memcpy(inf, inf_ptr_7aXK, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}
