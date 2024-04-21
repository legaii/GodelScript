#include "StringFunctions.hpp"


std::vector<std::string> StringFunctions::split(const std::string& str, char delimiter) {
  std::vector<std::string> substrs;
  substrs.emplace_back();
  for (const char& c : str) {
    if (c == delimiter) {
      substrs.emplace_back();
    } else {
      substrs.back().push_back(c);
    }
  }
  return substrs;
}


bool StringFunctions::checkUInt64(const std::string& str) {
  for (const char& c : str) {
    if (!('0' <= c && c <= '9')) {
      return false;
    }
  }
  return true;
}


uint64_t StringFunctions::toUInt64(const std::string& str) {
  uint64_t num = 0;
  for (const char& c : str) {
    num *= 10;
    num += c - '0';
  }
  return num;
}
