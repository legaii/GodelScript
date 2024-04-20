#include "Recur.hpp"


Recur::Recur(std::shared_ptr<Function> baseFunction,
             std::shared_ptr<Function> stepFunction)
    : Function{baseFunction->getArity() + 1},
      baseFunction{std::move(baseFunction)},
      stepFunction{std::move(stepFunction)} {
}


uint64_t Recur::eval(const std::vector<uint64_t>& args) const {
  auto newArgs = args;
  if (args.front() == 0) {
    newArgs.erase(newArgs.begin());
    return baseFunction->eval(newArgs);
  } else {
    --newArgs.front();
    newArgs.insert(newArgs.begin(), eval(newArgs));
    return stepFunction->eval(newArgs);
  }
}
