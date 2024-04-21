#include "Constant.hpp"
#include "StringFunctions.hpp"


std::shared_ptr<Function> Constant::fromString(const std::string& str) {
  auto substrs = StringFunctions::split(str, '_');
  if (substrs.size() != 2) {
    return {};
  }
  const std::string& left = substrs[0];
  const std::string& right = substrs[1];
  if (!StringFunctions::checkUInt64(left) || !StringFunctions::checkUInt64(right)) {
    return {};
  }
  return std::make_shared<Constant>(StringFunctions::toUInt64(left),
                                    StringFunctions::toUInt64(right));
}
