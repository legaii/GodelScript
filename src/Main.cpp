#include "Namespace.hpp"

#include <fstream>
#include <iostream>


std::shared_ptr<Function> getMainFunction(const std::string fileName) {
  std::ifstream file{fileName};
  Namespace mainSpace;
  mainSpace.readFrom(file);
  return mainSpace.getNamedFunction("main");
}


std::vector<uint64_t> readArgs(std::size_t count) {
  std::vector<uint64_t> args;
  args.reserve(count);
  while (count--) {
    args.emplace_back();
    std::cin >> args.back();
  }
  return args;
}


int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Syntax: godel file" << std::endl;
    return 1;
  }
  auto mainFunction = getMainFunction(argv[1]);
  if (!mainFunction) {
    std::cerr << "Error: main function does not exist" << std::endl;
    return 1;
  }
  auto args = readArgs(mainFunction->getArity());
  std::cout << mainFunction->eval(args) << std::endl;
  return 0;
}
