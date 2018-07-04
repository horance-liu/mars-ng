#ifndef H997A5C6C_C6D5_4E01_8DD5_8B11D40280AD
#define H997A5C6C_C6D5_4E01_8DD5_8B11D40280AD

#include <vector>
#include "mars/core/Test.h"

struct TestSuite : Test {
  ~TestSuite();
  void add(Test* test);

private:
  void run() override;

private:
  template <typename F>
  void foreach(F f) const;

private:
  std::vector<Test*> tests;
};

#endif
