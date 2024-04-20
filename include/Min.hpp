#pragma once

#include "Function.hpp"

#include <memory>


class Min : public Function {
    std::shared_ptr<Function> function;

  public:
    Min(std::shared_ptr<Function> function);

    uint64_t eval(const std::vector<uint64_t>& args) const override;
};
