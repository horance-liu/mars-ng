FILE(GLOB_RECURSE all_files *.cc)
add_library(mars STATIC ${all_files})