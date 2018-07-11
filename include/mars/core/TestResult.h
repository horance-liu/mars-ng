#ifndef HA17009C7_C23E_46B4_B0D1_636D7E8D7BBD
#define HA17009C7_C23E_46B4_B0D1_636D7E8D7BBD

#include <mars/except/TestFailure.h>
#include <string>
#include <vector>

struct TestCaseFunctor;

struct TestResult {
  int failCount() const;
  int errorCount() const;

  const std::vector<TestFailure>& getFailures() const;

  bool protect(const TestCaseFunctor&);

private:
  void onFail(std::string&&);
  void onError(std::string&&);

  template <typename Pred>
  int count(Pred) const;

private:
  std::vector<TestFailure> failures;
};

#endif
