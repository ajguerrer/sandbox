cc_library(
    name = "selection_sort",
    hdrs = ["selection_sort.h"],
    deps = [
        "@absl//absl/types:span"
    ]
)

cc_test(
    name = "selection_sort_test",
    srcs = ["selection_sort_test.cc"],
    deps = [
        ":selection_sort",
        "@gtest//:gtest_main",
    ],
)
