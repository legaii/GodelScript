#include "Namespace.hpp"
#include "Expression.hpp"
#include "SymbolQueue.hpp"


void Namespace::readFrom(std::istream& input) {
  SymbolQueue symbols;
  symbols.readFrom(input);
  while (!symbols.empty()) {
    std::string newName = Expression::readFrom(symbols).getName();
    Expression::readFrom(symbols);
    namedFunctions[newName] = Expression::readFrom(symbols).parse(*this);
  }
}


std::shared_ptr<Function> Namespace::getNamedFunction(const std::string& name) const {
  auto iter = namedFunctions.find(name);
  return iter == namedFunctions.end() ? nullptr : iter->second;
}
