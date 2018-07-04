#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestResult.h"
#include "mars/except/AssertionError.h"

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

