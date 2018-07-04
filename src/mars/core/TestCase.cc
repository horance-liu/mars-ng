#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/except/AssertionError.h"

int TestCase::countTestCases() const {
  return 1;
}

bool TestCase::protect(TestResult& result, Method method) {
  bool succ = false;
  try {
    (this->*method)();
    succ = true;
  } catch (const AssertionError&) {
    result.onFail();
  } catch (const std::exception&) {
    result.onError();
  } catch (...) {
    result.onError();
  }
  return succ;
}

void TestCase::run(TestResult& result) {
  if (protect(result, &TestCase::setUp)) {
    protect(result, &TestCase::runTest);
  }
  protect(result, &TestCase::tearDown);
}
