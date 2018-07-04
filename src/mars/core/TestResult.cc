#include "mars/core/TestResult.h"
#include "mars/core/internal/TestCaseFunctor.h"
#include "mars/except/AssertionError.h"

TestResult::TestResult()
  : numOfFails(0), numOfErrors(0) {
}

int TestResult::failCount() const {
  return numOfFails;
}

int TestResult::errorCount() const {
  return numOfErrors;
}

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError& e) {
    onFail();
  } catch (const std::exception& e) {
    onError();
  } catch (...) {
    onError();
  }
  return false;
}

void TestResult::onFail() {
  numOfFails++;
}

void TestResult::onError() {
  numOfErrors++;
}
