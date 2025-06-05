
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
  std::function<void(testA*)> MtSrvAbout_xag0_callback_;
  std::function<int()> MtSrvStartup_wqvx_callback_;
  std::function<void()> MtSrvCleanup_cnya_callback_;
  std::function<int(const testA*)> MtSrvPluginCfgAdd_lLd3_callback_;
  std::function<int(const testA*, const int)> MtSrvPluginCfgSet_TmFN_callback_;
  std::function<int(LPCSTR)> MtSrvPluginCfgDelete_nUU9_callback_;
  std::function<int(LPCSTR, testA*)> MtSrvPluginCfgGet_Pc04_callback_;
  std::function<int(const int, testA*)> MtSrvPluginCfgNext_sQ05_callback_;
  std::function<int()> MtSrvPluginCfgTotal_3ToP_callback_;
  std::function<void(testA*, const int)> MtSrvTradeRequestApply_uuVJ_callback_;
  std::function<int(const testA*, const testA*, const testA*)>
      MtSrvTradeStopsFilter_Bi0U_callback_;
  std::function<int(const testA*, const testA*, const testA*, testA*,
                    const int)>
      MtSrvTradeStopsApply_2crI_callback_;
  std::function<int(const testA*, const testA*, const testA*)>
      MtSrvTradePendingsFilter_91ay_callback_;
  std::function<int(const testA*, const testA*, const testA*, const testA*,
                    testA*)>
      MtSrvTradePendingsApply_4QyA_callback_;
  std::function<int(const testA*, const testA*, const int, const double,
                    const double)>
      MtSrvTradeStopoutsFilter_FmdX_callback_;
  std::function<int(const testA*, const testA*, const testA*, testA*)>
      MtSrvTradeStopoutsApply_n4Jz_callback_;
  std::function<void(testA*, const testA*, const testA*, const testA*,
                     const int)>
      MtSrvTradesAddRequest_MuDN_callback_;
  std::function<int(testA*, testA*, testA*)>
      MtSrvTradeTransaction_K8PA_callback_;
  std::function<void(testA*, const testA*, const testA*)>
      MtSrvTradeCommission_vgqL_callback_;
  std::function<int(testA*, const testA*, const testA*)>
      MtSrvTradeCommissionAgent_55QD_callback_;
  std::function<void(const testA*, testA*)>
      MtSrvHistoryTickApply_49xM_callback_;
};

