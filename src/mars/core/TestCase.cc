#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"

int TestCase::countTestCases() const {
  return 1;
}

void TestCase::run(TestResult& result) {
  setUp();
  runTest();
  tearDown();
}
