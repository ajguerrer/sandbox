#include "binary_search.h"
#include "gtest/gtest.h"
#include <vector>

namespace algr {
  namespace {
    TEST(BinarySearchTest, Empty) {
      EXPECT_FALSE(binary_search(absl::Span<const int>({}), 1));
    }
    
    TEST(BinarySearchTest, Simple) {
      EXPECT_EQ(0, binary_search(absl::Span<const int>({1}), 1));
    }

    TEST(BinarySeachTest, NotFound) {
      EXPECT_FALSE(binary_search(absl::Span<const int>({1, 3}), 2));
    }

    TEST(BinarySearchTest, OnTheEdge) {
      std::vector<int> v = {0, 1, 2, 3};
      EXPECT_EQ(0, binary_search(absl::Span<const int>(v), 0));
      EXPECT_EQ(3, binary_search(absl::Span<const int>(v), 3));
    }

    TEST(BinarySearchTest, OffTheEdge) {
      std::vector<int> v = {0, 1, 2, 3};
      EXPECT_FALSE(binary_search(absl::Span<const int>(v), -1));
      EXPECT_FALSE(binary_search(absl::Span<const int>(v), 4));
    }
  }
}