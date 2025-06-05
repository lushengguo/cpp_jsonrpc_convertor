
#include <gtest/gtest.h>

#include <functional>

#include "client.h"
#include "define.h"
#include "interface.h"
#include "jsonrpc.h"
#include "server.h"
#include "test_helper.h"
TEST_F(RpcTestFixture, MtSrvAbout_FaoY) {
  // input parameters
  testA info_input = random_value<testA>();

  // output parameters
  testA info_output = random_value<testA>();

  // diy callback
  server->MtSrvAbout_FaoY_callback_ = [&](testA* info) {
    // check input
    EXPECT_EQ(memcmp(&info_input, info, sizeof(testA)), 0);

    // assign output
    memcpy(info, &info_output, sizeof(testA));

    // return value
  };

  // call the RPC method
  client->MtSrvAbout_Rpc(&info_input);

  // check the result
  EXPECT_EQ(memcmp(&info_output, &info_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvStartup_Vp7x) {
  // input parameters

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvStartup_Vp7x_callback_ = [&]() {
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

TEST_F(RpcTestFixture, MtSrvCleanup_6g2V) {
  // input parameters

  // output parameters

  // diy callback
  server->MtSrvCleanup_6g2V_callback_ = [&]() {
    // check input

    // assign output

    // return value
  };

  // call the RPC method
  client->MtSrvCleanup_Rpc();

  // check the result
}

TEST_F(RpcTestFixture, MtSrvPluginCfgAdd_uEVd) {
  // input parameters
  testA cfg_input = random_value<testA>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgAdd_uEVd_callback_ = [&](const testA* cfg) {
    // check input
    EXPECT_EQ(memcmp(&cfg_input, cfg, sizeof(const testA)), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgAdd_Rpc(&cfg_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgSet_gGRa) {
  // input parameters
  testA values_input = random_value<testA>();
  const int total_input = random_value<int>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgSet_gGRa_callback_ = [&](const testA* values,
                                                 const int total) {
    // check input
    EXPECT_EQ(memcmp(&values_input, values, sizeof(const testA)), 0);
    EXPECT_EQ(memcmp(&total_input, &total, sizeof(const int)), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgSet_Rpc(&values_input, total_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgDelete_uu7C) {
  // input parameters
  LPCSTR name_input = "abcdefg";

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgDelete_uu7C_callback_ = [&](LPCSTR name) {
    // check input
    EXPECT_EQ(strcmp(name_input, name), 0);

    // assign output

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgDelete_Rpc(name_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgGet_3GCs) {
  // input parameters
  LPCSTR name_input = "abcdefg";
  testA cfg_input = random_value<testA>();

  // output parameters
  testA cfg_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgGet_3GCs_callback_ = [&](LPCSTR name, testA* cfg) {
    // check input
    EXPECT_EQ(strcmp(name_input, name), 0);
    EXPECT_EQ(memcmp(&cfg_input, cfg, sizeof(testA)), 0);

    // assign output
    memcpy(cfg, &cfg_output, sizeof(testA));

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgGet_Rpc(name_input, &cfg_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&cfg_output, &cfg_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgNext_bAVb) {
  // input parameters
  const int index_input = random_value<int>();
  testA cfg_input = random_value<testA>();

  // output parameters
  testA cfg_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgNext_bAVb_callback_ = [&](const int index, testA* cfg) {
    // check input
    EXPECT_EQ(memcmp(&index_input, &index, sizeof(const int)), 0);
    EXPECT_EQ(memcmp(&cfg_input, cfg, sizeof(testA)), 0);

    // assign output
    memcpy(cfg, &cfg_output, sizeof(testA));

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvPluginCfgNext_Rpc(index_input, &cfg_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&cfg_output, &cfg_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvPluginCfgTotal_r2W1) {
  // input parameters

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgTotal_r2W1_callback_ = [&]() {
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

TEST_F(RpcTestFixture, MtSrvTradeRequestApply_XpuX) {
  // input parameters
  testA request_input = random_value<testA>();
  const int isdemo_input = random_value<int>();

  // output parameters
  testA request_output = random_value<testA>();

  // diy callback
  server->MtSrvTradeRequestApply_XpuX_callback_ = [&](testA* request,
                                                      const int isdemo) {
    // check input
    EXPECT_EQ(memcmp(&request_input, request, sizeof(testA)), 0);
    EXPECT_EQ(memcmp(&isdemo_input, &isdemo, sizeof(const int)), 0);

    // assign output
    memcpy(request, &request_output, sizeof(testA));

    // return value
  };

  // call the RPC method
  client->MtSrvTradeRequestApply_Rpc(&request_input, isdemo_input);

  // check the result
  EXPECT_EQ(memcmp(&request_output, &request_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeStopsFilter_wbtO) {
  // input parameters
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA trade_input = random_value<testA>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopsFilter_wbtO_callback_ =
      [&](const testA* group, const testA* symbol, const testA* trade) {
        // check input
        EXPECT_EQ(memcmp(&group_input, group, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(const testA)), 0);

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

TEST_F(RpcTestFixture, MtSrvTradeStopsApply_lDzq) {
  // input parameters
  testA user_input = random_value<testA>();
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA trade_input = random_value<testA>();
  const int isTP_input = random_value<int>();

  // output parameters
  testA trade_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopsApply_lDzq_callback_ =
      [&](const testA* user, const testA* group, const testA* symbol,
          testA* trade, const int isTP) {
        // check input
        EXPECT_EQ(memcmp(&user_input, user, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&group_input, group, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(testA)), 0);
        EXPECT_EQ(memcmp(&isTP_input, &isTP, sizeof(const int)), 0);

        // assign output
        memcpy(trade, &trade_output, sizeof(testA));

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeStopsApply_Rpc(
      &user_input, &group_input, &symbol_input, &trade_input, isTP_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&trade_output, &trade_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradePendingsFilter_RwNh) {
  // input parameters
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA trade_input = random_value<testA>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradePendingsFilter_RwNh_callback_ =
      [&](const testA* group, const testA* symbol, const testA* trade) {
        // check input
        EXPECT_EQ(memcmp(&group_input, group, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(const testA)), 0);

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

TEST_F(RpcTestFixture, MtSrvTradePendingsApply_2XO4) {
  // input parameters
  testA user_input = random_value<testA>();
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA pending_input = random_value<testA>();
  testA trade_input = random_value<testA>();

  // output parameters
  testA trade_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradePendingsApply_2XO4_callback_ =
      [&](const testA* user, const testA* group, const testA* symbol,
          const testA* pending, testA* trade) {
        // check input
        EXPECT_EQ(memcmp(&user_input, user, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&group_input, group, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&pending_input, pending, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(testA)), 0);

        // assign output
        memcpy(trade, &trade_output, sizeof(testA));

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradePendingsApply_Rpc(
      &user_input, &group_input, &symbol_input, &pending_input, &trade_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&trade_output, &trade_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeStopoutsFilter_1Rnz) {
  // input parameters
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  const int login_input = random_value<int>();
  const double equity_input = random_value<double>();
  const double margin_input = random_value<double>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopoutsFilter_1Rnz_callback_ =
      [&](const testA* group, const testA* symbol, const int login,
          const double equity, const double margin) {
        // check input
        EXPECT_EQ(memcmp(&group_input, group, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&login_input, &login, sizeof(const int)), 0);
        EXPECT_EQ(memcmp(&equity_input, &equity, sizeof(const double)), 0);
        EXPECT_EQ(memcmp(&margin_input, &margin, sizeof(const double)), 0);

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

TEST_F(RpcTestFixture, MtSrvTradeStopoutsApply_hi0p) {
  // input parameters
  testA user_input = random_value<testA>();
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA stopout_input = random_value<testA>();

  // output parameters
  testA stopout_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopoutsApply_hi0p_callback_ =
      [&](const testA* user, const testA* group, const testA* symbol,
          testA* stopout) {
        // check input
        EXPECT_EQ(memcmp(&user_input, user, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&group_input, group, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&stopout_input, stopout, sizeof(testA)), 0);

        // assign output
        memcpy(stopout, &stopout_output, sizeof(testA));

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeStopoutsApply_Rpc(
      &user_input, &group_input, &symbol_input, &stopout_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&stopout_output, &stopout_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradesAddRequest_E0Tz) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA request_input = random_value<testA>();
  testA user_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  const int mode_input = random_value<int>();

  // output parameters
  testA trade_output = random_value<testA>();

  // diy callback
  server->MtSrvTradesAddRequest_E0Tz_callback_ =
      [&](testA* trade, const testA* request, const testA* user,
          const testA* symbol, const int mode) {
        // check input
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(testA)), 0);
        EXPECT_EQ(memcmp(&request_input, request, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&user_input, user, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&mode_input, &mode, sizeof(const int)), 0);

        // assign output
        memcpy(trade, &trade_output, sizeof(testA));

        // return value
      };

  // call the RPC method
  client->MtSrvTradesAddRequest_Rpc(&trade_input, &request_input, &user_input,
                                    &symbol_input, mode_input);

  // check the result
  EXPECT_EQ(memcmp(&trade_output, &trade_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeTransaction_wpvK) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA user_input = random_value<testA>();
  testA request_id_input = random_value<testA>();

  // output parameters
  testA trade_output = random_value<testA>();
  testA user_output = random_value<testA>();
  testA request_id_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeTransaction_wpvK_callback_ = [&](testA* trade, testA* user,
                                                     testA* request_id) {
    // check input
    EXPECT_EQ(memcmp(&trade_input, trade, sizeof(testA)), 0);
    EXPECT_EQ(memcmp(&user_input, user, sizeof(testA)), 0);
    EXPECT_EQ(memcmp(&request_id_input, request_id, sizeof(testA)), 0);

    // assign output
    memcpy(trade, &trade_output, sizeof(testA));
    memcpy(user, &user_output, sizeof(testA));
    memcpy(request_id, &request_id_output, sizeof(testA));

    // return value
    return rpc_result_output;
  };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeTransaction_Rpc(&trade_input, &user_input,
                                                      &request_id_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&trade_output, &trade_input, sizeof(testA)), 0);
  EXPECT_EQ(memcmp(&user_output, &user_input, sizeof(testA)), 0);
  EXPECT_EQ(memcmp(&request_id_output, &request_id_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeCommission_NaKR) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA Sec_input = random_value<testA>();
  testA Grp_input = random_value<testA>();

  // output parameters
  testA trade_output = random_value<testA>();

  // diy callback
  server->MtSrvTradeCommission_NaKR_callback_ =
      [&](testA* trade, const testA* Sec, const testA* Grp) {
        // check input
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(testA)), 0);
        EXPECT_EQ(memcmp(&Sec_input, Sec, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&Grp_input, Grp, sizeof(const testA)), 0);

        // assign output
        memcpy(trade, &trade_output, sizeof(testA));

        // return value
      };

  // call the RPC method
  client->MtSrvTradeCommission_Rpc(&trade_input, &Sec_input, &Grp_input);

  // check the result
  EXPECT_EQ(memcmp(&trade_output, &trade_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvTradeCommissionAgent_ZItd) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA sec_input = random_value<testA>();
  testA info_input = random_value<testA>();

  // output parameters
  testA trade_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeCommissionAgent_ZItd_callback_ =
      [&](testA* trade, const testA* sec, const testA* info) {
        // check input
        EXPECT_EQ(memcmp(&trade_input, trade, sizeof(testA)), 0);
        EXPECT_EQ(memcmp(&sec_input, sec, sizeof(const testA)), 0);
        EXPECT_EQ(memcmp(&info_input, info, sizeof(const testA)), 0);

        // assign output
        memcpy(trade, &trade_output, sizeof(testA));

        // return value
        return rpc_result_output;
      };

  // call the RPC method
  auto rpc_result = client->MtSrvTradeCommissionAgent_Rpc(
      &trade_input, &sec_input, &info_input);

  // check the result
  EXPECT_EQ(rpc_result, rpc_result_output);
  EXPECT_EQ(memcmp(&trade_output, &trade_input, sizeof(testA)), 0);
}

TEST_F(RpcTestFixture, MtSrvHistoryTickApply_Jy9x) {
  // input parameters
  testA symbol_input = random_value<testA>();
  testA inf_input = random_value<testA>();

  // output parameters
  testA inf_output = random_value<testA>();

  // diy callback
  server->MtSrvHistoryTickApply_Jy9x_callback_ = [&](const testA* symbol,
                                                     testA* inf) {
    // check input
    EXPECT_EQ(memcmp(&symbol_input, symbol, sizeof(const testA)), 0);
    EXPECT_EQ(memcmp(&inf_input, inf, sizeof(testA)), 0);

    // assign output
    memcpy(inf, &inf_output, sizeof(testA));

    // return value
  };

  // call the RPC method
  client->MtSrvHistoryTickApply_Rpc(&symbol_input, &inf_input);

  // check the result
  EXPECT_EQ(memcmp(&inf_output, &inf_input, sizeof(testA)), 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
