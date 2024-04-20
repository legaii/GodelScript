#pragma once

#include "Function.hpp"

#include <memory>


class Recur : public Function {
    std::shared_ptr<Function> baseFunction;
    std::shared_ptr<Function> stepFunction;

  public:
    Recur(std::shared_ptr<Function> baseFunction, std::shared_ptr<Function> stepFunction);

    uint64_t eval(const std::vector<uint64_t>& args) const override;
};
