#pragma once

#include <string>

class LogAnalyzer {
 public:
  bool IsValidLogFileName(const std::string& fileName);

 private:
  bool EndsWith(const std::string& fileName, const std::string& suffix);
};