#include "Compose.hpp"


Compose::Compose(std::shared_ptr<Function> externalFunction,
                 std::vector<std::shared_ptr<Function>> internalFunctions)
    : Function{internalFunctions.front()->getArity()},
      externalFunction{std::move(externalFunction)},
      internalFunctions{std::move(internalFunctions)} {
}


uint64_t Compose::eval(const std::vector<uint64_t>& args) const {
  std::vector<uint64_t> internalResults;
  internalResults.reserve(getArity());
  for (const auto& internalFunction : internalFunctions) {
    internalResults.push_back(internalFunction->eval(args));
  }
  return externalFunction->eval(internalResults);
}
