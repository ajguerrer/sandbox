add_library(SelectionSort INTERFACE)

include(GoogleTest)
add_executable(SelectionSortTest selection_sort_test.cc)
target_link_libraries(SelectionSortTest PRIVATE absl::base gtest_main)
gtest_discover_tests(SelectionSortTest)