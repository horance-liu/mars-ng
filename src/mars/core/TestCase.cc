#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/except/AssertionError.h"

int TestCase::countTestCases() const {
  return 1;
}

void TestCase::run(TestResult& result) {
  bool succ = false;
  try {
    setUp();
    succ = true;
  } catch (const AssertionError&) {
    result.onFail();
  } catch (const std::exception&) {
    result.onError();
  }

  if (succ) {
    try {
      runTest();
    } catch (const AssertionError&) {
      result.onFail();
    } catch (const std::exception&) {
      result.onError();
    } catch (...) {
      result.onError();
    }
  }

  try {
    tearDown();
  } catch (const AssertionError&) {
    result.onFail();
  }
}
