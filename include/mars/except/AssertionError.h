#ifndef HDFEBB6EF_E8DA_4A19_B777_14C1F09E522C
#define HDFEBB6EF_E8DA_4A19_B777_14C1F09E522C

#include <string>
#include <exception>

struct AssertionError : std::exception {
  AssertionError(const std::string& src, const std::string& msg);
  ~AssertionError() noexcept = default;

  const char* what() const noexcept;

private:
  std::string msg;
};

#endif
