#pragma once

class hooks_rpc_interface {
 public:
  virtual void MtSrvAbout_Rpc(testA* info) = 0;
  virtual int MtSrvStartup_Rpc() = 0;
  virtual void MtSrvCleanup_Rpc() = 0;
  virtual int MtSrvPluginCfgAdd_Rpc(const testA* cfg) = 0;
  virtual int MtSrvPluginCfgSet_Rpc(const testA* values, const int total) = 0;
  virtual int MtSrvPluginCfgDelete_Rpc(LPCSTR name) = 0;
  virtual int MtSrvPluginCfgGet_Rpc(LPCSTR name, testA* cfg) = 0;
  virtual int MtSrvPluginCfgNext_Rpc(const int index, testA* cfg) = 0;
  virtual int MtSrvPluginCfgTotal_Rpc() = 0;
  virtual void MtSrvTradeRequestApply_Rpc(testA* request, const int isdemo) = 0;
  virtual int MtSrvTradeStopsFilter_Rpc(const testA* group, const testA* symbol,
                                        const testA* trade) = 0;
  virtual int MtSrvTradeStopsApply_Rpc(const testA* user, const testA* group,
                                       const testA* symbol, testA* trade,
                                       const int isTP) = 0;
  virtual int MtSrvTradePendingsFilter_Rpc(const testA* group,
                                           const testA* symbol,
                                           const testA* trade) = 0;
  virtual int MtSrvTradePendingsApply_Rpc(const testA* user, const testA* group,
                                          const testA* symbol,
                                          const testA* pending,
                                          testA* trade) = 0;
  virtual int MtSrvTradeStopoutsFilter_Rpc(const testA* group,
                                           const testA* symbol, const int login,
                                           const double equity,
                                           const double margin) = 0;
  virtual int MtSrvTradeStopoutsApply_Rpc(const testA* user, const testA* group,
                                          const testA* symbol,
                                          testA* stopout) = 0;
  virtual void MtSrvTradesAddRequest_Rpc(testA* trade, const testA* request,
                                         const testA* user, const testA* symbol,
                                         const int mode) = 0;
  virtual int MtSrvTradeTransaction_Rpc(testA* trade, testA* user,
                                        testA* request_id) = 0;
  virtual void MtSrvTradeCommission_Rpc(testA* trade, const testA* Sec,
                                        const testA* Grp) = 0;
  virtual int MtSrvTradeCommissionAgent_Rpc(testA* trade, const testA* sec,
                                            const testA* info) = 0;
  virtual void MtSrvHistoryTickApply_Rpc(const testA* symbol, testA* inf) = 0;
};
