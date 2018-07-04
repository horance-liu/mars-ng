#ifndef H1DD5DED6_6EC7_4C5C_A27F_063CFDA78F84
#define H1DD5DED6_6EC7_4C5C_A27F_063CFDA78F84

#include <string>

struct Test {
  virtual ~Test() {}
  virtual const std::string& getName() const = 0;
  virtual void run() = 0;
};

#endif
