#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"

void TestCase::runBare() {
  setUp();
  runTest();
  tearDown();
}

void TestCase::run(TestResult& result) {
  result.onRun();
  runBare();
}
