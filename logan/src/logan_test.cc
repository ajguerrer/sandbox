#include "logan.h"
#include "gtest/gtest.h"
#include <stdexcept>

namespace {
TEST(LogAnTest, WrongExtensionIsInvalid) {
  LogAnalyzer analyzer;
  bool result = analyzer.IsValidLogFileName("filewithbadextension.foo");
  ASSERT_FALSE(result);
}

TEST(LogAnTest, LowercaseExtensionIsValid) {
  LogAnalyzer analyzer;
  bool result = analyzer.IsValidLogFileName("filewithgoodextension.slf");
  ASSERT_TRUE(result);
}

TEST(LogAnTest, UppercaseExtensionIsValid) {
  LogAnalyzer analyzer;
  bool result = analyzer.IsValidLogFileName("filewithgoodextension.SLF");
  ASSERT_TRUE(result);
}

TEST(LogAnTest, EmptyFilenameThrowsInvalidArgument) {
  LogAnalyzer analyzer;
  EXPECT_THROW(analyzer.IsValidLogFileName(""), std::invalid_argument);
}
}  // namespace