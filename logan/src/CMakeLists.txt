add_library(LogAn logan.cc)

include(GoogleTest)
add_executable(LogAnTest logan_test.cc)
target_link_libraries(LogAnTest PRIVATE LogAn gtest_main)
gtest_discover_tests(LogAnTest)