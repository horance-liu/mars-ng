#include <mars/core/TestResult.h>
#include <mars/core/internal/TestCaseFunctor.h>
#include <mars/except/AssertionError.h>
#include <algorithm>

template <typename Pred>
inline int TestResult::count(Pred pred) const {
  return std::count_if(failures.begin(), failures.end(), pred);
}

int TestResult::failCount() const {
  return count([](auto& e) {
    return e.isFailure();
  });
}

int TestResult::errorCount() const {
  return count([](auto& e) {
    return e.isError();
  });
}

const std::vector<TestFailure>& TestResult::getFailures() const {
  return failures;
}

namespace {
  struct NilException {
    const char* what() const {
      return "";
    }
  };

  inline std::string msg(const char* why, const char* where, const char* what) {
    return std::string(why) + ' ' + where + '\n' + what;
  }
}

#define ON_FAIL(except)  onFail(msg(except, f.where(), e.what()))
#define ON_ERROR(except) onError(msg(except, f.where(), e.what()))

bool TestResult::protect(const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError& e) {
    ON_FAIL("assertion fail");
  } catch (const std::exception& e) {
    ON_ERROR("uncaught std::exception");
  } catch (...) {
    NilException e;
    ON_ERROR("uncaught unknown exception");
  }
  return false;
}

void TestResult::onFail(std::string&& msg) {
  failures.emplace_back(std::move(msg), true);
}

void TestResult::onError(std::string&& msg) {
  failures.emplace_back(std::move(msg), false);
}
