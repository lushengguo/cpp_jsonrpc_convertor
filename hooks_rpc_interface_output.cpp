// client side code:

class hooks_rpc_interface {
 public:
  virtual void MtSrvAbout_Rpc(PluginInfo* info) = 0;
  virtual int MtSrvStartup_Rpc() = 0;
  virtual void MtSrvCleanup_Rpc() = 0;
  virtual int MtSrvPluginCfgAdd_Rpc(const PluginCfg* cfg) = 0;
  virtual int MtSrvPluginCfgSet_Rpc(const PluginCfg* values,
                                    const int total) = 0;
  virtual int MtSrvPluginCfgDelete_Rpc(LPCSTR name) = 0;
  virtual int MtSrvPluginCfgGet_Rpc(LPCSTR name, PluginCfg* cfg) = 0;
  virtual int MtSrvPluginCfgNext_Rpc(const int index, PluginCfg* cfg) = 0;
  virtual int MtSrvPluginCfgTotal_Rpc() = 0;
  virtual void MtSrvTradeRequestApply_Rpc(RequestInfo* request,
                                          const int isdemo) = 0;
  virtual int MtSrvTradeStopsFilter_Rpc(const ConGroup* group,
                                        const ConSymbol* symbol,
                                        const TradeRecord* trade) = 0;
  virtual int MtSrvTradeStopsApply_Rpc(const UserInfo* user,
                                       const ConGroup* group,
                                       const ConSymbol* symbol,
                                       TradeRecord* trade, const int isTP) = 0;
  virtual int MtSrvTradePendingsFilter_Rpc(const ConGroup* group,
                                           const ConSymbol* symbol,
                                           const TradeRecord* trade) = 0;
  virtual int MtSrvTradePendingsApply_Rpc(const UserInfo* user,
                                          const ConGroup* group,
                                          const ConSymbol* symbol,
                                          const TradeRecord* pending,
                                          TradeRecord* trade) = 0;
  virtual int MtSrvTradeStopoutsFilter_Rpc(const ConGroup* group,
                                           const ConSymbol* symbol,
                                           const int login, const double equity,
                                           const double margin) = 0;
  virtual int MtSrvTradeStopoutsApply_Rpc(const UserInfo* user,
                                          const ConGroup* group,
                                          const ConSymbol* symbol,
                                          TradeRecord* stopout) = 0;
  virtual void MtSrvTradesAddRequest_Rpc(TradeRecord* trade,
                                         const RequestInfo* request,
                                         const UserInfo* user,
                                         const ConSymbol* symbol,
                                         const int mode) = 0;
  virtual int MtSrvTradeTransaction_Rpc(TradeTransInfo* trade, UserInfo* user,
                                        int* request_id) = 0;
  virtual void MtSrvTradeCommission_Rpc(TradeRecord* trade,
                                        const ConSymbol* Sec,
                                        const ConGroup* Grp) = 0;
  virtual int MtSrvTradeCommissionAgent_Rpc(TradeRecord* trade,
                                            const ConSymbol* sec,
                                            const UserInfo* info) = 0;
  virtual void MtSrvHistoryTickApply_Rpc(const ConSymbol* symbol,
                                         FeedTick* inf) = 0;
};

class executor_rpc_client : public json_rpc_client {
 public:
  executor_rpc_client(std::string rpc_server_ip, unsigned short rpc_server_port)
      : json_rpc_client(rpc_server_ip, rpc_server_port) {}

  void MtSrvAbout_Rpc(PluginInfo* info) override final;
  int MtSrvStartup_Rpc() override final;
  void MtSrvCleanup_Rpc() override final;
  int MtSrvPluginCfgAdd_Rpc(const PluginCfg* cfg) override final;
  int MtSrvPluginCfgSet_Rpc(const PluginCfg* values,
                            const int total) override final;
  int MtSrvPluginCfgDelete_Rpc(LPCSTR name) override final;
  int MtSrvPluginCfgGet_Rpc(LPCSTR name, PluginCfg* cfg) override final;
  int MtSrvPluginCfgNext_Rpc(const int index, PluginCfg* cfg) override final;
  int MtSrvPluginCfgTotal_Rpc() override final;
  void MtSrvTradeRequestApply_Rpc(RequestInfo* request,
                                  const int isdemo) override final;
  int MtSrvTradeStopsFilter_Rpc(const ConGroup* group, const ConSymbol* symbol,
                                const TradeRecord* trade) override final;
  int MtSrvTradeStopsApply_Rpc(const UserInfo* user, const ConGroup* group,
                               const ConSymbol* symbol, TradeRecord* trade,
                               const int isTP) override final;
  int MtSrvTradePendingsFilter_Rpc(const ConGroup* group,
                                   const ConSymbol* symbol,
                                   const TradeRecord* trade) override final;
  int MtSrvTradePendingsApply_Rpc(const UserInfo* user, const ConGroup* group,
                                  const ConSymbol* symbol,
                                  const TradeRecord* pending,
                                  TradeRecord* trade) override final;
  int MtSrvTradeStopoutsFilter_Rpc(const ConGroup* group,
                                   const ConSymbol* symbol, const int login,
                                   const double equity,
                                   const double margin) override final;
  int MtSrvTradeStopoutsApply_Rpc(const UserInfo* user, const ConGroup* group,
                                  const ConSymbol* symbol,
                                  TradeRecord* stopout) override final;
  void MtSrvTradesAddRequest_Rpc(TradeRecord* trade, const RequestInfo* request,
                                 const UserInfo* user, const ConSymbol* symbol,
                                 const int mode) override final;
  int MtSrvTradeTransaction_Rpc(TradeTransInfo* trade, UserInfo* user,
                                int* request_id) override final;
  void MtSrvTradeCommission_Rpc(TradeRecord* trade, const ConSymbol* Sec,
                                const ConGroup* Grp) override final;
  int MtSrvTradeCommissionAgent_Rpc(TradeRecord* trade, const ConSymbol* sec,
                                    const UserInfo* info) override final;
  void MtSrvHistoryTickApply_Rpc(const ConSymbol* symbol,
                                 FeedTick* inf) override final;
};

