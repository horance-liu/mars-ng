#include "mars/util/ScopedExit.h"
#include <gtest/gtest.h>
#include <stdio.h>

TEST(ScopedExitSpec, close_file_safely) {
  auto file = std::fopen("~/.bashrc", "r");
  SCOPED_EXIT([file] {
    fclose(file);
  });
}
