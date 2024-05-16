#include <gtest/gtest.h>
#include "SymbolQueue.hpp"


TEST(SymbolQueueTest, SymbolQueueTest) {
  std::stringstream input;
  input << "a(b (#d\n";
  input << " aba{!})_";
  SymbolQueue symbols;
  symbols.readFrom(input);
  EXPECT_EQ(symbols, std::queue<std::string>({"a", "(", "b", "(", "aba{!}", ")", "_"}));
}
