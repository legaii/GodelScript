#pragma once

#include "Function.hpp"

#include <istream>
#include <map>
#include <memory>


class Namespace {
    std::map<std::string, std::shared_ptr<Function>> namedFunctions;

  public:
    void readFrom(std::istream& input);
    std::shared_ptr<Function> getNamedFunction(const std::string& name) const;
};
