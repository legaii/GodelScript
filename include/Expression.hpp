#pragma once

#include "Namespace.hpp"
#include "SymbolQueue.hpp"


class Expression {
    std::vector<Expression> children;
    std::string name;

    Expression() = default;
    Expression(std::vector<Expression> children, std::string name);

  public:
    std::string getName() const;

    static Expression readFrom(SymbolQueue& symbols);

    std::shared_ptr<Function> parse(const Namespace& names) const;
};
