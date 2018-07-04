#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/internal/TestCaseFunctor.h"
#include "mars/except/AssertionError.h"

int TestCase::countTestCases() const {
  return 1;
}

namespace {
  struct Functor : TestCaseFunctor {
    using Method = void(TestCase::*)();

    Functor(TestCase* self, Method method)
      : self(self), method(method) {
    }

  private:
    const std::string& getTestName() const override {
      return self->getName();
    }

    bool operator()() const override {
      (self->*method)();
      return true;
    }

  private:
    TestCase* self;
    Method method;
  };
}

bool TestCase::protect(TestResult& result, const TestCaseFunctor& f) {
  try {
    return f();
  } catch (const AssertionError&) {
    result.onFail();
  } catch (const std::exception&) {
    result.onError();
  } catch (...) {
    result.onError();
  }
  return false;
}

void TestCase::run(TestResult& result) {
  if (protect(result, Functor(this, &TestCase::setUp))) {
    protect(result, Functor(this, &TestCase::runTest));
  }
  protect(result, Functor(this, &TestCase::tearDown));
}
