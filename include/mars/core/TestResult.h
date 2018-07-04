#ifndef HA17009C7_C23E_46B4_B0D1_636D7E8D7BBD
#define HA17009C7_C23E_46B4_B0D1_636D7E8D7BBD

struct TestResult {
  TestResult();

  int failCount() const;
  int errorCount() const;

  void onFail();
  void onError();

private:
  int numOfFails;
  int numOfErrors;
};

#endif
