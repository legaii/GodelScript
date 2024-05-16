#include <gtest/gtest.h>
#include "Expression.hpp"


uint64_t eval(std::string text, std::vector<uint64_t> args = {}) {
  std::istringstream input{std::move(text)};
  SymbolQueue symbols;
  symbols.readFrom(input);
  return Expression::readFrom(symbols).parse({})->eval(std::move(args));
}


TEST(ExpressionTest, Constant) {
  EXPECT_EQ(eval("5_0"), 5);
  EXPECT_EQ(eval("1025_2", {24929492, 8}), 1025);
}


TEST(ExpressionTest, Succ) {
  EXPECT_EQ(eval("succ", {7}), 8);
  EXPECT_EQ(eval("succ", {1024}), 1025);
}


TEST(ExpressionTest, Id) {
  EXPECT_EQ(eval("id1_2", {1, 2}), 1);
  EXPECT_EQ(eval("id2_2", {1, 2}), 2);
}


TEST(ExpressionTest, Compose) {
  EXPECT_EQ(eval("(Compose succ succ)", {3}), 5);
  EXPECT_EQ(eval("(Compose succ id1_2)", {1, 2}), 2);
  EXPECT_EQ(eval("(Compose succ id2_2)", {1, 2}), 3);
  EXPECT_EQ(eval("(Compose (Compose succ id2_2) id2_3 id3_3)", {1, 2, 3}), 4);
  EXPECT_EQ(eval("(Compose succ (Compose succ id1_2))", {1, 2}), 3);
}


TEST(ExpressionTest, Recur) {
  EXPECT_EQ(eval("(Recur succ 0_2)", {0}), 1);
  EXPECT_EQ(eval("(Recur succ 0_2)", {1}), 0);
  EXPECT_EQ(eval("(Recur id1_1 (Compose succ id1_3))", {4, 5}), 9);
  EXPECT_EQ(eval("(Recur 0_0 (Compose succ (Compose succ id1_2)))", {5}), 10);
  EXPECT_EQ(eval("(Recur 1_0 (Recur 0_1 (Compose succ (Compose succ id1_3))))", {5}), 32);
}


TEST(ExpressionTest, Min) {
  EXPECT_EQ(eval("(Min 0_1)"), 0);
  EXPECT_EQ(eval("(Min (Recur 3_0 id2_2))"), 1);
  EXPECT_EQ(eval("(Min (Recur 9_0 (Recur 0_1 id2_3)))"), 9);
}
