#include "Expression.hpp"
#include "Compose.hpp"
#include "Constant.hpp"
#include "Id.hpp"
#include "Min.hpp"
#include "Recur.hpp"
#include "Succ.hpp"


Expression::Expression(std::vector<Expression> children, std::string name)
    : children{std::move(children)}, name{std::move(name)} {
}


std::string Expression::getName() const {
  return name;
}


Expression Expression::readFrom(SymbolQueue& symbols) {
  Expression expression;
  if (symbols.front() != "(") {
    expression.name = std::move(symbols.front());
    symbols.pop();
    return expression;
  }
  symbols.pop();
  while (symbols.front() != ")") {
    expression.children.push_back(readFrom(symbols));
  }
  symbols.pop();
  return expression;
}


std::shared_ptr<Function> Expression::parse(const Namespace& names) const {
  if (!name.empty()) {
    if (auto func = Constant::fromString(name); func) {
      return func;
    } else if (auto func = Succ::fromString(name); func) {
      return func;
    } else if (auto func = Id::fromString(name); func) {
      return func;
    } else {
      return names.getNamedFunction(name);
    }
  }
  const std::string& operatorName = children.front().getName();
  std::vector<std::shared_ptr<Function>> operands;
  operands.reserve(children.size() - 1);
  for (std::size_t i = 1; i < children.size(); ++i) {
    operands.push_back(children[i].parse(names));
  }
  if (operatorName == "Compose") {
    std::shared_ptr<Function> externalFunction = std::move(operands.front());
    operands.erase(operands.begin());
    return std::make_shared<Compose>(std::move(externalFunction), std::move(operands));
  } else if (operatorName == "Recur") {
    return std::make_shared<Recur>(std::move(operands.front()),
                                   std::move(operands.back()));
  } else if (operatorName == "Min") {
    return std::make_shared<Min>(std::move(operands.front()));
  } else {
    return {};
  }
}
