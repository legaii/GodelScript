#include "Min.hpp"


Min::Min(std::shared_ptr<Function> function)
    : Function{function->getArity() - 1}, function{std::move(function)} {
}


uint64_t Min::eval(const std::vector<uint64_t>& args) const {
  auto newArgs = args;
  newArgs.insert(newArgs.begin(), 0);
  while (function->eval(newArgs) > 0) {
    ++newArgs.front();
  }
  return newArgs.front();
}