void executor_rpc_client::MtSrvAbout_Rpc(PluginInfo* info) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvAbout_Z7Qm", std::make_tuple(::rpc_format(info)),
        net::use_future);
    future.get();

    auto info_vector_9gwJ = ::rpc_parse<PluginInfo>(rpc_result.get<0>());
    PluginInfo* info_ptr_fICf = info_vector_9gwJ.data();
    if (info) memcpy(info, info_ptr_fICf, sizeof(PluginInfo));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

int executor_rpc_client::MtSrvStartup_Rpc() {
  try {
    auto future = packio_client_->async_call(
        "MtSrvStartup_a5XX", std::make_tuple(), net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

void executor_rpc_client::MtSrvCleanup_Rpc() {
  try {
    auto future = packio_client_->async_call(
        "MtSrvCleanup_jLdk", std::make_tuple(), net::use_future);
    future.get();

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

int executor_rpc_client::MtSrvPluginCfgAdd_Rpc(const PluginCfg* cfg) {
  try {
    auto future = packio_client_->async_call("MtSrvPluginCfgAdd_NfyL",
                                             std::make_tuple(::rpc_format(cfg)),
                                             net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvPluginCfgSet_Rpc(const PluginCfg* values,
                                               const int total) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgSet_SoPx", std::make_tuple(::rpc_format(values), total),
        net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvPluginCfgDelete_Rpc(LPCSTR name) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgDelete_HI9K",
        std::make_tuple(name ? std::string(name) : std::string()),
        net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvPluginCfgGet_Rpc(LPCSTR name, PluginCfg* cfg) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgGet_ainG",
        std::make_tuple(name ? std::string(name) : std::string(),
                        ::rpc_format(cfg)),
        net::use_future);
    auto rpc_result = future.get();

    auto cfg_vector_xbP2 = ::rpc_parse<PluginCfg>(rpc_result.get<1>());
    PluginCfg* cfg_ptr_BGKU = cfg_vector_xbP2.data();
    if (cfg) memcpy(cfg, cfg_ptr_BGKU, sizeof(PluginCfg));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvPluginCfgNext_Rpc(const int index,
                                                PluginCfg* cfg) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgNext_wHUa", std::make_tuple(index, ::rpc_format(cfg)),
        net::use_future);
    auto rpc_result = future.get();

    auto cfg_vector_gPFO = ::rpc_parse<PluginCfg>(rpc_result.get<1>());
    PluginCfg* cfg_ptr_f8pn = cfg_vector_gPFO.data();
    if (cfg) memcpy(cfg, cfg_ptr_f8pn, sizeof(PluginCfg));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvPluginCfgTotal_Rpc() {
  try {
    auto future = packio_client_->async_call(
        "MtSrvPluginCfgTotal_WL9I", std::make_tuple(), net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

void executor_rpc_client::MtSrvTradeRequestApply_Rpc(RequestInfo* request,
                                                     const int isdemo) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeRequestApply_CIiE",
        std::make_tuple(::rpc_format(request), isdemo), net::use_future);
    future.get();

    auto request_vector_9wXH = ::rpc_parse<RequestInfo>(rpc_result.get<0>());
    RequestInfo* request_ptr_gbkE = request_vector_9wXH.data();
    if (request) memcpy(request, request_ptr_gbkE, sizeof(RequestInfo));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

int executor_rpc_client::MtSrvTradeStopsFilter_Rpc(const ConGroup* group,
                                                   const ConSymbol* symbol,
                                                   const TradeRecord* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopsFilter_vtbN",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol),
                        ::rpc_format(trade)),
        net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvTradeStopsApply_Rpc(const UserInfo* user,
                                                  const ConGroup* group,
                                                  const ConSymbol* symbol,
                                                  TradeRecord* trade,
                                                  const int isTP) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopsApply_vYoT",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(trade), isTP),
        net::use_future);
    auto rpc_result = future.get();

    auto trade_vector_3XuB = ::rpc_parse<TradeRecord>(rpc_result.get<1>());
    TradeRecord* trade_ptr_2fVX = trade_vector_3XuB.data();
    if (trade) memcpy(trade, trade_ptr_2fVX, sizeof(TradeRecord));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvTradePendingsFilter_Rpc(
    const ConGroup* group, const ConSymbol* symbol, const TradeRecord* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradePendingsFilter_WEJR",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol),
                        ::rpc_format(trade)),
        net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvTradePendingsApply_Rpc(const UserInfo* user,
                                                     const ConGroup* group,
                                                     const ConSymbol* symbol,
                                                     const TradeRecord* pending,
                                                     TradeRecord* trade) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradePendingsApply_JGik",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(pending),
                        ::rpc_format(trade)),
        net::use_future);
    auto rpc_result = future.get();

    auto trade_vector_3J5a = ::rpc_parse<TradeRecord>(rpc_result.get<1>());
    TradeRecord* trade_ptr_TCHq = trade_vector_3J5a.data();
    if (trade) memcpy(trade, trade_ptr_TCHq, sizeof(TradeRecord));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvTradeStopoutsFilter_Rpc(const ConGroup* group,
                                                      const ConSymbol* symbol,
                                                      const int login,
                                                      const double equity,
                                                      const double margin) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopoutsFilter_8QsL",
        std::make_tuple(::rpc_format(group), ::rpc_format(symbol), login,
                        equity, margin),
        net::use_future);
    auto rpc_result = future.get();

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

int executor_rpc_client::MtSrvTradeStopoutsApply_Rpc(const UserInfo* user,
                                                     const ConGroup* group,
                                                     const ConSymbol* symbol,
                                                     TradeRecord* stopout) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeStopoutsApply_oYnw",
        std::make_tuple(::rpc_format(user), ::rpc_format(group),
                        ::rpc_format(symbol), ::rpc_format(stopout)),
        net::use_future);
    auto rpc_result = future.get();

    auto stopout_vector_yXZp = ::rpc_parse<TradeRecord>(rpc_result.get<1>());
    TradeRecord* stopout_ptr_C06B = stopout_vector_yXZp.data();
    if (stopout) memcpy(stopout, stopout_ptr_C06B, sizeof(TradeRecord));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

void executor_rpc_client::MtSrvTradesAddRequest_Rpc(TradeRecord* trade,
                                                    const RequestInfo* request,
                                                    const UserInfo* user,
                                                    const ConSymbol* symbol,
                                                    const int mode) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradesAddRequest_QSdE",
        std::make_tuple(::rpc_format(trade), ::rpc_format(request),
                        ::rpc_format(user), ::rpc_format(symbol), mode),
        net::use_future);
    future.get();

    auto trade_vector_Oi5Q = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
    TradeRecord* trade_ptr_cYe9 = trade_vector_Oi5Q.data();
    if (trade) memcpy(trade, trade_ptr_cYe9, sizeof(TradeRecord));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

int executor_rpc_client::MtSrvTradeTransaction_Rpc(TradeTransInfo* trade,
                                                   UserInfo* user,
                                                   int* request_id) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeTransaction_oHqb",
        std::make_tuple(::rpc_format(trade), ::rpc_format(user),
                        ::rpc_format(request_id)),
        net::use_future);
    auto rpc_result = future.get();

    auto trade_vector_XmBv = ::rpc_parse<TradeTransInfo>(rpc_result.get<1>());
    TradeTransInfo* trade_ptr_sFoz = trade_vector_XmBv.data();
    if (trade) memcpy(trade, trade_ptr_sFoz, sizeof(TradeTransInfo));
    auto user_vector_QN0C = ::rpc_parse<UserInfo>(rpc_result.get<2>());
    UserInfo* user_ptr_dNaE = user_vector_QN0C.data();
    if (user) memcpy(user, user_ptr_dNaE, sizeof(UserInfo));
    auto request_id_vector_ZE7R = ::rpc_parse<int>(rpc_result.get<3>());
    int* request_id_ptr_QHVf = request_id_vector_ZE7R.data();
    if (request_id) memcpy(request_id, request_id_ptr_QHVf, sizeof(int));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

void executor_rpc_client::MtSrvTradeCommission_Rpc(TradeRecord* trade,
                                                   const ConSymbol* Sec,
                                                   const ConGroup* Grp) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeCommission_XZti",
        std::make_tuple(::rpc_format(trade), ::rpc_format(Sec),
                        ::rpc_format(Grp)),
        net::use_future);
    future.get();

    auto trade_vector_90iE = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
    TradeRecord* trade_ptr_Sc4k = trade_vector_90iE.data();
    if (trade) memcpy(trade, trade_ptr_Sc4k, sizeof(TradeRecord));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}

