#pragma once

#include "Function.hpp"


class Succ : public Function {
  public:
    Succ() : Function{1} {
    }

    uint64_t eval(const std::vector<uint64_t>& args) const override {
      return args.front() + 1;
    }
};
