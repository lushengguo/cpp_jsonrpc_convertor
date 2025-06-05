
#pragma once
#include <functional>

#include "client.h"
#include "define.h"
#include "interface.h"
#include "jsonrpc.h"
#include "server.h"

class plugin_rpc_server : public json_rpc_server {
 public:
  bool register_method() override final;
  std::function<void(testA*)> MtSrvAbout_FaoY_callback_;
  std::function<int()> MtSrvStartup_Vp7x_callback_;
  std::function<void()> MtSrvCleanup_6g2V_callback_;
  std::function<int(const testA*)> MtSrvPluginCfgAdd_uEVd_callback_;
  std::function<int(const testA*, const int)> MtSrvPluginCfgSet_gGRa_callback_;
  std::function<int(LPCSTR)> MtSrvPluginCfgDelete_uu7C_callback_;
  std::function<int(LPCSTR, testA*)> MtSrvPluginCfgGet_3GCs_callback_;
  std::function<int(const int, testA*)> MtSrvPluginCfgNext_bAVb_callback_;
  std::function<int()> MtSrvPluginCfgTotal_r2W1_callback_;
  std::function<void(testA*, const int)> MtSrvTradeRequestApply_XpuX_callback_;
  std::function<int(const testA*, const testA*, const testA*)>
      MtSrvTradeStopsFilter_wbtO_callback_;
  std::function<int(const testA*, const testA*, const testA*, testA*,
                    const int)>
      MtSrvTradeStopsApply_lDzq_callback_;
  std::function<int(const testA*, const testA*, const testA*)>
      MtSrvTradePendingsFilter_RwNh_callback_;
  std::function<int(const testA*, const testA*, const testA*, const testA*,
                    testA*)>
      MtSrvTradePendingsApply_2XO4_callback_;
  std::function<int(const testA*, const testA*, const int, const double,
                    const double)>
      MtSrvTradeStopoutsFilter_1Rnz_callback_;
  std::function<int(const testA*, const testA*, const testA*, testA*)>
      MtSrvTradeStopoutsApply_hi0p_callback_;
  std::function<void(testA*, const testA*, const testA*, const testA*,
                     const int)>
      MtSrvTradesAddRequest_E0Tz_callback_;
  std::function<int(testA*, testA*, testA*)>
      MtSrvTradeTransaction_wpvK_callback_;
  std::function<void(testA*, const testA*, const testA*)>
      MtSrvTradeCommission_NaKR_callback_;
  std::function<int(testA*, const testA*, const testA*)>
      MtSrvTradeCommissionAgent_ZItd_callback_;
  std::function<void(const testA*, testA*)>
      MtSrvHistoryTickApply_Jy9x_callback_;
};