int executor_rpc_client::MtSrvTradeCommissionAgent_Rpc(TradeRecord* trade,
                                                       const ConSymbol* sec,
                                                       const UserInfo* info) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvTradeCommissionAgent_n1gK",
        std::make_tuple(::rpc_format(trade), ::rpc_format(sec),
                        ::rpc_format(info)),
        net::use_future);
    auto rpc_result = future.get();

    auto trade_vector_uTZb = ::rpc_parse<TradeRecord>(rpc_result.get<1>());
    TradeRecord* trade_ptr_nzTO = trade_vector_uTZb.data();
    if (trade) memcpy(trade, trade_ptr_nzTO, sizeof(TradeRecord));

    return rpc_result.get<0>();
  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
    return -1;
  }
}

void executor_rpc_client::MtSrvHistoryTickApply_Rpc(const ConSymbol* symbol,
                                                    FeedTick* inf) {
  try {
    auto future = packio_client_->async_call(
        "MtSrvHistoryTickApply_tbl1",
        std::make_tuple(::rpc_format(symbol), ::rpc_format(inf)),
        net::use_future);
    future.get();

    auto inf_vector_PbCp = ::rpc_parse<FeedTick>(rpc_result.get<0>());
    FeedTick* inf_ptr_2Ys3 = inf_vector_PbCp.data();
    if (inf) memcpy(inf, inf_ptr_2Ys3, sizeof(FeedTick));

  } catch (const std::exception& e) {
    SPDLOG_CRITICAL("RPC call failed: {}", e.what());
  }
}
// server side code:

class plugin_rpc_server : public json_rpc_server {
 public:
  bool register_method() override final;
  std::function<PluginInfo*> MtSrvAbout_Z7Qm_callback_;
  std::function<> MtSrvStartup_a5XX_callback_;
  std::function<> MtSrvCleanup_jLdk_callback_;
  std::function<const PluginCfg*> MtSrvPluginCfgAdd_NfyL_callback_;
  std::function<const PluginCfg*, const int> MtSrvPluginCfgSet_SoPx_callback_;
  std::function<LPCSTR> MtSrvPluginCfgDelete_HI9K_callback_;
  std::function<LPCSTR, PluginCfg*> MtSrvPluginCfgGet_ainG_callback_;
  std::function<const int, PluginCfg*> MtSrvPluginCfgNext_wHUa_callback_;
  std::function<> MtSrvPluginCfgTotal_WL9I_callback_;
  std::function<RequestInfo*, const int> MtSrvTradeRequestApply_CIiE_callback_;
  std::function<const ConGroup*, const ConSymbol*, const TradeRecord*>
      MtSrvTradeStopsFilter_vtbN_callback_;
  std::function<const UserInfo*, const ConGroup*, const ConSymbol*,
                TradeRecord*, const int>
      MtSrvTradeStopsApply_vYoT_callback_;
  std::function<const ConGroup*, const ConSymbol*, const TradeRecord*>
      MtSrvTradePendingsFilter_WEJR_callback_;
  std::function<const UserInfo*, const ConGroup*, const ConSymbol*,
                const TradeRecord*, TradeRecord*>
      MtSrvTradePendingsApply_JGik_callback_;
  std::function<const ConGroup*, const ConSymbol*, const int, const double,
                const double>
      MtSrvTradeStopoutsFilter_8QsL_callback_;
  std::function<const UserInfo*, const ConGroup*, const ConSymbol*,
                TradeRecord*>
      MtSrvTradeStopoutsApply_oYnw_callback_;
  std::function<TradeRecord*, const RequestInfo*, const UserInfo*,
                const ConSymbol*, const int>
      MtSrvTradesAddRequest_QSdE_callback_;
  std::function<TradeTransInfo*, UserInfo*, int*>
      MtSrvTradeTransaction_oHqb_callback_;
  std::function<TradeRecord*, const ConSymbol*, const ConGroup*>
      MtSrvTradeCommission_XZti_callback_;
  std::function<TradeRecord*, const ConSymbol*, const UserInfo*>
      MtSrvTradeCommissionAgent_n1gK_callback_;
  std::function<const ConSymbol*, FeedTick*>
      MtSrvHistoryTickApply_tbl1_callback_;
};

