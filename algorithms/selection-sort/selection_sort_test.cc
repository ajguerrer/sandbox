#include "selection_sort.h"
#include <vector>
#include "absl/types/span.h"
#include "gtest/gtest.h"

namespace algr {
namespace {
TEST(SelectionSortTest, Empty) {
  std::vector<int> empty;
  selection_sort(absl::MakeSpan(empty));
  EXPECT_EQ(std::vector<int>(), empty);
}

TEST(SelectionSortTest, Trivial) {
  std::vector<int> items = {1};
  selection_sort(absl::MakeSpan(items));
  EXPECT_EQ(std::vector<int>({1}), items);
}

TEST(SelectionSortTest, ReverseSorted) {
  std::vector<int> items = {3, 2, 1};
  selection_sort(absl::MakeSpan(items));
  EXPECT_EQ(std::vector<int>({1, 2, 3}), items);
}

TEST(SelectionSortTest, AlreadySorted) {
  std::vector<int> items = {1, 2, 3};
  selection_sort(absl::MakeSpan(items));
  EXPECT_EQ(std::vector<int>({1, 2, 3}), items);
}

TEST(SelectionSortTest, Duplicates) {
  std::vector<int> items = {1, 2, 1, 2};
  selection_sort(absl::MakeSpan(items));
  EXPECT_EQ(std::vector<int>({1, 1, 2, 2}), items);
}

TEST(SelectionSorTest, Example) {
  std::vector<int> items = {5, 3, 6, 2, 10};
  selection_sort(absl::MakeSpan(items));
  EXPECT_EQ(std::vector<int>({2, 3, 5, 6, 10}), items);
}
}  // namespace
}  // namespace algr