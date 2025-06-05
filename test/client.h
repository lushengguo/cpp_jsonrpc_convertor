
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
        "MtSrvAbout_xag0", std::make_tuple(::rpc_format(info)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto info_vector_ZCjH = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* info_ptr_MF9p = info_vector_ZCjH.data();
    if (info) memcpy(info, info_ptr_MF9p, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvStartup_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvStartup_wqvx", net::use_future);

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
        packio_client_->async_call("MtSrvCleanup_cnya", net::use_future);
    future.get();

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvPluginCfgAdd_Rpc(const testA* cfg) {
  try {
    auto future = packio_client_->async_call("MtSrvPluginCfgAdd_lLd3",
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
        "MtSrvPluginCfgSet_TmFN", std::make_tuple(::rpc_format(values), total),
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
        "MtSrvPluginCfgDelete_nUU9",
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
        "MtSrvPluginCfgGet_Pc04",
        std::make_tuple(name ? std::string(name) : std::string(),
                        ::rpc_format(cfg)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto cfg_vector_lUfh = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* cfg_ptr_iZlG = cfg_vector_lUfh.data();
    if (cfg) memcpy(cfg, cfg_ptr_iZlG, sizeof(testA));

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
        "MtSrvPluginCfgNext_sQ05", std::make_tuple(index, ::rpc_format(cfg)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto cfg_vector_ZyHq = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* cfg_ptr_Vlo5 = cfg_vector_ZyHq.data();
    if (cfg) memcpy(cfg, cfg_ptr_Vlo5, sizeof(testA));

    return std::get<0>(rpc_result);
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

inline int executor_rpc_client::MtSrvPluginCfgTotal_Rpc() {
  try {
    auto future =
        packio_client_->async_call("MtSrvPluginCfgTotal_3ToP", net::use_future);

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
        "MtSrvTradeRequestApply_uuVJ",
        std::make_tuple(::rpc_format(request), isdemo), net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto request_vector_TG8m = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* request_ptr_UMkN = request_vector_TG8m.data();
    if (request) memcpy(request, request_ptr_UMkN, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeStopsFilter_Rpc(const testA* group,
                                                          const testA* symbol,
                                                          const testA* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopsFilter_Bi0U",
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
        "MtSrvTradeStopsApply_2crI",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(trade), isTP),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto trade_vector_fw86 = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_20BI = trade_vector_fw86.data();
    if (trade) memcpy(trade, trade_ptr_20BI, sizeof(testA));

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
        "MtSrvTradePendingsFilter_91ay",
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
        "MtSrvTradePendingsApply_4QyA",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(pending),
                        ::rpc_format(trade)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto trade_vector_yUuV = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_nQob = trade_vector_yUuV.data();
    if (trade) memcpy(trade, trade_ptr_nQob, sizeof(testA));

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
        "MtSrvTradeStopoutsFilter_FmdX",
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
        "MtSrvTradeStopoutsApply_n4Jz",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(stopout)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto stopout_vector_UmfF = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* stopout_ptr_3V16 = stopout_vector_UmfF.data();
    if (stopout) memcpy(stopout, stopout_ptr_3V16, sizeof(testA));

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
        "MtSrvTradesAddRequest_MuDN",
        std::make_tuple(::rpc_format(trade), ::rpc_format(request),
                        ::rpc_format(user), ::rpc_format(symbol), mode),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto trade_vector_ZHdX = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* trade_ptr_dXlU = trade_vector_ZHdX.data();
    if (trade) memcpy(trade, trade_ptr_dXlU, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeTransaction_Rpc(testA* trade,
                                                          testA* user,
                                                          testA* request_id) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeTransaction_K8PA",
        std::make_tuple(::rpc_format(trade), ::rpc_format(user),
                        ::rpc_format(request_id)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result = boost::json::value_to<
        std::tuple<int, std::string, std::string, std::string>>(future_result);

    auto trade_vector_5rcd = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_JPoC = trade_vector_5rcd.data();
    if (trade) memcpy(trade, trade_ptr_JPoC, sizeof(testA));
    auto user_vector_z4FI = ::rpc_parse<testA>(std::get<2>(rpc_result));
    testA* user_ptr_r27a = user_vector_z4FI.data();
    if (user) memcpy(user, user_ptr_r27a, sizeof(testA));
    auto request_id_vector_GFYV = ::rpc_parse<testA>(std::get<3>(rpc_result));
    testA* request_id_ptr_GwdV = request_id_vector_GFYV.data();
    if (request_id) memcpy(request_id, request_id_ptr_GwdV, sizeof(testA));

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
        "MtSrvTradeCommission_vgqL",
        std::make_tuple(::rpc_format(trade), ::rpc_format(Sec),
                        ::rpc_format(Grp)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto trade_vector_tJ33 = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* trade_ptr_7nJs = trade_vector_tJ33.data();
    if (trade) memcpy(trade, trade_ptr_7nJs, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

inline int executor_rpc_client::MtSrvTradeCommissionAgent_Rpc(
    testA* trade, const testA* sec, const testA* info) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeCommissionAgent_55QD",
        std::make_tuple(::rpc_format(trade), ::rpc_format(sec),
                        ::rpc_format(info)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<int, std::string>>(future_result);

    auto trade_vector_6njM = ::rpc_parse<testA>(std::get<1>(rpc_result));
    testA* trade_ptr_uHzK = trade_vector_6njM.data();
    if (trade) memcpy(trade, trade_ptr_uHzK, sizeof(testA));

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
        "MtSrvHistoryTickApply_49xM",
        std::make_tuple(::rpc_format(symbol), ::rpc_format(inf)),
        net::use_future);

    auto future_result = future.get().result;
    auto rpc_result =
        boost::json::value_to<std::tuple<std::string>>(future_result);

    auto inf_vector_viwJ = ::rpc_parse<testA>(std::get<0>(rpc_result));
    testA* inf_ptr_O399 = inf_vector_viwJ.data();
    if (inf) memcpy(inf, inf_ptr_O399, sizeof(testA));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}
