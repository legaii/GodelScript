#include <gtest/gtest.h>
#include <fstream>
#include "Namespace.hpp"


std::shared_ptr<Function> getMainFunction(const std::string& fileName) {
  std::ifstream file{fileName};
  Namespace mainSpace;
  mainSpace.readFrom(file);
  return mainSpace.getNamedFunction("main");
}


TEST(ExamplesTest, Multiply) {
  auto mainFunction = getMainFunction("../../examples/Multiply.godel");
  EXPECT_EQ(mainFunction->eval({7, 9}), 63);
  EXPECT_EQ(mainFunction->eval({17, 29}), 493);
  EXPECT_EQ(mainFunction->eval({37, 73}), 2701);
}


TEST(ExamplesTest, IsPrime) {
  auto mainFunction = getMainFunction("../../examples/IsPrime.godel");
  EXPECT_EQ(mainFunction->eval({7}), 1);
  EXPECT_EQ(mainFunction->eval({8}), 0);
  EXPECT_EQ(mainFunction->eval({27}), 0);
  EXPECT_EQ(mainFunction->eval({29}), 1);
  EXPECT_EQ(mainFunction->eval({31}), 1);
  EXPECT_EQ(mainFunction->eval({57}), 0);
  EXPECT_EQ(mainFunction->eval({61}), 1);
  EXPECT_EQ(mainFunction->eval({63}), 0);
}


uint64_t encode(int x) {
  return x >= 0 ? x * 2 : -x * 2 - 1;
}


TEST(ExamplesTest, Substract) {
  auto mainFunction = getMainFunction("../../examples/Subtract.godel");
  const int MAX_ABS = 20;
  for (int x = -MAX_ABS; x <= MAX_ABS; ++x) {
    for (int y = -MAX_ABS; y <= MAX_ABS; ++y) {
      EXPECT_EQ(mainFunction->eval({encode(x), encode(y)}), encode(x - y));
    }
  }
}
