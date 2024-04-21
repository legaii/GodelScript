#pragma once

#include "Function.hpp"

#include <memory>


class Constant : public Function {
    const uint64_t value;

  public:
    Constant(uint64_t value, std::size_t arity) : Function{arity}, value{value} {
    }

    uint64_t eval(const std::vector<uint64_t>&) const override {
      return value;
    }

    static std::shared_ptr<Function> fromString(const std::string& str);
};
