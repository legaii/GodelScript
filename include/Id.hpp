#pragma once

#include "Function.hpp"

#include <memory>


class Id : public Function {
    std::size_t index;

  public:
    Id(std::size_t index, std::size_t arity) : Function{arity}, index{index} {
    }

    uint64_t eval(const std::vector<uint64_t>& args) const override {
      return args[index];
    }

    static std::shared_ptr<Function> fromString(const std::string& str);
};
