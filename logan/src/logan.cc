#include "logan.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>

bool LogAnalyzer::IsValidLogFileName(const std::string& fileName) {
  if (fileName.empty()) {
    throw std::invalid_argument("Filename cannot be empty");
  }

  if (!EndsWith(fileName, ".SLF")) {
    return false;
  }

  return true;
}

bool LogAnalyzer::EndsWith(const std::string& fileName,
                           const std::string& suffix) {
  return std::equal(suffix.rbegin(), suffix.rend(), fileName.rbegin(),
                    [](const char a, const char b) {
                      return std::tolower(a) == std::tolower(b);
                    });
}