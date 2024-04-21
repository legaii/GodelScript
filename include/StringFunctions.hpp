#pragma once

#include <string>
#include <vector>


namespace StringFunctions {
std::vector<std::string> split(const std::string& str, char delimiter);
bool checkUInt64(const std::string& str);
uint64_t toUInt64(const std::string& str);
}  // namespace StringFunctions
