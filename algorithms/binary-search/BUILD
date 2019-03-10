cc_library(
    name = "binary_search",
    hdrs = ["binary_search.h"],
    deps = [
      "@absl//absl/types:span",
      "@absl//absl/types:optional",     
    ],
)

cc_test(
    name = "binary_search_test",
    srcs = ["binary_search_test.cc"],
    deps = [
        ":binary_search",
        "@gtest//:gtest_main",
    ],
)
