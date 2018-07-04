#ifndef HF0CC2B6C_307B_4EF3_ACD9_84918773AE38
#define HF0CC2B6C_307B_4EF3_ACD9_84918773AE38

#include <string>

struct TestFailure {
  TestFailure(std::string&& msg, bool failure);

  bool isFailure() const;
  const std::string& getExceptionMsg() const;

private:
  std::string msg;
  bool failure;
};

#endif
