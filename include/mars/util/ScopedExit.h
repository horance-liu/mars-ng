#ifndef H89840DA4_E6EB_42F5_8A33_BD9F32529AE6
#define H89840DA4_E6EB_42F5_8A33_BD9F32529AE6

#include "mars/util/Symbol.h"

template <typename F>
struct ScopedExit {
  ScopedExit(F f) : f(f) {
  }

  ~ScopedExit(){
    f();
  }

private:
  F f;
};

template <typename F>
ScopedExit<F> makeScopedExit(F f) {
  return ScopedExit<F>(f);
};

#define SCOPED_EXIT(code) \
    auto UNIQUE_NAME(scope_exit) = makeScopedExit(code)

#endif
