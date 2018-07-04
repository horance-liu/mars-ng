#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/core/internal/TestCaseFunctor.h"

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
    bool operator()() const override {
      (self->*method)();
      return true;
    }

  private:
    TestCase* self;
    Method method;
  };
}

void TestCase::run(TestResult& result) {
  if (result.protect(Functor(this, &TestCase::setUp))) {
    result.protect(Functor(this, &TestCase::runTest));
  }
  result.protect(Functor(this, &TestCase::tearDown));
}
