#include "mars/core/TestResult.h"

TestResult::TestResult() : numOfFails(0) {
}

int TestResult::failCount() const {
  return numOfFails;
}

void TestResult::onFail() {
  numOfFails++;
}
