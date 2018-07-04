#include "mars/core/TestResult.h"

TestResult::TestResult()
  : numOfFails(0), numOfErrors(0) {
}

int TestResult::failCount() const {
  return numOfFails;
}

int TestResult::errorCount() const {
  return numOfErrors;
}

void TestResult::onFail() {
  numOfFails++;
}

void TestResult::onError() {
  numOfErrors++;
}
