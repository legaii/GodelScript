#include "SymbolQueue.hpp"


void SymbolQueue::finishCurrentSymbol() {
  if (!currentSymbol.empty()) {
    push(currentSymbol);
    currentSymbol.clear();
  }
}


void SymbolQueue::readFrom(std::istream& input) {
  for (char c; input.get(c);) {
    if (isComment) {
      if (c == '\n') {
        isComment = false;
      }
      continue;
    }
    if (c == '#') {
      finishCurrentSymbol();
      isComment = true;
      continue;
    }
    if (std::isspace(static_cast<unsigned char>(c))) {
      finishCurrentSymbol();
      continue;
    }
    if (c == '(' || c == ')') {
      finishCurrentSymbol();
      currentSymbol.push_back(c);
      finishCurrentSymbol();
    } else {
      currentSymbol.push_back(c);
    }
  }
  finishCurrentSymbol();
}
