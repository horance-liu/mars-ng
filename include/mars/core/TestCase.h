#ifndef H586108AA_CD7B_459D_8A2F_0DFE6C9720ED
#define H586108AA_CD7B_459D_8A2F_0DFE6C9720ED

#include "mars/core/Test.h"

struct TestCase : Test {
  using Test::Test;

private:
  int countTestCases() const override;
  void run(TestResult&) override;

private:
  virtual void setUp() {}
  virtual void runTest() {}
  virtual void tearDown() {}
};

#endif
