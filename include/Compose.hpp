#pragma once

#include "Function.hpp"

#include <memory>


class Compose : public Function {
    std::shared_ptr<Function> externalFunction;
    std::vector<std::shared_ptr<Function>> internalFunctions;

  public:
    Compose(std::shared_ptr<Function> externalFunction,
            std::vector<std::shared_ptr<Function>> internalFunctions);

    uint64_t eval(const std::vector<uint64_t>& args) const override;
};
