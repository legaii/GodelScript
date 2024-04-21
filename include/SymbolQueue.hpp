#pragma once

#include <istream>
#include <queue>


class SymbolQueue : public std::queue<std::string> {
    std::string currentSymbol;
    bool isComment = false;

    void finishCurrentSymbol();

  public:
    void readFrom(std::istream& input);
};
