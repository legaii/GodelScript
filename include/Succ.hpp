#pragma once

#include "Function.hpp"

#include <memory>
#include <string>


class Succ : public Function {
  public:
    Succ() : Function{1} {
    }

    uint64_t eval(const std::vector<uint64_t>& args) const override {
      return args.front() + 1;
    }

    static std::shared_ptr<Function> fromString(const std::string& str);
};
