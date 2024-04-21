#include "Succ.hpp"


std::shared_ptr<Function> Succ::fromString(const std::string& str) {
  return str == "succ" ? std::make_shared<Succ>() : nullptr;
}
