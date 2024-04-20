#pragma once

#include "Function.hpp"


class Constant : public Function {
    const uint64_t value;

  public:
    Constant(uint64_t value, std::size_t arity) : Function{arity}, value{value} {
    }

    uint64_t eval(const std::vector<uint64_t>& args) const override {
      return value;
    }
}