inline bool plugin_rpc_server::register_method() {
  dispatcher()->add("MtSrvAbout_FaoY",
                    [this](std::string info_format) -> std::tuple<std::string> {
                      auto info_vector_nkGG = ::rpc_parse<testA>(info_format);
                      testA* info_ptr_PtWY = info_vector_nkGG.data();

                      MtSrvAbout_FaoY_callback_(info_ptr_PtWY);
                      return std::make_tuple(::rpc_format(info_ptr_PtWY));
                    });

  dispatcher()->add("MtSrvStartup_Vp7x", [this]() -> std::tuple<int> {
    auto result = MtSrvStartup_Vp7x_callback_();
    return std::make_tuple(result);
  });

  dispatcher()->add("MtSrvCleanup_6g2V",
                    [this]() { MtSrvCleanup_6g2V_callback_(); });

  dispatcher()->add("MtSrvPluginCfgAdd_uEVd",
                    [this](std::string cfg_format) -> std::tuple<int> {
                      auto cfg_vector_9yFQ = ::rpc_parse<testA>(cfg_format);
                      const testA* cfg_ptr_uFvd = cfg_vector_9yFQ.data();

                      auto result =
                          MtSrvPluginCfgAdd_uEVd_callback_(cfg_ptr_uFvd);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvPluginCfgSet_gGRa",
      [this](std::string values_format, const int total) -> std::tuple<int> {
        auto values_vector_nmHU = ::rpc_parse<testA>(values_format);
        const testA* values_ptr_ilPE = values_vector_nmHU.data();

        auto result = MtSrvPluginCfgSet_gGRa_callback_(values_ptr_ilPE, total);
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvPluginCfgDelete_uu7C", [this](std::string name) -> std::tuple<int> {
        auto result = MtSrvPluginCfgDelete_uu7C_callback_(name.c_str());
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvPluginCfgGet_3GCs",
      [this](std::string name,
             std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_Cxuy = ::rpc_parse<testA>(cfg_format);
        testA* cfg_ptr_w8Iw = cfg_vector_Cxuy.data();

        auto result =
            MtSrvPluginCfgGet_3GCs_callback_(name.c_str(), cfg_ptr_w8Iw);
        return std::make_tuple(result, ::rpc_format(cfg_ptr_w8Iw));
      });

  dispatcher()->add(
      "MtSrvPluginCfgNext_bAVb",
      [this](const int index,
             std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_BSPh = ::rpc_parse<testA>(cfg_format);
        testA* cfg_ptr_iHU1 = cfg_vector_BSPh.data();

        auto result = MtSrvPluginCfgNext_bAVb_callback_(index, cfg_ptr_iHU1);
        return std::make_tuple(result, ::rpc_format(cfg_ptr_iHU1));
      });

  dispatcher()->add("MtSrvPluginCfgTotal_r2W1", [this]() -> std::tuple<int> {
    auto result = MtSrvPluginCfgTotal_r2W1_callback_();
    return std::make_tuple(result);
  });

  dispatcher()->add(
      "MtSrvTradeRequestApply_XpuX",
      [this](std::string request_format,
             const int isdemo) -> std::tuple<std::string> {
        auto request_vector_nloW = ::rpc_parse<testA>(request_format);
        testA* request_ptr_scno = request_vector_nloW.data();

        MtSrvTradeRequestApply_XpuX_callback_(request_ptr_scno, isdemo);
        return std::make_tuple(::rpc_format(request_ptr_scno));
      });

  dispatcher()->add("MtSrvTradeStopsFilter_wbtO",
                    [this](std::string group_format, std::string symbol_format,
                           std::string trade_format) -> std::tuple<int> {
                      auto group_vector_zPPx = ::rpc_parse<testA>(group_format);
                      const testA* group_ptr_2ieA = group_vector_zPPx.data();

                      auto symbol_vector_R1Mm =
                          ::rpc_parse<testA>(symbol_format);
                      const testA* symbol_ptr_LsgO = symbol_vector_R1Mm.data();

                      auto trade_vector_DSkW = ::rpc_parse<testA>(trade_format);
                      const testA* trade_ptr_GlYY = trade_vector_DSkW.data();

                      auto result = MtSrvTradeStopsFilter_wbtO_callback_(
                          group_ptr_2ieA, symbol_ptr_LsgO, trade_ptr_GlYY);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvTradeStopsApply_lDzq",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format, std::string trade_format,
             const int isTP) -> std::tuple<int, std::string> {
        auto user_vector_8Exr = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_Zsz5 = user_vector_8Exr.data();

        auto group_vector_aeAF = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_mGzC = group_vector_aeAF.data();

        auto symbol_vector_kFyk = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_1yPX = symbol_vector_kFyk.data();

        auto trade_vector_byy2 = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_5U6F = trade_vector_byy2.data();

        auto result = MtSrvTradeStopsApply_lDzq_callback_(
            user_ptr_Zsz5, group_ptr_mGzC, symbol_ptr_1yPX, trade_ptr_5U6F,
            isTP);
        return std::make_tuple(result, ::rpc_format(trade_ptr_5U6F));
      });

  dispatcher()->add("MtSrvTradePendingsFilter_RwNh",
                    [this](std::string group_format, std::string symbol_format,
                           std::string trade_format) -> std::tuple<int> {
                      auto group_vector_eAVw = ::rpc_parse<testA>(group_format);
                      const testA* group_ptr_Hl8u = group_vector_eAVw.data();

                      auto symbol_vector_jAqT =
                          ::rpc_parse<testA>(symbol_format);
                      const testA* symbol_ptr_0IAh = symbol_vector_jAqT.data();

                      auto trade_vector_pgVQ = ::rpc_parse<testA>(trade_format);
                      const testA* trade_ptr_hjlx = trade_vector_pgVQ.data();

                      auto result = MtSrvTradePendingsFilter_RwNh_callback_(
                          group_ptr_Hl8u, symbol_ptr_0IAh, trade_ptr_hjlx);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvTradePendingsApply_2XO4",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format, std::string pending_format,
             std::string trade_format) -> std::tuple<int, std::string> {
        auto user_vector_jLAN = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_lUGL = user_vector_jLAN.data();

        auto group_vector_agYV = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_vn8n = group_vector_agYV.data();

        auto symbol_vector_5Txp = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_x0ML = symbol_vector_5Txp.data();

        auto pending_vector_TlP1 = ::rpc_parse<testA>(pending_format);
        const testA* pending_ptr_b9pK = pending_vector_TlP1.data();

        auto trade_vector_2RlP = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_L8dP = trade_vector_2RlP.data();

        auto result = MtSrvTradePendingsApply_2XO4_callback_(
            user_ptr_lUGL, group_ptr_vn8n, symbol_ptr_x0ML, pending_ptr_b9pK,
            trade_ptr_L8dP);
        return std::make_tuple(result, ::rpc_format(trade_ptr_L8dP));
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsFilter_1Rnz",
      [this](std::string group_format, std::string symbol_format,
             const int login, const double equity,
             const double margin) -> std::tuple<int> {
        auto group_vector_9pgf = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_RONf = group_vector_9pgf.data();

        auto symbol_vector_qInC = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_MpAj = symbol_vector_qInC.data();

        auto result = MtSrvTradeStopoutsFilter_1Rnz_callback_(
            group_ptr_RONf, symbol_ptr_MpAj, login, equity, margin);
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsApply_hi0p",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format,
             std::string stopout_format) -> std::tuple<int, std::string> {
        auto user_vector_fYKp = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_mulL = user_vector_fYKp.data();

        auto group_vector_AfW0 = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_7A2v = group_vector_AfW0.data();

        auto symbol_vector_XseC = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_SQVX = symbol_vector_XseC.data();

        auto stopout_vector_yXPf = ::rpc_parse<testA>(stopout_format);
        testA* stopout_ptr_YxdM = stopout_vector_yXPf.data();

        auto result = MtSrvTradeStopoutsApply_hi0p_callback_(
            user_ptr_mulL, group_ptr_7A2v, symbol_ptr_SQVX, stopout_ptr_YxdM);
        return std::make_tuple(result, ::rpc_format(stopout_ptr_YxdM));
      });

  dispatcher()->add(
      "MtSrvTradesAddRequest_E0Tz",
      [this](std::string trade_format, std::string request_format,
             std::string user_format, std::string symbol_format,
             const int mode) -> std::tuple<std::string> {
        auto trade_vector_X2WE = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_paw5 = trade_vector_X2WE.data();

        auto request_vector_Bf52 = ::rpc_parse<testA>(request_format);
        const testA* request_ptr_5js9 = request_vector_Bf52.data();

        auto user_vector_uOtx = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_5OyZ = user_vector_uOtx.data();

        auto symbol_vector_f6F8 = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_78hz = symbol_vector_f6F8.data();

        MtSrvTradesAddRequest_E0Tz_callback_(trade_ptr_paw5, request_ptr_5js9,
                                             user_ptr_5OyZ, symbol_ptr_78hz,
                                             mode);
        return std::make_tuple(::rpc_format(trade_ptr_paw5));
      });

  dispatcher()->add(
      "MtSrvTradeTransaction_wpvK",
      [this](std::string trade_format, std::string user_format,
             std::string request_id_format)
          -> std::tuple<int, std::string, std::string, std::string> {
        auto trade_vector_w6vD = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_Dljk = trade_vector_w6vD.data();

        auto user_vector_3JCA = ::rpc_parse<testA>(user_format);
        testA* user_ptr_b8vi = user_vector_3JCA.data();

        auto request_id_vector_SHvF = ::rpc_parse<testA>(request_id_format);
        testA* request_id_ptr_xxrJ = request_id_vector_SHvF.data();

        auto result = MtSrvTradeTransaction_wpvK_callback_(
            trade_ptr_Dljk, user_ptr_b8vi, request_id_ptr_xxrJ);
        return std::make_tuple(result, ::rpc_format(trade_ptr_Dljk),
                               ::rpc_format(user_ptr_b8vi),
                               ::rpc_format(request_id_ptr_xxrJ));
      });

  dispatcher()->add("MtSrvTradeCommission_NaKR",
                    [this](std::string trade_format, std::string Sec_format,
                           std::string Grp_format) -> std::tuple<std::string> {
                      auto trade_vector_78xN = ::rpc_parse<testA>(trade_format);
                      testA* trade_ptr_0gC3 = trade_vector_78xN.data();

                      auto Sec_vector_RjXx = ::rpc_parse<testA>(Sec_format);
                      const testA* Sec_ptr_Nhkm = Sec_vector_RjXx.data();

                      auto Grp_vector_nQu3 = ::rpc_parse<testA>(Grp_format);
                      const testA* Grp_ptr_PHF0 = Grp_vector_nQu3.data();

                      MtSrvTradeCommission_NaKR_callback_(
                          trade_ptr_0gC3, Sec_ptr_Nhkm, Grp_ptr_PHF0);
                      return std::make_tuple(::rpc_format(trade_ptr_0gC3));
                    });

  dispatcher()->add(
      "MtSrvTradeCommissionAgent_ZItd",
      [this](std::string trade_format, std::string sec_format,
             std::string info_format) -> std::tuple<int, std::string> {
        auto trade_vector_fQoL = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_yqMo = trade_vector_fQoL.data();

        auto sec_vector_0wIB = ::rpc_parse<testA>(sec_format);
        const testA* sec_ptr_UBW6 = sec_vector_0wIB.data();

        auto info_vector_Ado2 = ::rpc_parse<testA>(info_format);
        const testA* info_ptr_lKpC = info_vector_Ado2.data();

        auto result = MtSrvTradeCommissionAgent_ZItd_callback_(
            trade_ptr_yqMo, sec_ptr_UBW6, info_ptr_lKpC);
        return std::make_tuple(result, ::rpc_format(trade_ptr_yqMo));
      });

  dispatcher()->add(
      "MtSrvHistoryTickApply_Jy9x",
      [this](std::string symbol_format,
             std::string inf_format) -> std::tuple<std::string> {
        auto symbol_vector_DD0z = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_fULS = symbol_vector_DD0z.data();

        auto inf_vector_Q3H9 = ::rpc_parse<testA>(inf_format);
        testA* inf_ptr_7aXK = inf_vector_Q3H9.data();

        MtSrvHistoryTickApply_Jy9x_callback_(symbol_ptr_fULS, inf_ptr_7aXK);
        return std::make_tuple(::rpc_format(inf_ptr_7aXK));
      });
  return true;
}
