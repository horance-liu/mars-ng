#ifndef H1DD5DED6_6EC7_4C5C_A27F_063CFDA78F84
#define H1DD5DED6_6EC7_4C5C_A27F_063CFDA78F84

#include <string>

struct Test {
  explicit Test(const std::string& name = "");
  const std::string& getName() const;

  virtual ~Test() {}
  virtual void run() = 0;

private:
  std::string name;
};

#endif
