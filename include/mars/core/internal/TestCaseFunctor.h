#ifndef H1B8199D4_5320_41E7_94AF_4A23EDE5A01F
#define H1B8199D4_5320_41E7_94AF_4A23EDE5A01F

struct TestCaseFunctor {
  virtual ~TestCaseFunctor() {}
  virtual const char* where() const = 0;
  virtual bool operator()() const = 0;
};

#endif