inline bool plugin_rpc_server::register_method() {
  dispatcher()->add("MtSrvAbout_xag0",
                    [this](std::string info_format) -> std::tuple<std::string> {
                      auto info_vector_ZCjH = ::rpc_parse<testA>(info_format);
                      testA* info_ptr_MF9p = info_vector_ZCjH.data();

                      MtSrvAbout_xag0_callback_(info_ptr_MF9p);
                      return std::make_tuple(::rpc_format(info_ptr_MF9p));
                    });

  dispatcher()->add("MtSrvStartup_wqvx", [this]() -> std::tuple<int> {
    auto result = MtSrvStartup_wqvx_callback_();
    return std::make_tuple(result);
  });

  dispatcher()->add("MtSrvCleanup_cnya",
                    [this]() { MtSrvCleanup_cnya_callback_(); });

  dispatcher()->add("MtSrvPluginCfgAdd_lLd3",
                    [this](std::string cfg_format) -> std::tuple<int> {
                      auto cfg_vector_Hlx4 = ::rpc_parse<testA>(cfg_format);
                      const testA* cfg_ptr_4bD1 = cfg_vector_Hlx4.data();

                      auto result =
                          MtSrvPluginCfgAdd_lLd3_callback_(cfg_ptr_4bD1);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvPluginCfgSet_TmFN",
      [this](std::string values_format, const int total) -> std::tuple<int> {
        auto values_vector_7JAn = ::rpc_parse<testA>(values_format);
        const testA* values_ptr_zWKH = values_vector_7JAn.data();

        auto result = MtSrvPluginCfgSet_TmFN_callback_(values_ptr_zWKH, total);
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvPluginCfgDelete_nUU9", [this](std::string name) -> std::tuple<int> {
        auto result = MtSrvPluginCfgDelete_nUU9_callback_(name.c_str());
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvPluginCfgGet_Pc04",
      [this](std::string name,
             std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_lUfh = ::rpc_parse<testA>(cfg_format);
        testA* cfg_ptr_iZlG = cfg_vector_lUfh.data();

        auto result =
            MtSrvPluginCfgGet_Pc04_callback_(name.c_str(), cfg_ptr_iZlG);
        return std::make_tuple(result, ::rpc_format(cfg_ptr_iZlG));
      });

  dispatcher()->add(
      "MtSrvPluginCfgNext_sQ05",
      [this](const int index,
             std::string cfg_format) -> std::tuple<int, std::string> {
        auto cfg_vector_ZyHq = ::rpc_parse<testA>(cfg_format);
        testA* cfg_ptr_Vlo5 = cfg_vector_ZyHq.data();

        auto result = MtSrvPluginCfgNext_sQ05_callback_(index, cfg_ptr_Vlo5);
        return std::make_tuple(result, ::rpc_format(cfg_ptr_Vlo5));
      });

  dispatcher()->add("MtSrvPluginCfgTotal_3ToP", [this]() -> std::tuple<int> {
    auto result = MtSrvPluginCfgTotal_3ToP_callback_();
    return std::make_tuple(result);
  });

  dispatcher()->add(
      "MtSrvTradeRequestApply_uuVJ",
      [this](std::string request_format,
             const int isdemo) -> std::tuple<std::string> {
        auto request_vector_TG8m = ::rpc_parse<testA>(request_format);
        testA* request_ptr_UMkN = request_vector_TG8m.data();

        MtSrvTradeRequestApply_uuVJ_callback_(request_ptr_UMkN, isdemo);
        return std::make_tuple(::rpc_format(request_ptr_UMkN));
      });

  dispatcher()->add("MtSrvTradeStopsFilter_Bi0U",
                    [this](std::string group_format, std::string symbol_format,
                           std::string trade_format) -> std::tuple<int> {
                      auto group_vector_D9MC = ::rpc_parse<testA>(group_format);
                      const testA* group_ptr_c27R = group_vector_D9MC.data();

                      auto symbol_vector_HDge =
                          ::rpc_parse<testA>(symbol_format);
                      const testA* symbol_ptr_Wx2k = symbol_vector_HDge.data();

                      auto trade_vector_6RNv = ::rpc_parse<testA>(trade_format);
                      const testA* trade_ptr_9nL5 = trade_vector_6RNv.data();

                      auto result = MtSrvTradeStopsFilter_Bi0U_callback_(
                          group_ptr_c27R, symbol_ptr_Wx2k, trade_ptr_9nL5);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvTradeStopsApply_2crI",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format, std::string trade_format,
             const int isTP) -> std::tuple<int, std::string> {
        auto user_vector_MJHb = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_pz3y = user_vector_MJHb.data();

        auto group_vector_eJCl = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_HE1V = group_vector_eJCl.data();

        auto symbol_vector_aBah = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_EcoK = symbol_vector_aBah.data();

        auto trade_vector_fw86 = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_20BI = trade_vector_fw86.data();

        auto result = MtSrvTradeStopsApply_2crI_callback_(
            user_ptr_pz3y, group_ptr_HE1V, symbol_ptr_EcoK, trade_ptr_20BI,
            isTP);
        return std::make_tuple(result, ::rpc_format(trade_ptr_20BI));
      });

  dispatcher()->add("MtSrvTradePendingsFilter_91ay",
                    [this](std::string group_format, std::string symbol_format,
                           std::string trade_format) -> std::tuple<int> {
                      auto group_vector_CZIZ = ::rpc_parse<testA>(group_format);
                      const testA* group_ptr_3V1E = group_vector_CZIZ.data();

                      auto symbol_vector_iHJC =
                          ::rpc_parse<testA>(symbol_format);
                      const testA* symbol_ptr_VDPH = symbol_vector_iHJC.data();

                      auto trade_vector_G3s4 = ::rpc_parse<testA>(trade_format);
                      const testA* trade_ptr_juHP = trade_vector_G3s4.data();

                      auto result = MtSrvTradePendingsFilter_91ay_callback_(
                          group_ptr_3V1E, symbol_ptr_VDPH, trade_ptr_juHP);
                      return std::make_tuple(result);
                    });

  dispatcher()->add(
      "MtSrvTradePendingsApply_4QyA",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format, std::string pending_format,
             std::string trade_format) -> std::tuple<int, std::string> {
        auto user_vector_CuHp = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_hpNW = user_vector_CuHp.data();

        auto group_vector_hPDE = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_VfJe = group_vector_hPDE.data();

        auto symbol_vector_Ppt9 = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_3ctX = symbol_vector_Ppt9.data();

        auto pending_vector_Z31L = ::rpc_parse<testA>(pending_format);
        const testA* pending_ptr_y9mT = pending_vector_Z31L.data();

        auto trade_vector_yUuV = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_nQob = trade_vector_yUuV.data();

        auto result = MtSrvTradePendingsApply_4QyA_callback_(
            user_ptr_hpNW, group_ptr_VfJe, symbol_ptr_3ctX, pending_ptr_y9mT,
            trade_ptr_nQob);
        return std::make_tuple(result, ::rpc_format(trade_ptr_nQob));
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsFilter_FmdX",
      [this](std::string group_format, std::string symbol_format,
             const int login, const double equity,
             const double margin) -> std::tuple<int> {
        auto group_vector_LG7W = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_KN1u = group_vector_LG7W.data();

        auto symbol_vector_p04y = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_MQUn = symbol_vector_p04y.data();

        auto result = MtSrvTradeStopoutsFilter_FmdX_callback_(
            group_ptr_KN1u, symbol_ptr_MQUn, login, equity, margin);
        return std::make_tuple(result);
      });

  dispatcher()->add(
      "MtSrvTradeStopoutsApply_n4Jz",
      [this](std::string user_format, std::string group_format,
             std::string symbol_format,
             std::string stopout_format) -> std::tuple<int, std::string> {
        auto user_vector_iq09 = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_3mzk = user_vector_iq09.data();

        auto group_vector_aSty = ::rpc_parse<testA>(group_format);
        const testA* group_ptr_jpi9 = group_vector_aSty.data();

        auto symbol_vector_BRfk = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_1zy1 = symbol_vector_BRfk.data();

        auto stopout_vector_UmfF = ::rpc_parse<testA>(stopout_format);
        testA* stopout_ptr_3V16 = stopout_vector_UmfF.data();

        auto result = MtSrvTradeStopoutsApply_n4Jz_callback_(
            user_ptr_3mzk, group_ptr_jpi9, symbol_ptr_1zy1, stopout_ptr_3V16);
        return std::make_tuple(result, ::rpc_format(stopout_ptr_3V16));
      });

  dispatcher()->add(
      "MtSrvTradesAddRequest_MuDN",
      [this](std::string trade_format, std::string request_format,
             std::string user_format, std::string symbol_format,
             const int mode) -> std::tuple<std::string> {
        auto trade_vector_ZHdX = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_dXlU = trade_vector_ZHdX.data();

        auto request_vector_YdRv = ::rpc_parse<testA>(request_format);
        const testA* request_ptr_jTJW = request_vector_YdRv.data();

        auto user_vector_yCxq = ::rpc_parse<testA>(user_format);
        const testA* user_ptr_GFe9 = user_vector_yCxq.data();

        auto symbol_vector_L8ds = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_qZOz = symbol_vector_L8ds.data();

        MtSrvTradesAddRequest_MuDN_callback_(trade_ptr_dXlU, request_ptr_jTJW,
                                             user_ptr_GFe9, symbol_ptr_qZOz,
                                             mode);
        return std::make_tuple(::rpc_format(trade_ptr_dXlU));
      });

  dispatcher()->add(
      "MtSrvTradeTransaction_K8PA",
      [this](std::string trade_format, std::string user_format,
             std::string request_id_format)
          -> std::tuple<int, std::string, std::string, std::string> {
        auto trade_vector_5rcd = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_JPoC = trade_vector_5rcd.data();

        auto user_vector_z4FI = ::rpc_parse<testA>(user_format);
        testA* user_ptr_r27a = user_vector_z4FI.data();

        auto request_id_vector_GFYV = ::rpc_parse<testA>(request_id_format);
        testA* request_id_ptr_GwdV = request_id_vector_GFYV.data();

        auto result = MtSrvTradeTransaction_K8PA_callback_(
            trade_ptr_JPoC, user_ptr_r27a, request_id_ptr_GwdV);
        return std::make_tuple(result, ::rpc_format(trade_ptr_JPoC),
                               ::rpc_format(user_ptr_r27a),
                               ::rpc_format(request_id_ptr_GwdV));
      });

  dispatcher()->add("MtSrvTradeCommission_vgqL",
                    [this](std::string trade_format, std::string Sec_format,
                           std::string Grp_format) -> std::tuple<std::string> {
                      auto trade_vector_tJ33 = ::rpc_parse<testA>(trade_format);
                      testA* trade_ptr_7nJs = trade_vector_tJ33.data();

                      auto Sec_vector_jdrH = ::rpc_parse<testA>(Sec_format);
                      const testA* Sec_ptr_WwaM = Sec_vector_jdrH.data();

                      auto Grp_vector_YIG3 = ::rpc_parse<testA>(Grp_format);
                      const testA* Grp_ptr_g5Kb = Grp_vector_YIG3.data();

                      MtSrvTradeCommission_vgqL_callback_(
                          trade_ptr_7nJs, Sec_ptr_WwaM, Grp_ptr_g5Kb);
                      return std::make_tuple(::rpc_format(trade_ptr_7nJs));
                    });

  dispatcher()->add(
      "MtSrvTradeCommissionAgent_55QD",
      [this](std::string trade_format, std::string sec_format,
             std::string info_format) -> std::tuple<int, std::string> {
        auto trade_vector_6njM = ::rpc_parse<testA>(trade_format);
        testA* trade_ptr_uHzK = trade_vector_6njM.data();

        auto sec_vector_yMs7 = ::rpc_parse<testA>(sec_format);
        const testA* sec_ptr_L3mj = sec_vector_yMs7.data();

        auto info_vector_kOgq = ::rpc_parse<testA>(info_format);
        const testA* info_ptr_Mtuo = info_vector_kOgq.data();

        auto result = MtSrvTradeCommissionAgent_55QD_callback_(
            trade_ptr_uHzK, sec_ptr_L3mj, info_ptr_Mtuo);
        return std::make_tuple(result, ::rpc_format(trade_ptr_uHzK));
      });

  dispatcher()->add(
      "MtSrvHistoryTickApply_49xM",
      [this](std::string symbol_format,
             std::string inf_format) -> std::tuple<std::string> {
        auto symbol_vector_O9vd = ::rpc_parse<testA>(symbol_format);
        const testA* symbol_ptr_Wekz = symbol_vector_O9vd.data();

        auto inf_vector_viwJ = ::rpc_parse<testA>(inf_format);
        testA* inf_ptr_O399 = inf_vector_viwJ.data();

        MtSrvHistoryTickApply_49xM_callback_(symbol_ptr_Wekz, inf_ptr_O399);
        return std::make_tuple(::rpc_format(inf_ptr_O399));
      });
  return true;
}
