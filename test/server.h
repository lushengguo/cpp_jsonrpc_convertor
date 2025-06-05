
#pragma once
#include "client.h"
#include "define.h"
#include "functional"
#include "jsonrpc.h"
#include "server.h"

class plugin_rpc_server : public json_rpc_server {
 public:
  bool register_method() override final;
  std::function<void(testA*)> MtSrvAbout_G7DX_callback_;
  std::function<int()> MtSrvStartup_E0gE_callback_;
  std::function<void()> MtSrvCleanup_PKHr_callback_;
  std::function<int(const testA*)> MtSrvPluginCfgAdd_CbA0_callback_;
  std::function<int(const testA*, const int)> MtSrvPluginCfgSet_tifQ_callback_;
  std::function<int(LPCSTR)> MtSrvPluginCfgDelete_vkKH_callback_;
  std::function<int(LPCSTR, testA*)> MtSrvPluginCfgGet_WMtN_callback_;
  std::function<int(const int, testA*)> MtSrvPluginCfgNext_9LGj_callback_;
  std::function<int()> MtSrvPluginCfgTotal_cffM_callback_;
  std::function<void(testA*, const int)> MtSrvTradeRequestApply_yL5z_callback_;
  std::function<int(const testA*, const testA*, const testA*)>
      MtSrvTradeStopsFilter_l8h6_callback_;
  std::function<int(const testA*, const testA*, const testA*, testA*,
                    const int)>
      MtSrvTradeStopsApply_oFkn_callback_;
  std::function<int(const testA*, const testA*, const testA*)>
      MtSrvTradePendingsFilter_0RQG_callback_;
  std::function<int(const testA*, const testA*, const testA*, const testA*,
                    testA*)>
      MtSrvTradePendingsApply_p9q6_callback_;
  std::function<int(const testA*, const testA*, const int, const double,
                    const double)>
      MtSrvTradeStopoutsFilter_zpw6_callback_;
  std::function<int(const testA*, const testA*, const testA*, testA*)>
      MtSrvTradeStopoutsApply_7mFc_callback_;
  std::function<void(testA*, const testA*, const testA*, const testA*,
                     const int)>
      MtSrvTradesAddRequest_RkK3_callback_;
  std::function<int(testA*, testA*, testA*)>
      MtSrvTradeTransaction_c7kx_callback_;
  std::function<void(testA*, const testA*, const testA*)>
      MtSrvTradeCommission_MeFx_callback_;
  std::function<int(testA*, const testA*, const testA*)>
      MtSrvTradeCommissionAgent_YGkX_callback_;
  std::function<void(const testA*, testA*)>
      MtSrvHistoryTickApply_IbhS_callback_;
};

