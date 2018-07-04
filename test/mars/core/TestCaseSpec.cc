#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/except/AssertionError.h"
#include "mars/except/TestFailure.h"

namespace {
  void assertName(const Test& test, const char* expected) {
    ASSERT_EQ(std::string(expected), test.getName());
  }
}

TEST(NamedTestCase, named_test_case) {
  assertName(TestCase("test case1"), "test case1");
}

namespace {
  struct TestCaseSpec : testing::Test {
  protected:
    void run(::Test& test) {
      test.run(result);
    }

  protected:
    TestResult result;
  };
}


namespace {
  struct AssertionFailedTest : TestCase {
    const char* expectMsg() const {
      return "assertion fail in the runTest\n"
              "test.cpp:57\n"
              "expected value == 2, but got 3";
    }

  private:
    void runTest() override {
      throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_run_test) {
  AssertionFailedTest test;
  run(test);

  ASSERT_EQ(1, result.failCount());
}

TEST_F(TestCaseSpec, cache_failure_if_throw_assertion_error_on_run_test) {
  AssertionFailedTest test;
  run(test);

  auto& failures = result.getFailures();
  ASSERT_FALSE(failures.empty());

  auto& failure = failures.front();
  ASSERT_TRUE(failure.isFailure());
  ASSERT_EQ(test.expectMsg(), failure.getExceptionMsg());
}

namespace {
  struct AssertionFailedOnSetUpTest : TestCase {
    bool wasRun = false;

  private:
    void setUp() override {
      throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
    }

    void runTest() override {
      wasRun = true;
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_setup) {
  AssertionFailedOnSetUpTest test;
  run(test);

  ASSERT_EQ(1, result.failCount());
  ASSERT_FALSE(test.wasRun);
}

namespace {
  struct AssertionFailedOnTearDownTest : TestCase {
    void tearDown() override {
      throw AssertionError("test.cpp:57", "expected value == 2, but got 3");
    }
  };
}

TEST_F(TestCaseSpec, throw_assertion_error_on_tear_down) {
  AssertionFailedOnTearDownTest test;
  run(test);

  ASSERT_EQ(1, result.failCount());
}

namespace {
  struct StdExceptionTest : TestCase {
    const char* expectMsg() const {
      return "uncaught std::exception in the runTest\n"
              "std::exception";
    }

  private:
    void runTest() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_run_test) {
  StdExceptionTest test;
  run(test);

  ASSERT_EQ(0, result.failCount());
  ASSERT_EQ(1, result.errorCount());
}

TEST_F(TestCaseSpec, cache_error_if_throw_std_exception_on_run_test) {
  StdExceptionTest test;
  run(test);

  auto& errors = result.getFailures();
  ASSERT_FALSE(errors.empty());

  auto& error = errors.front();
  ASSERT_TRUE(error.isError());
  ASSERT_EQ(test.expectMsg(), error.getExceptionMsg());
}

namespace {
  struct StdExceptionOnSetUpTest : TestCase {
    void setUp() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_setup) {
  StdExceptionOnSetUpTest test;
  run(test);

  ASSERT_EQ(0, result.failCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct StdExceptionOnTearDownTest : TestCase {
    void tearDown() override {
      throw std::exception();
    }
  };
}

TEST_F(TestCaseSpec, throw_std_exception_on_tear_down) {
  StdExceptionOnTearDownTest test;
  run(test);

  ASSERT_EQ(0, result.failCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct UnknownException {};

  struct UnknownExceptionTest : TestCase {
    const char* expectMsg() const {
      return "uncaught unknown exception in the runTest\n";
    }

  private:
    void runTest() override {
      throw UnknownException();
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_run_test) {
  UnknownExceptionTest test;
  run(test);

  ASSERT_EQ(0, result.failCount());
  ASSERT_EQ(1, result.errorCount());
}

TEST_F(TestCaseSpec, cache_error_if_throw_unknown_exception_on_run_test) {
  UnknownExceptionTest test;
  run(test);

  auto& errors = result.getFailures();
  ASSERT_FALSE(errors.empty());

  auto& error = errors.front();
  ASSERT_TRUE(error.isError());
  ASSERT_EQ(test.expectMsg(), error.getExceptionMsg());
}

namespace {
  struct UnknownExceptionOnSetUpTest : TestCase {
    void setUp() override {
      throw UnknownException();
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_setup) {
  UnknownExceptionOnSetUpTest test;
  run(test);

  ASSERT_EQ(0, result.failCount());
  ASSERT_EQ(1, result.errorCount());
}

namespace {
  struct UnknownExceptionOnTearDownTest : TestCase {
    void tearDown() override {
      throw UnknownException();
    }
  };
}

TEST_F(TestCaseSpec, throw_unknown_exception_on_tear_down) {
  UnknownExceptionOnTearDownTest test;
  run(test);

  ASSERT_EQ(0, result.failCount());
  ASSERT_EQ(1, result.errorCount());
}

