#pragma once

#include "Function.hpp"

#include <istream>
#include <memory>


class Namespace {
  public:
    void readFrom(std::istream& input);
    std::shared_ptr<Function> getNamedFunction(const std::string& name) const;
};
