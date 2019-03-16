add_library(BinarySearch INTERFACE)

include(GoogleTest)
add_executable(BinarySearchTest binary_search_test.cc)
target_link_libraries(BinarySearchTest PRIVATE absl::base gtest_main)
gtest_discover_tests(BinarySearchTest)