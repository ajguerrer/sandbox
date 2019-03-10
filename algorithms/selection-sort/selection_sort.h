#include <algorithm>
#include "absl/types/span.h"

namespace algr {
template <typename T>
void selection_sort(absl::Span<T> items) {
  for (auto i = items.begin(); i != items.end(); i++) {
    std::iter_swap(i, std::min_element(i, items.end()));
  }
}
}  // namespace algr