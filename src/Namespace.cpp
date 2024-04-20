#include "Namespace.hpp"

#include <iostream>  //TODO


void Namespace::readFrom(std::istream& input) {
  for (std::string s; std::getline(input, s);) {
    std::cout << "$: " << s << std::endl;
  }
}


std::shared_ptr<Function> Namespace::getNamedFunction(const std::string& name) const {
  return nullptr;
}
