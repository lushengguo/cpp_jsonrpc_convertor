
#include <gtest/gtest.h>

#include "client.h"
#include "define.h"
#include "functional"
#include "jsonrpc.h"
#include "server.h"
TEST_F(RpcTestFixture, MtSrvAbout_G7DX) {
  // input parameters
  testA info_input = random_value<testA>();

  // output parameters
  testA info_output = random_value<testA>();

  // diy callback
  server->MtSrvAbout_G7DX_callback_ = [&](testA* info) {
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

TEST_F(RpcTestFixture, MtSrvStartup_E0gE) {
  // input parameters

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvStartup_E0gE_callback_ = [&]() {
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

TEST_F(RpcTestFixture, MtSrvCleanup_PKHr) {
  // input parameters

  // output parameters

  // diy callback
  server->MtSrvCleanup_PKHr_callback_ = [&]() {
    // check input

    // assign output

    // return value
  };

  // call the RPC method
  client->MtSrvCleanup_Rpc();

  // check the result
}

TEST_F(RpcTestFixture, MtSrvPluginCfgAdd_CbA0) {
  // input parameters
  testA cfg_input = random_value<testA>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgAdd_CbA0_callback_ = [&](const testA* cfg) {
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

TEST_F(RpcTestFixture, MtSrvPluginCfgSet_tifQ) {
  // input parameters
  testA values_input = random_value<testA>();
  const int total_input = random_value<int>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgSet_tifQ_callback_ = [&](const testA* values,
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

TEST_F(RpcTestFixture, MtSrvPluginCfgDelete_vkKH) {
  // input parameters
  LPCSTR name_input = "abcdefg";

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgDelete_vkKH_callback_ = [&](LPCSTR name) {
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

TEST_F(RpcTestFixture, MtSrvPluginCfgGet_WMtN) {
  // input parameters
  LPCSTR name_input = "abcdefg";
  testA cfg_input = random_value<testA>();

  // output parameters
  testA cfg_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgGet_WMtN_callback_ = [&](LPCSTR name, testA* cfg) {
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

TEST_F(RpcTestFixture, MtSrvPluginCfgNext_9LGj) {
  // input parameters
  const int index_input = random_value<int>();
  testA cfg_input = random_value<testA>();

  // output parameters
  testA cfg_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgNext_9LGj_callback_ = [&](const int index, testA* cfg) {
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

TEST_F(RpcTestFixture, MtSrvPluginCfgTotal_cffM) {
  // input parameters

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvPluginCfgTotal_cffM_callback_ = [&]() {
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

TEST_F(RpcTestFixture, MtSrvTradeRequestApply_yL5z) {
  // input parameters
  testA request_input = random_value<testA>();
  const int isdemo_input = random_value<int>();

  // output parameters
  testA request_output = random_value<testA>();

  // diy callback
  server->MtSrvTradeRequestApply_yL5z_callback_ = [&](testA* request,
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

TEST_F(RpcTestFixture, MtSrvTradeStopsFilter_l8h6) {
  // input parameters
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA trade_input = random_value<testA>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeStopsFilter_l8h6_callback_ =
      [&](const testA* group, const testA* symbol, const testA* trade) {
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

TEST_F(RpcTestFixture, MtSrvTradeStopsApply_oFkn) {
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
  server->MtSrvTradeStopsApply_oFkn_callback_ =
      [&](const testA* user, const testA* group, const testA* symbol,
          testA* trade, const int isTP) {
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

TEST_F(RpcTestFixture, MtSrvTradePendingsFilter_0RQG) {
  // input parameters
  testA group_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  testA trade_input = random_value<testA>();

  // output parameters

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradePendingsFilter_0RQG_callback_ =
      [&](const testA* group, const testA* symbol, const testA* trade) {
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

TEST_F(RpcTestFixture, MtSrvTradePendingsApply_p9q6) {
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
  server->MtSrvTradePendingsApply_p9q6_callback_ =
      [&](const testA* user, const testA* group, const testA* symbol,
          const testA* pending, testA* trade) {
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

TEST_F(RpcTestFixture, MtSrvTradeStopoutsFilter_zpw6) {
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
  server->MtSrvTradeStopoutsFilter_zpw6_callback_ =
      [&](const testA* group, const testA* symbol, const int login,
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

TEST_F(RpcTestFixture, MtSrvTradeStopoutsApply_7mFc) {
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
  server->MtSrvTradeStopoutsApply_7mFc_callback_ =
      [&](const testA* user, const testA* group, const testA* symbol,
          testA* stopout) {
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

TEST_F(RpcTestFixture, MtSrvTradesAddRequest_RkK3) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA request_input = random_value<testA>();
  testA user_input = random_value<testA>();
  testA symbol_input = random_value<testA>();
  const int mode_input = random_value<int>();

  // output parameters
  testA trade_output = random_value<testA>();

  // diy callback
  server->MtSrvTradesAddRequest_RkK3_callback_ =
      [&](testA* trade, const testA* request, const testA* user,
          const testA* symbol, const int mode) {
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

TEST_F(RpcTestFixture, MtSrvTradeTransaction_c7kx) {
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
  server->MtSrvTradeTransaction_c7kx_callback_ = [&](testA* trade, testA* user,
                                                     testA* request_id) {
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

TEST_F(RpcTestFixture, MtSrvTradeCommission_MeFx) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA Sec_input = random_value<testA>();
  testA Grp_input = random_value<testA>();

  // output parameters
  testA trade_output = random_value<testA>();

  // diy callback
  server->MtSrvTradeCommission_MeFx_callback_ =
      [&](testA* trade, const testA* Sec, const testA* Grp) {
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

TEST_F(RpcTestFixture, MtSrvTradeCommissionAgent_YGkX) {
  // input parameters
  testA trade_input = random_value<testA>();
  testA sec_input = random_value<testA>();
  testA info_input = random_value<testA>();

  // output parameters
  testA trade_output = random_value<testA>();

  // return value
  int rpc_result_output = 1;

  // diy callback
  server->MtSrvTradeCommissionAgent_YGkX_callback_ =
      [&](testA* trade, const testA* sec, const testA* info) {
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

TEST_F(RpcTestFixture, MtSrvHistoryTickApply_IbhS) {
  // input parameters
  testA symbol_input = random_value<testA>();
  testA inf_input = random_value<testA>();

  // output parameters
  testA inf_output = random_value<testA>();

  // diy callback
  server->MtSrvHistoryTickApply_IbhS_callback_ = [&](const testA* symbol,
                                                     testA* inf) {
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

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
