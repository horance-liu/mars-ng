#ifndef H997A5C6C_C6D5_4E01_8DD5_8B11D40280AD
#define H997A5C6C_C6D5_4E01_8DD5_8B11D40280AD

#include <mars/core/Test.h>
#include <vector>

struct TestSuite : Test {
  using Test::Test;
  ~TestSuite() override;

  void add(Test* test);

private:
  int countTestCases() const override;
  void run(TestResult&) override;

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::vector<Test*> tests;
};

#endif
