#include "mars/core/TestResult.h"
#include "mars/core/internal/TestCaseFunctor.h"
#include "mars/except/AssertionError.h"

TestResult::TestResult()
  : numOfFails(0), numOfErrors(0) {
}

TestResult::~TestResult() {
  for (auto f : failures) {
    delete f;
  }
}


int TestResult::failCount() const {
  return numOfFails;
}

int TestResult::errorCount() const {
  return numOfErrors;
}

const std::vector<TestFailure*>& TestResult::getFailures() const {
  return failures;
}

const std::vector<std::string>& TestResult::getErrors() const {
  return errors;
}

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError& e) {
    onFail(std::string("assertion fail") + " " + f.where() + "\n" + e.what());
  } catch (const std::exception& e) {
    onError(std::string("uncaught std::exception") + " " + f.where() + "\n" + e.what());
  } catch (...) {
    onError(std::string("uncaught unknown exception") + " " + f.where() + "\n" + "");
  }
  return false;
}

void TestResult::onFail(std::string&& msg) {
  failures.push_back(new TestFailure(std::move(msg), true));
  numOfFails++;
}

void TestResult::onError(std::string&& msg) {
  errors.emplace_back(std::move(msg));
  numOfErrors++;
}
