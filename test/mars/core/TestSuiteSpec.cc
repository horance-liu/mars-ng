#include <gtest/gtest.h>
#include "mars/core/TestCase.h"
#include "mars/core/TestSuite.h"
#include "mars/core/TestResult.h"

namespace {
  struct TestSuiteSpec : testing::Test {
    void run(::Test& test) {
      test.run(result);
    }

    int countTestCases(::Test& test) {
      return test.countTestCases();
    }

  protected:
    TestResult result;
  };
}

TEST_F(TestSuiteSpec, run_multi_test_cases_using_test_suite) {
  TestSuite suite;
  suite.add(new TestCase);
  suite.add(new TestCase);

  run(suite);

  ASSERT_EQ(2, countTestCases(suite));
}

TEST_F(TestSuiteSpec, package_sub_test_suite_into_outter_test_suite) {
  auto inner = new TestSuite;
  inner->add(new TestCase);

  TestSuite outter;
  outter.add(new TestCase);
  outter.add(inner);

  run(outter);

  ASSERT_EQ(2, countTestCases(outter));
}