inline bool plugin_rpc_server::register_method() {
  dispatcher()->add("MtSrvAbout_G7DX",
                    [this](std::string info_format) -> std::tuple<std::string> {
                      auto info_vector_OVQQ = ::rpc_parse<testA>(info_format);
                      testA* info_ptr_reqA = info_vector_OVQQ.data();

                      MtSrvAbout_G7DX_callback_(info_ptr_reqA);
                      return std::make_tuple(::rpc_format(info_ptr_reqA));
                    });

  dispatcher()->add("MtSrvStartup_E0gE", [this]() -> std::tuple<int> {
    auto result = MtSrvStartup_E0gE_callback_();
    return std::make_tuple(result);
  });

  dispatcher()->add("MtSrvCleanup_PKHr",
                    [this]() -> { MtSrvCleanup_PKHr_callback_(); });

  dispatcher()->add("MtSrvPluginCfgAdd_CbA0",
                    [this](std::string cfg_format) -> std::tuple<int> {
                      auto cfg_vector_4IB0 = ::rpc_parse<testA>(cfg_format);
                      const testA* cfg_ptr_19Am = cfg_vector_4IB0.data();

                      auto result =
                          MtSrvPluginCfgAdd_CbA0_callback_(cfg_ptr_19Am);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvPluginCfgSet_tifQ",
      [this](std::string values_format, const int total) -> std::tuple<int> {
        auto values_vector_0kFR = ::rpc_parse<testA>(values_format);
        const testA* values_ptr_s10V = values_vector_0kFR.data();

        auto result = MtSrvPluginCfgSet_tifQ_callback_(values_ptr_s10V, total);
        return std::make_tuple(result);
      });

  dispatcher()->add("MtSrvPluginCfgDelete_vkKH",
                    [this](std::string name) -> std::tuple<int> {
                      auto result = MtSrvPluginCfgDelete_vkKH_callback_(name);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvPluginCfgGet_WMtN",
      [this](std::string name,
             std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_3jXw = ::rpc_parse<testA>(cfg_format);
        testA* cfg_ptr_DxgR = cfg_vector_3jXw.data();

        auto result = MtSrvPluginCfgGet_WMtN_callback_(name, cfg_ptr_DxgR);
        return std::make_tuple(result, ::rpc_format(cfg_ptr_DxgR));
      });

  dispatcher()->add(
      "MtSrvPluginCfgNext_9LGj",
      [this](const int index,
             std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_Sc1A = ::rpc_parse<testA>(cfg_format);
        testA* cfg_ptr_dTeS = cfg_vector_Sc1A.data();

        auto result = MtSrvPluginCfgNext_9LGj_callback_(index, cfg_ptr_dTeS);
        return std::make_tuple(result, ::rpc_format(cfg_ptr_dTeS));
      });

  dispatcher()->add("MtSrvPluginCfgTotal_cffM", [this]() -> std::tuple<int> {
    auto result = MtSrvPluginCfgTotal_cffM_callback_();
    return std::make_tuple(result);
  });

  dispatcher()->add(
      "MtSrvTradeRequestApply_yL5z",
      [this](std::string request_format,
             const int isdemo) -> std::tuple<std::string> {
        auto request_vector_Lo7X = ::rpc_parse<testA>(request_format);
        testA* request_ptr_qu1X = request_vector_Lo7X.data();

        MtSrvTradeRequestApply_yL5z_callback_(request_ptr_qu1X, isdemo);
        return std::make_tuple(::rpc_format(request_ptr_qu1X));
      });

  dispatcher()->add("MtSrvTradeStopsFilter_l8h6",
                    [this](std::string group_format, std::string symbol_format,
                           std::string trade_format) -> std::tuple<int> {
                      auto group_vector_ZTox = ::rpc_parse<testA>(group_format);
                      const testA* group_ptr_xbE9 = group_vector_ZTox.data();

                      auto symbol_vector_MFhe =
                          ::rpc_parse<testA>(symbol_format);
                      const testA* symbol_ptr_hwOJ = symbol_vector_MFhe.data();

                      auto trade_vector_5MjO = ::rpc_parse<testA>(trade_format);
                      const testA* trade_ptr_J05f = trade_vector_5MjO.data();

                      auto result = MtSrvTradeStopsFilter_l8h6_callback_(
                          group_ptr_xbE9, symbol_ptr_hwOJ, trade_ptr_J05f);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvTradeStopsApply_oFkn",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format, std::string trade_format,
             const int isTP) -> std::tuple<int, std::string> {
        auto user_vector_pGvK = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_rigL = user_vector_pGvK.data();

        auto group_vector_H6pu = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_k8PP = group_vector_H6pu.data();

        auto symbol_vector_nQyu = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_vAzo = symbol_vector_nQyu.data();

        auto trade_vector_tW24 = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_tPdx = trade_vector_tW24.data();

        auto result = MtSrvTradeStopsApply_oFkn_callback_(
            user_ptr_rigL, group_ptr_k8PP, symbol_ptr_vAzo, trade_ptr_tPdx,
            isTP);
        return std::make_tuple(result, ::rpc_format(trade_ptr_tPdx));
      });

  dispatcher()->add("MtSrvTradePendingsFilter_0RQG",
                    [this](std::string group_format, std::string symbol_format,
                           std::string trade_format) -> std::tuple<int> {
                      auto group_vector_O2cs = ::rpc_parse<testA>(group_format);
                      const testA* group_ptr_KPXb = group_vector_O2cs.data();

                      auto symbol_vector_ss5C =
                          ::rpc_parse<testA>(symbol_format);
                      const testA* symbol_ptr_eZ8F = symbol_vector_ss5C.data();

                      auto trade_vector_hhFW = ::rpc_parse<testA>(trade_format);
                      const testA* trade_ptr_Qayt = trade_vector_hhFW.data();

                      auto result = MtSrvTradePendingsFilter_0RQG_callback_(
                          group_ptr_KPXb, symbol_ptr_eZ8F, trade_ptr_Qayt);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvTradePendingsApply_p9q6",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format, std::string pending_format,
             std::string trade_format) -> std::tuple<int, std::string> {
        auto user_vector_N05P = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_tKNx = user_vector_N05P.data();

        auto group_vector_eyNL = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_Qb3C = group_vector_eyNL.data();

        auto symbol_vector_rHwk = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_x7t2 = symbol_vector_rHwk.data();

        auto pending_vector_jOxB = ::rpc_parse<testA>(pending_format);
        const testA* pending_ptr_UM53 = pending_vector_jOxB.data();

        auto trade_vector_v9pm = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_3Hc2 = trade_vector_v9pm.data();

        auto result = MtSrvTradePendingsApply_p9q6_callback_(
            user_ptr_tKNx, group_ptr_Qb3C, symbol_ptr_x7t2, pending_ptr_UM53,
            trade_ptr_3Hc2);
        return std::make_tuple(result, ::rpc_format(trade_ptr_3Hc2));
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsFilter_zpw6",
      [this](std::string group_format, std::string symbol_format,
             const int login, const double equity,
             const double margin) -> std::tuple<int> {
        auto group_vector_9DNZ = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_BV0q = group_vector_9DNZ.data();

        auto symbol_vector_RqW7 = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_doH4 = symbol_vector_RqW7.data();

        auto result = MtSrvTradeStopoutsFilter_zpw6_callback_(
            group_ptr_BV0q, symbol_ptr_doH4, login, equity, margin);
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsApply_7mFc",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format,
             std::string stopout_format) -> std::tuple<int, std::string> {
        auto user_vector_ypgL = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_GeDK = user_vector_ypgL.data();

        auto group_vector_WWWz = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_9RUL = group_vector_WWWz.data();

        auto symbol_vector_HpnD = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_zpPY = symbol_vector_HpnD.data();

        auto stopout_vector_dwlL = ::rpc_parse<testA>(stopout_format);
        testA* stopout_ptr_5cpw = stopout_vector_dwlL.data();

        auto result = MtSrvTradeStopoutsApply_7mFc_callback_(
            user_ptr_GeDK, group_ptr_9RUL, symbol_ptr_zpPY, stopout_ptr_5cpw);
        return std::make_tuple(result, ::rpc_format(stopout_ptr_5cpw));
      });

  dispatcher()->add(
      "MtSrvTradesAddRequest_RkK3",
      [this](std::string trade_format, std::string request_format,
             std::string user_format, std::string symbol_format,
             const int mode) -> std::tuple<std::string> {
        auto trade_vector_cqA1 = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_ZU2b = trade_vector_cqA1.data();

        auto request_vector_dOum = ::rpc_parse<testA>(request_format);
        const testA* request_ptr_kDMz = request_vector_dOum.data();

        auto user_vector_QEqZ = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_JndB = user_vector_QEqZ.data();

        auto symbol_vector_iS0j = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_L1I6 = symbol_vector_iS0j.data();

        MtSrvTradesAddRequest_RkK3_callback_(trade_ptr_ZU2b, request_ptr_kDMz,
                                             user_ptr_JndB, symbol_ptr_L1I6,
                                             mode);
        return std::make_tuple(::rpc_format(trade_ptr_ZU2b));
      });

  dispatcher()->add(
      "MtSrvTradeTransaction_c7kx",
      [this](std::string trade_format, std::string user_format,
             std::string request_id_format)
          -> std::tuple<int, std::string, std::string, std::string> {
        auto trade_vector_Kq2m = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_QSHl = trade_vector_Kq2m.data();

        auto user_vector_aJqW = ::rpc_parse<testA>(user_format);
        testA* user_ptr_zL87 = user_vector_aJqW.data();

        auto request_id_vector_RCLH = ::rpc_parse<testA>(request_id_format);
        testA* request_id_ptr_EfnR = request_id_vector_RCLH.data();

        auto result = MtSrvTradeTransaction_c7kx_callback_(
            trade_ptr_QSHl, user_ptr_zL87, request_id_ptr_EfnR);
        return std::make_tuple(result, ::rpc_format(trade_ptr_QSHl),
                               ::rpc_format(user_ptr_zL87),
                               ::rpc_format(request_id_ptr_EfnR));
      });

  dispatcher()->add("MtSrvTradeCommission_MeFx",
                    [this](std::string trade_format, std::string Sec_format,
                           std::string Grp_format) -> std::tuple<std::string> {
                      auto trade_vector_fpfW = ::rpc_parse<testA>(trade_format);
                      testA* trade_ptr_9Qxc = trade_vector_fpfW.data();

                      auto Sec_vector_HOht = ::rpc_parse<testA>(Sec_format);
                      const testA* Sec_ptr_bkPr = Sec_vector_HOht.data();

                      auto Grp_vector_SqE5 = ::rpc_parse<testA>(Grp_format);
                      const testA* Grp_ptr_qpx0 = Grp_vector_SqE5.data();

                      MtSrvTradeCommission_MeFx_callback_(
                          trade_ptr_9Qxc, Sec_ptr_bkPr, Grp_ptr_qpx0);
                      return std::make_tuple(::rpc_format(trade_ptr_9Qxc));
                    });

  dispatcher()->add(
      "MtSrvTradeCommissionAgent_YGkX",
      [this](std::string trade_format, std::string sec_format,
             std::string info_format) -> std::tuple<int, std::string> {
        auto trade_vector_qENz = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_zX8a = trade_vector_qENz.data();

        auto sec_vector_f6ws = ::rpc_parse<testA>(sec_format);
        const testA* sec_ptr_nJQw = sec_vector_f6ws.data();

        auto info_vector_RcfC = ::rpc_parse<testA>(info_format);
        const testA* info_ptr_16DH = info_vector_RcfC.data();

        auto result = MtSrvTradeCommissionAgent_YGkX_callback_(
            trade_ptr_zX8a, sec_ptr_nJQw, info_ptr_16DH);
        return std::make_tuple(result, ::rpc_format(trade_ptr_zX8a));
      });

  dispatcher()->add(
      "MtSrvHistoryTickApply_IbhS",
      [this](std::string symbol_format,
             std::string inf_format) -> std::tuple<std::string> {
        auto symbol_vector_pGEC = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_YnvA = symbol_vector_pGEC.data();

        auto inf_vector_UR8F = ::rpc_parse<testA>(inf_format);
        testA* inf_ptr_BOjZ = inf_vector_UR8F.data();

        MtSrvHistoryTickApply_IbhS_callback_(symbol_ptr_YnvA, inf_ptr_BOjZ);
        return std::make_tuple(::rpc_format(inf_ptr_BOjZ));
      });
  return true;
}
