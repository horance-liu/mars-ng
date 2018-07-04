#include "mars/core/TestResult.h"

TestResult::TestResult() : numOfRuns(0) {
}

void TestResult::onRun() {
  numOfRuns++;
}

int TestResult::runCount() const {
  return numOfRuns;
}
