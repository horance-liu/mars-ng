#include "mars/core/TestSuite.h"
#include "mars/core/TestCase.h"

TestSuite::TestSuite(const std::string& name) : name(name) {
}

const std::string& TestSuite::getName() const {
  return name;
}

void TestSuite::add(Test* test) {
  tests.push_back(test);
}

template <typename F>
inline void TestSuite::foreach(F f) const {
  for (auto test : tests) {
    f(test);
  }
}

TestSuite::~TestSuite() {
  foreach([](auto test) {
    delete test;
  });
}

void TestSuite::run() {
  foreach([](auto test) {
    test->run();
  });
}
