#ifndef H997A5C6C_C6D5_4E01_8DD5_8B11D40280AD
#define H997A5C6C_C6D5_4E01_8DD5_8B11D40280AD

#include <vector>

struct TestCase;

struct TestSuite {
  ~TestSuite();

  void add(TestCase* test);
  void run();

private:
  std::vector<TestCase*> tests;
};

#endif
