#ifndef H586108AA_CD7B_459D_8A2F_0DFE6C9720ED
#define H586108AA_CD7B_459D_8A2F_0DFE6C9720ED

struct TestCase {
  virtual ~TestCase() {}
  virtual void run() = 0;
};

#endif
