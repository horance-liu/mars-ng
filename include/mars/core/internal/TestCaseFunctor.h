#ifndef H1B8199D4_5320_41E7_94AF_4A23EDE5A01F
#define H1B8199D4_5320_41E7_94AF_4A23EDE5A01F

#include <string>

struct TestCaseFunctor {
  virtual ~TestCaseFunctor() {}
  virtual bool operator()() const = 0;
};

#endif
