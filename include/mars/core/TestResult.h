#ifndef HA17009C7_C23E_46B4_B0D1_636D7E8D7BBD
#define HA17009C7_C23E_46B4_B0D1_636D7E8D7BBD

#include <vector>
#include <string>

struct TestCaseFunctor;

struct TestResult {
  TestResult();

  int failCount() const;
  int errorCount() const;

  bool protect(const TestCaseFunctor&);

  const std::vector<std::string>& getFailures() const;
  const std::vector<std::string>& getErrors() const;

private:
  void onFail(std::string&& msg);
  void onError(std::string&& msg);

private:
  int numOfFails;
  int numOfErrors;

  std::vector<std::string> failures;
  std::vector<std::string> errors;
};

#endif
