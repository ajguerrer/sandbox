#include "binary_search.h"
#include <vector>
#include "absl/types/span.h"
#include "gtest/gtest.h"

namespace algr {
namespace {
TEST(BinarySearchTest, Empty) {
  std::vector<int> empty;
  EXPECT_FALSE(binary_search(absl::MakeConstSpan(empty), 1));
}

TEST(BinarySearchTest, Simple) { EXPECT_EQ(0, binary_search({1}, 1)); }

TEST(BinarySeachTest, NotFound) { EXPECT_FALSE(binary_search({1, 3}, 2)); }

TEST(BinarySearchTest, OnTheEdge) {
  EXPECT_EQ(0, binary_search({0, 1, 2, 3}, 0));
  EXPECT_EQ(3, binary_search({0, 1, 2, 3}, 3));
}

TEST(BinarySearchTest, OffTheEdge) {
  EXPECT_FALSE(binary_search({0, 1, 2, 3}, -1));
  EXPECT_FALSE(binary_search({0, 1, 2, 3}, 4));
}
}  // namespace
}  // namespace algr