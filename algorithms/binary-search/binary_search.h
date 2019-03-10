#include "absl/types/span.h"
#include "absl/types/optional.h"

namespace algr {
// binary_search finds an item in a span of items of type T using the binary
// search algorithm. Returns the index of the item found in the span, or -1
// if the item is not found in the span.
// Runtime: O(log n)
// Pre-conditions: 
// * The span must be sorted
// * Items in the span must be comparable
template <typename T>
absl::optional<int> binary_search(absl::Span<const T> items, const T& item) {
  int low = 0;
  int high = items.length() - 1;

  while (low <= high) {
    int index = (low + high) / 2;
    const T guess = items[index];
    if (guess == item) return index;
    if (guess > item)
      high = index - 1;
    else
      low = index + 1;
  }

  return absl::nullopt;
}
}  // namespace algr