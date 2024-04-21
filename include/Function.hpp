#pragma once

#include <cstdint>
#include <vector>


class Function {
    std::size_t arity;

  public:
    Function(std::size_t arity) : arity{arity} {
    }

    virtual ~Function() = default;
    virtual uint64_t eval(const std::vector<uint64_t>& args) const = 0;

    std::size_t getArity() const {
      return arity;
    }
};