bool plugin_rpc_server::register_method() {
  dispatcher()->add("MtSrvAbout_Z7Qm",
                    [](std::string info_format) -> std::tuple<std::string> {
                      auto info_vector_9gwJ =
                          ::rpc_parse<PluginInfo>(rpc_result.get<0>());
                      PluginInfo* info_ptr_fICf = info_vector_9gwJ.data();

                      MtSrvAbout_Z7Qm_callback_(info_ptr_fICf);

                      return std::make_tuple(::rpc_format(info_ptr_fICf));
                    });

  dispatcher()->add("MtSrvStartup_a5XX", []() -> std::tuple<int> {
    auto result = MtSrvStartup_a5XX_callback_();

    return std::make_tuple(result, );
  });

  dispatcher()->add("MtSrvCleanup_jLdk", []() -> std::tupl > {
    MtSrvCleanup_jLdk_callback_();

    return std::make_tuple();
  });

  dispatcher()->add(
      "MtSrvPluginCfgAdd_NfyL", [](std::string cfg_format) -> std::tuple<int> {
        auto cfg_vector_APN9 = ::rpc_parse<PluginCfg>(rpc_result.get<0>());
        const PluginCfg* cfg_ptr_cbgw = cfg_vector_APN9.data();

        auto result = MtSrvPluginCfgAdd_NfyL_callback_(cfg_ptr_cbgw);

        return std::make_tuple(result, );
      });

  dispatcher()->add(
      "MtSrvPluginCfgSet_SoPx",
      [](std::string values_format, const int total) -> std::tuple<int> {
        auto values_vector_SIr6 = ::rpc_parse<PluginCfg>(rpc_result.get<0>());
        const PluginCfg* values_ptr_iXhK = values_vector_SIr6.data();

        auto result = MtSrvPluginCfgSet_SoPx_callback_(values_ptr_iXhK, total);

        return std::make_tuple(result, );
      });

  dispatcher()->add("MtSrvPluginCfgDelete_HI9K",
                    [](std::string name) -> std::tuple<int> {
                      auto result = MtSrvPluginCfgDelete_HI9K_callback_(name);

                      return std::make_tuple(result, );
                    });

  dispatcher()->add(
      "MtSrvPluginCfgGet_ainG",
      [](std::string name,
         std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_xbP2 = ::rpc_parse<PluginCfg>(rpc_result.get<0>());
        PluginCfg* cfg_ptr_BGKU = cfg_vector_xbP2.data();

        auto result = MtSrvPluginCfgGet_ainG_callback_(name, cfg_ptr_BGKU);

        return std::make_tuple(result, ::rpc_format(cfg_ptr_BGKU));
      });

  dispatcher()->add(
      "MtSrvPluginCfgNext_wHUa",
      [](const int index,
         std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_gPFO = ::rpc_parse<PluginCfg>(rpc_result.get<0>());
        PluginCfg* cfg_ptr_f8pn = cfg_vector_gPFO.data();

        auto result = MtSrvPluginCfgNext_wHUa_callback_(index, cfg_ptr_f8pn);

        return std::make_tuple(result, ::rpc_format(cfg_ptr_f8pn));
      });

  dispatcher()->add("MtSrvPluginCfgTotal_WL9I", []() -> std::tuple<int> {
    auto result = MtSrvPluginCfgTotal_WL9I_callback_();

    return std::make_tuple(result, );
  });

  dispatcher()->add(
      "MtSrvTradeRequestApply_CIiE",
      [](std::string request_format,
         const int isdemo) -> std::tuple<std::string> {
        auto request_vector_9wXH =
            ::rpc_parse<RequestInfo>(rpc_result.get<0>());
        RequestInfo* request_ptr_gbkE = request_vector_9wXH.data();

        MtSrvTradeRequestApply_CIiE_callback_(request_ptr_gbkE, isdemo);

        return std::make_tuple(::rpc_format(request_ptr_gbkE));
      });

  dispatcher()->add(
      "MtSrvTradeStopsFilter_vtbN",
      [](std::string group_format, std::string symbol_format,
         std::string trade_format) -> std::tuple<int> {
        auto group_vector_OPvd = ::rpc_parse<ConGroup>(rpc_result.get<0>());
        const ConGroup* group_ptr_GYu8 = group_vector_OPvd.data();

        auto symbol_vector_54Iz = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_5ckY = symbol_vector_54Iz.data();

        auto trade_vector_ITGV = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        const TradeRecord* trade_ptr_df2C = trade_vector_ITGV.data();

        auto result = MtSrvTradeStopsFilter_vtbN_callback_(
            group_ptr_GYu8, symbol_ptr_5ckY, trade_ptr_df2C);

        return std::make_tuple(result, );
      });

  dispatcher()->add(
      "MtSrvTradeStopsApply_vYoT",
      [](std::string user_format, std::string group_format,
         std::string symbol_format, std::string trade_format,
         const int isTP) -> std::tuple<int, std::string> {
        auto user_vector_eDEf = ::rpc_parse<UserInfo>(rpc_result.get<0>());
        const UserInfo* user_ptr_tqk2 = user_vector_eDEf.data();

        auto group_vector_Kco6 = ::rpc_parse<ConGroup>(rpc_result.get<0>());
        const ConGroup* group_ptr_hE8K = group_vector_Kco6.data();

        auto symbol_vector_wiIe = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_641O = symbol_vector_wiIe.data();

        auto trade_vector_3XuB = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        TradeRecord* trade_ptr_2fVX = trade_vector_3XuB.data();

        auto result = MtSrvTradeStopsApply_vYoT_callback_(
            user_ptr_tqk2, group_ptr_hE8K, symbol_ptr_641O, trade_ptr_2fVX,
            isTP);

        return std::make_tuple(result, ::rpc_format(trade_ptr_2fVX));
      });

  dispatcher()->add(
      "MtSrvTradePendingsFilter_WEJR",
      [](std::string group_format, std::string symbol_format,
         std::string trade_format) -> std::tuple<int> {
        auto group_vector_SlY4 = ::rpc_parse<ConGroup>(rpc_result.get<0>());
        const ConGroup* group_ptr_FXxX = group_vector_SlY4.data();

        auto symbol_vector_Xz8w = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_DvoS = symbol_vector_Xz8w.data();

        auto trade_vector_BHHx = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        const TradeRecord* trade_ptr_XWOS = trade_vector_BHHx.data();

        auto result = MtSrvTradePendingsFilter_WEJR_callback_(
            group_ptr_FXxX, symbol_ptr_DvoS, trade_ptr_XWOS);

        return std::make_tuple(result, );
      });

  dispatcher()->add(
      "MtSrvTradePendingsApply_JGik",
      [](std::string user_format, std::string group_format,
         std::string symbol_format, std::string pending_format,
         std::string trade_format) -> std::tuple<int, std::string> {
        auto user_vector_cENZ = ::rpc_parse<UserInfo>(rpc_result.get<0>());
        const UserInfo* user_ptr_REKQ = user_vector_cENZ.data();

        auto group_vector_1yKb = ::rpc_parse<ConGroup>(rpc_result.get<0>());
        const ConGroup* group_ptr_Eobv = group_vector_1yKb.data();

        auto symbol_vector_pPx7 = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_Ptn7 = symbol_vector_pPx7.data();

        auto pending_vector_OPk5 =
            ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        const TradeRecord* pending_ptr_9j8r = pending_vector_OPk5.data();

        auto trade_vector_3J5a = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        TradeRecord* trade_ptr_TCHq = trade_vector_3J5a.data();

        auto result = MtSrvTradePendingsApply_JGik_callback_(
            user_ptr_REKQ, group_ptr_Eobv, symbol_ptr_Ptn7, pending_ptr_9j8r,
            trade_ptr_TCHq);

        return std::make_tuple(result, ::rpc_format(trade_ptr_TCHq));
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsFilter_8QsL",
      [](std::string group_format, std::string symbol_format, const int login,
         const double equity, const double margin) -> std::tuple<int> {
        auto group_vector_qjx5 = ::rpc_parse<ConGroup>(rpc_result.get<0>());
        const ConGroup* group_ptr_IYPI = group_vector_qjx5.data();

        auto symbol_vector_oD4B = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_5SSw = symbol_vector_oD4B.data();

        auto result = MtSrvTradeStopoutsFilter_8QsL_callback_(
            group_ptr_IYPI, symbol_ptr_5SSw, login, equity, margin);

        return std::make_tuple(result, );
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsApply_oYnw",
      [](std::string user_format, std::string group_format,
         std::string symbol_format,
         std::string stopout_format) -> std::tuple<int, std::string> {
        auto user_vector_H66Q = ::rpc_parse<UserInfo>(rpc_result.get<0>());
        const UserInfo* user_ptr_gw5W = user_vector_H66Q.data();

        auto group_vector_KMto = ::rpc_parse<ConGroup>(rpc_result.get<0>());
        const ConGroup* group_ptr_pjZb = group_vector_KMto.data();

        auto symbol_vector_ZkIs = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_ugrv = symbol_vector_ZkIs.data();

        auto stopout_vector_yXZp =
            ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        TradeRecord* stopout_ptr_C06B = stopout_vector_yXZp.data();

        auto result = MtSrvTradeStopoutsApply_oYnw_callback_(
            user_ptr_gw5W, group_ptr_pjZb, symbol_ptr_ugrv, stopout_ptr_C06B);

        return std::make_tuple(result, ::rpc_format(stopout_ptr_C06B));
      });

  dispatcher()->add(
      "MtSrvTradesAddRequest_QSdE",
      [](std::string trade_format, std::string request_format,
         std::string user_format, std::string symbol_format,
         const int mode) -> std::tuple<std::string> {
        auto trade_vector_Oi5Q = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        TradeRecord* trade_ptr_cYe9 = trade_vector_Oi5Q.data();

        auto request_vector_tRJs =
            ::rpc_parse<RequestInfo>(rpc_result.get<1>());
        const RequestInfo* request_ptr_awOw = request_vector_tRJs.data();

        auto user_vector_fxJv = ::rpc_parse<UserInfo>(rpc_result.get<1>());
        const UserInfo* user_ptr_FWCP = user_vector_fxJv.data();

        auto symbol_vector_y2Hb = ::rpc_parse<ConSymbol>(rpc_result.get<1>());
        const ConSymbol* symbol_ptr_kY1C = symbol_vector_y2Hb.data();

        MtSrvTradesAddRequest_QSdE_callback_(trade_ptr_cYe9, request_ptr_awOw,
                                             user_ptr_FWCP, symbol_ptr_kY1C,
                                             mode);

        return std::make_tuple(::rpc_format(trade_ptr_cYe9));
      });

  dispatcher()->add(
      "MtSrvTradeTransaction_oHqb",
      [](std::string trade_format, std::string user_format,
         std::string request_id_format)
          -> std::tuple<int, std::string, std::string, std::string> {
        auto trade_vector_XmBv =
            ::rpc_parse<TradeTransInfo>(rpc_result.get<0>());
        TradeTransInfo* trade_ptr_sFoz = trade_vector_XmBv.data();

        auto user_vector_QN0C = ::rpc_parse<UserInfo>(rpc_result.get<1>());
        UserInfo* user_ptr_dNaE = user_vector_QN0C.data();

        auto request_id_vector_ZE7R = ::rpc_parse<int>(rpc_result.get<2>());
        int* request_id_ptr_QHVf = request_id_vector_ZE7R.data();

        auto result = MtSrvTradeTransaction_oHqb_callback_(
            trade_ptr_sFoz, user_ptr_dNaE, request_id_ptr_QHVf);

        return std::make_tuple(result, ::rpc_format(trade_ptr_sFoz),
                               ::rpc_format(user_ptr_dNaE),
                               ::rpc_format(request_id_ptr_QHVf));
      });

  dispatcher()->add(
      "MtSrvTradeCommission_XZti",
      [](std::string trade_format, std::string Sec_format,
         std::string Grp_format) -> std::tuple<std::string> {
        auto trade_vector_90iE = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        TradeRecord* trade_ptr_Sc4k = trade_vector_90iE.data();

        auto Sec_vector_ge17 = ::rpc_parse<ConSymbol>(rpc_result.get<1>());
        const ConSymbol* Sec_ptr_48qf = Sec_vector_ge17.data();

        auto Grp_vector_pDNR = ::rpc_parse<ConGroup>(rpc_result.get<1>());
        const ConGroup* Grp_ptr_PbVw = Grp_vector_pDNR.data();

        MtSrvTradeCommission_XZti_callback_(trade_ptr_Sc4k, Sec_ptr_48qf,
                                            Grp_ptr_PbVw);

        return std::make_tuple(::rpc_format(trade_ptr_Sc4k));
      });

  dispatcher()->add(
      "MtSrvTradeCommissionAgent_n1gK",
      [](std::string trade_format, std::string sec_format,
         std::string info_format) -> std::tuple<int, std::string> {
        auto trade_vector_uTZb = ::rpc_parse<TradeRecord>(rpc_result.get<0>());
        TradeRecord* trade_ptr_nzTO = trade_vector_uTZb.data();

        auto sec_vector_kgP4 = ::rpc_parse<ConSymbol>(rpc_result.get<1>());
        const ConSymbol* sec_ptr_niVv = sec_vector_kgP4.data();

        auto info_vector_TDcS = ::rpc_parse<UserInfo>(rpc_result.get<1>());
        const UserInfo* info_ptr_Gshg = info_vector_TDcS.data();

        auto result = MtSrvTradeCommissionAgent_n1gK_callback_(
            trade_ptr_nzTO, sec_ptr_niVv, info_ptr_Gshg);

        return std::make_tuple(result, ::rpc_format(trade_ptr_nzTO));
      });

  dispatcher()->add(
      "MtSrvHistoryTickApply_tbl1",
      [](std::string symbol_format,
         std::string inf_format) -> std::tuple<std::string> {
        auto symbol_vector_89e3 = ::rpc_parse<ConSymbol>(rpc_result.get<0>());
        const ConSymbol* symbol_ptr_QvPe = symbol_vector_89e3.data();

        auto inf_vector_PbCp = ::rpc_parse<FeedTick>(rpc_result.get<0>());
        FeedTick* inf_ptr_2Ys3 = inf_vector_PbCp.data();

        MtSrvHistoryTickApply_tbl1_callback_(symbol_ptr_QvPe, inf_ptr_2Ys3);

        return std::make_tuple(::rpc_format(inf_ptr_2Ys3));
      });
  return true;
}
// test code:
TEST_F(RpcTestFixture, MtSrvAbout_Z7Qm) {
  // input parameters
  PluginInfo info_input = random_value<PluginInfo>();

  // output parameters
  PluginInfo info_output = random_value<PluginInfo>();

  // diy callback
  server->MtSrvAbout_Z7Qm_callback_ = [&](PluginInfo* info) {
    // check input
    EXPECT_TRUE(memcmp(&info_input, info), 0);

    // assign output
    memcpy(info, &info_output);

    // return value
  };

  // call the RPC method
  client->MtSrvAbout_Rpc(&info_input);

  // check the result
  EXPECT_TRUE(memcmp(&info_output, &info_input), 0);
}

TEST_F(RpcTestFixture, MtSrvStartup_a5XX) {
  // input parameters

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvStartup_a5XX_callback_ = [&]() {
    // check input

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvStartup_Rpc();

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvCleanup_jLdk) {
  // input parameters

  // output parameters

  // diy callback
  server->MtSrvCleanup_jLdk_callback_ = [&]() {
    // check input

    // assign output

    // return value
  };

  // call the RPC method
  client->MtSrvCleanup_Rpc();

  // check the result
}

TEST_F(RpcTestFixture, MtSrvPluginCfgAdd_NfyL) {
  // input parameters
  PluginCfg cfg_input = random_value<PluginCfg>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgAdd_NfyL_callback_ = [&](const PluginCfg* cfg) {
    // check input
    EXPECT_TRUE(memcmp(&cfg_input, cfg), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgAdd_Rpc(&cfg_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgSet_SoPx) {
  // input parameters
  PluginCfg values_input = random_value<PluginCfg>();
  const int total_input = random_value<int>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgSet_SoPx_callback_ = [&](const PluginCfg* values,
                                                 const int total) {
    // check input
    EXPECT_TRUE(memcmp(&values_input, values), 0);
    EXPECT_TRUE(memcmp(&total_input, &total), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgSet_Rpc(&values_input, total_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgDelete_HI9K) {
  // input parameters
  LPCSTR name_input = "abcdefg";

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgDelete_HI9K_callback_ = [&](LPCSTR name) {
    // check input
    EXPECT_TRUE(memcmp(&name_input, &name), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgDelete_Rpc(name_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgGet_ainG) {
  // input parameters
  LPCSTR name_input = "abcdefg";
  PluginCfg cfg_input = random_value<PluginCfg>();

  // output parameters
  PluginCfg cfg_output = random_value<PluginCfg>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgGet_ainG_callback_ = [&](LPCSTR name, PluginCfg* cfg) {
    // check input
    EXPECT_TRUE(memcmp(&name_input, &name), 0);
    EXPECT_TRUE(memcmp(&cfg_input, cfg), 0);

    // assign output
    memcpy(cfg, &cfg_output);

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgGet_Rpc(name_input, &cfg_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&cfg_output, &cfg_input), 0);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgNext_wHUa) {
  // input parameters
  const int index_input = random_value<int>();
  PluginCfg cfg_input = random_value<PluginCfg>();

  // output parameters
  PluginCfg cfg_output = random_value<PluginCfg>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgNext_wHUa_callback_ = [&](const int index,
                                                  PluginCfg* cfg) {
    // check input
    EXPECT_TRUE(memcmp(&index_input, &index), 0);
    EXPECT_TRUE(memcmp(&cfg_input, cfg), 0);

    // assign output
    memcpy(cfg, &cfg_output);

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgNext_Rpc(index_input, &cfg_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&cfg_output, &cfg_input), 0);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgTotal_WL9I) {
  // input parameters

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgTotal_WL9I_callback_ = [&]() {
    // check input

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgTotal_Rpc();

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvTradeRequestApply_CIiE) {
  // input parameters
  RequestInfo request_input = random_value<RequestInfo>();
  const int isdemo_input = random_value<int>();

  // output parameters
  RequestInfo request_output = random_value<RequestInfo>();

  // diy callback
  server->MtSrvTradeRequestApply_CIiE_callback_ = [&](RequestInfo* request,
                                                      const int isdemo) {
    // check input
    EXPECT_TRUE(memcmp(&request_input, request), 0);
    EXPECT_TRUE(memcmp(&isdemo_input, &isdemo), 0);

    // assign output
    memcpy(request, &request_output);

    // return value
  };

  // call the RPC method
  client->MtSrvTradeRequestApply_Rpc(&request_input, isdemo_input);

  // check the result
  EXPECT_TRUE(memcmp(&request_output, &request_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeStopsFilter_vtbN) {
  // input parameters
  ConGroup group_input = random_value<ConGroup>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  TradeRecord trade_input = random_value<TradeRecord>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopsFilter_vtbN_callback_ = [&](const ConGroup* group,
                                                     const ConSymbol* symbol,
                                                     const TradeRecord* trade) {
    // check input
    EXPECT_TRUE(memcmp(&group_input, group), 0);
    EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
    EXPECT_TRUE(memcmp(&trade_input, trade), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeStopsFilter_Rpc(
      &group_input, &symbol_input, &trade_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvTradeStopsApply_vYoT) {
  // input parameters
  UserInfo user_input = random_value<UserInfo>();
  ConGroup group_input = random_value<ConGroup>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  TradeRecord trade_input = random_value<TradeRecord>();
  const int isTP_input = random_value<int>();

  // output parameters
  TradeRecord trade_output = random_value<TradeRecord>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopsApply_vYoT_callback_ =
      [&](const UserInfo* user, const ConGroup* group, const ConSymbol* symbol,
          TradeRecord* trade, const int isTP) {
        // check input
        EXPECT_TRUE(memcmp(&user_input, user), 0);
        EXPECT_TRUE(memcmp(&group_input, group), 0);
        EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);
        EXPECT_TRUE(memcmp(&isTP_input, &isTP), 0);

        // assign output
        memcpy(trade, &trade_output);

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeStopsApply_Rpc(
      &user_input, &group_input, &symbol_input, &trade_input, isTP_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&trade_output, &trade_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradePendingsFilter_WEJR) {
  // input parameters
  ConGroup group_input = random_value<ConGroup>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  TradeRecord trade_input = random_value<TradeRecord>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradePendingsFilter_WEJR_callback_ =
      [&](const ConGroup* group, const ConSymbol* symbol,
          const TradeRecord* trade) {
        // check input
        EXPECT_TRUE(memcmp(&group_input, group), 0);
        EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);

        // assign output

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradePendingsFilter_Rpc(
      &group_input, &symbol_input, &trade_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvTradePendingsApply_JGik) {
  // input parameters
  UserInfo user_input = random_value<UserInfo>();
  ConGroup group_input = random_value<ConGroup>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  TradeRecord pending_input = random_value<TradeRecord>();
  TradeRecord trade_input = random_value<TradeRecord>();

  // output parameters
  TradeRecord trade_output = random_value<TradeRecord>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradePendingsApply_JGik_callback_ =
      [&](const UserInfo* user, const ConGroup* group, const ConSymbol* symbol,
          const TradeRecord* pending, TradeRecord* trade) {
        // check input
        EXPECT_TRUE(memcmp(&user_input, user), 0);
        EXPECT_TRUE(memcmp(&group_input, group), 0);
        EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
        EXPECT_TRUE(memcmp(&pending_input, pending), 0);
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);

        // assign output
        memcpy(trade, &trade_output);

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradePendingsApply_Rpc(
      &user_input, &group_input, &symbol_input, &pending_input, &trade_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&trade_output, &trade_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeStopoutsFilter_8QsL) {
  // input parameters
  ConGroup group_input = random_value<ConGroup>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  const int login_input = random_value<int>();
  const double equity_input = random_value<double>();
  const double margin_input = random_value<double>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopoutsFilter_8QsL_callback_ =
      [&](const ConGroup* group, const ConSymbol* symbol, const int login,
          const double equity, const double margin) {
        // check input
        EXPECT_TRUE(memcmp(&group_input, group), 0);
        EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
        EXPECT_TRUE(memcmp(&login_input, &login), 0);
        EXPECT_TRUE(memcmp(&equity_input, &equity), 0);
        EXPECT_TRUE(memcmp(&margin_input, &margin), 0);

        // assign output

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeStopoutsFilter_Rpc(
      &group_input, &symbol_input, login_input, equity_input, margin_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvTradeStopoutsApply_oYnw) {
  // input parameters
  UserInfo user_input = random_value<UserInfo>();
  ConGroup group_input = random_value<ConGroup>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  TradeRecord stopout_input = random_value<TradeRecord>();

  // output parameters
  TradeRecord stopout_output = random_value<TradeRecord>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopoutsApply_oYnw_callback_ =
      [&](const UserInfo* user, const ConGroup* group, const ConSymbol* symbol,
          TradeRecord* stopout) {
        // check input
        EXPECT_TRUE(memcmp(&user_input, user), 0);
        EXPECT_TRUE(memcmp(&group_input, group), 0);
        EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
        EXPECT_TRUE(memcmp(&stopout_input, stopout), 0);

        // assign output
        memcpy(stopout, &stopout_output);

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeStopoutsApply_Rpc(
      &user_input, &group_input, &symbol_input, &stopout_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&stopout_output, &stopout_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradesAddRequest_QSdE) {
  // input parameters
  TradeRecord trade_input = random_value<TradeRecord>();
  RequestInfo request_input = random_value<RequestInfo>();
  UserInfo user_input = random_value<UserInfo>();
  ConSymbol symbol_input = random_value<ConSymbol>();
  const int mode_input = random_value<int>();

  // output parameters
  TradeRecord trade_output = random_value<TradeRecord>();

  // diy callback
  server->MtSrvTradesAddRequest_QSdE_callback_ =
      [&](TradeRecord* trade, const RequestInfo* request, const UserInfo* user,
          const ConSymbol* symbol, const int mode) {
        // check input
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);
        EXPECT_TRUE(memcmp(&request_input, request), 0);
        EXPECT_TRUE(memcmp(&user_input, user), 0);
        EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
        EXPECT_TRUE(memcmp(&mode_input, &mode), 0);

        // assign output
        memcpy(trade, &trade_output);

        // return value
      };

  // call the RPC method
  client->MtSrvTradesAddRequest_Rpc(&trade_input, &request_input, &user_input,
                                    &symbol_input, mode_input);

  // check the result
  EXPECT_TRUE(memcmp(&trade_output, &trade_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeTransaction_oHqb) {
  // input parameters
  TradeTransInfo trade_input = random_value<TradeTransInfo>();
  UserInfo user_input = random_value<UserInfo>();
  int request_id_input = random_value<int>();

  // output parameters
  TradeTransInfo trade_output = random_value<TradeTransInfo>();
  UserInfo user_output = random_value<UserInfo>();
  int request_id_output = random_value<int>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeTransaction_oHqb_callback_ =
      [&](TradeTransInfo* trade, UserInfo* user, int* request_id) {
        // check input
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);
        EXPECT_TRUE(memcmp(&user_input, user), 0);
        EXPECT_TRUE(memcmp(&request_id_input, request_id), 0);

        // assign output
        memcpy(trade, &trade_output);
        memcpy(user, &user_output);
        memcpy(request_id, &request_id_output);

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeTransaction_Rpc(&trade_input, &user_input,
                                                      &request_id_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&trade_output, &trade_input), 0);
  EXPECT_TRUE(memcmp(&user_output, &user_input), 0);
  EXPECT_TRUE(memcmp(&request_id_output, &request_id_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeCommission_XZti) {
  // input parameters
  TradeRecord trade_input = random_value<TradeRecord>();
  ConSymbol Sec_input = random_value<ConSymbol>();
  ConGroup Grp_input = random_value<ConGroup>();

  // output parameters
  TradeRecord trade_output = random_value<TradeRecord>();

  // diy callback
  server->MtSrvTradeCommission_XZti_callback_ =
      [&](TradeRecord* trade, const ConSymbol* Sec, const ConGroup* Grp) {
        // check input
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);
        EXPECT_TRUE(memcmp(&Sec_input, Sec), 0);
        EXPECT_TRUE(memcmp(&Grp_input, Grp), 0);

        // assign output
        memcpy(trade, &trade_output);

        // return value
      };

  // call the RPC method
  client->MtSrvTradeCommission_Rpc(&trade_input, &Sec_input, &Grp_input);

  // check the result
  EXPECT_TRUE(memcmp(&trade_output, &trade_input), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeCommissionAgent_n1gK) {
  // input parameters
  TradeRecord trade_input = random_value<TradeRecord>();
  ConSymbol sec_input = random_value<ConSymbol>();
  UserInfo info_input = random_value<UserInfo>();

  // output parameters
  TradeRecord trade_output = random_value<TradeRecord>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeCommissionAgent_n1gK_callback_ =
      [&](TradeRecord* trade, const ConSymbol* sec, const UserInfo* info) {
        // check input
        EXPECT_TRUE(memcmp(&trade_input, trade), 0);
        EXPECT_TRUE(memcmp(&sec_input, sec), 0);
        EXPECT_TRUE(memcmp(&info_input, info), 0);

        // assign output
        memcpy(trade, &trade_output);

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeCommissionAgent_Rpc(
      &trade_input, &sec_input, &info_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_TRUE(memcmp(&trade_output, &trade_input), 0);
}

TEST_F(RpcTestFixture, MtSrvHistoryTickApply_tbl1) {
  // input parameters
  ConSymbol symbol_input = random_value<ConSymbol>();
  FeedTick inf_input = random_value<FeedTick>();

  // output parameters
  FeedTick inf_output = random_value<FeedTick>();

  // diy callback
  server->MtSrvHistoryTickApply_tbl1_callback_ = [&](const ConSymbol* symbol,
                                                     FeedTick* inf) {
    // check input
    EXPECT_TRUE(memcmp(&symbol_input, symbol), 0);
    EXPECT_TRUE(memcmp(&inf_input, inf), 0);

    // assign output
    memcpy(inf, &inf_output);

    // return value
  };

  // call the RPC method
  client->MtSrvHistoryTickApply_Rpc(&symbol_input, &inf_input);

  // check the result
  EXPECT_TRUE(memcmp(&inf_output, &inf_input), 0);
}
