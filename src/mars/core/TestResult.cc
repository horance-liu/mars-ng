#include <mars/core/TestResult.h>
#include <mars/core/internal/TestCaseFunctor.h>
#include <mars/except/AssertionError.h>


TestResult::TestResult()
  : numOfFails(0), numOfErrors(0) {
}

int TestResult::failCount() const {
  return numOfFails;
}

int TestResult::errorCount() const {
  return numOfErrors;
}

const std::vector<TestFailure>& TestResult::getFailures() const {
  return failures;
}

namespace {
  std::string msg(const char* why, const char* where, const char* what = "") {
    return std::string(why) + ' ' + where + '\n' + what;
  }
}

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError& e) {
    onFail(msg("assertion fail", f.where(), e.what()));
  } catch (const std::exception& e) {
    onError(msg("uncaught std::exception", f.where(), e.what()));
  } catch (...) {
    onError(msg("uncaught unknown exception", f.where()));
  }
  return false;
}

void TestResult::onFail(std::string&& msg) {
  failures.emplace_back(std::move(msg), true);
  numOfFails++;
}

void TestResult::onError(std::string&& msg) {
  failures.emplace_back(std::move(msg), false);
  numOfErrors++;
}
