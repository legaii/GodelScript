#include "Id.hpp"
#include "StringFunctions.hpp"


std::shared_ptr<Function> Id::fromString(const std::string& str) {
  auto substrs = StringFunctions::split(str, '_');
  if (substrs.size() != 2) {
    return {};
  }
  const std::string& left = substrs[0];
  const std::string& right = substrs[1];
  if (left.size() < 2 || left.substr(0, 2) != "id" ||
      !StringFunctions::checkUInt64(left.substr(2)) ||
      !StringFunctions::checkUInt64(right)) {
    return {};
  }
  return std::make_shared<Id>(StringFunctions::toUInt64(left.substr(2)) - 1,
                              StringFunctions::toUInt64(right));
}
