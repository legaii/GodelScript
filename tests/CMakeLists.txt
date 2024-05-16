include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TEST_NAMES SymbolQueueTest ExpressionTest)
add_custom_target(test)

include(GoogleTest)
foreach(TEST_NAME IN LISTS TEST_NAMES)
  add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
  target_link_libraries(${TEST_NAME} godel_lib GTest::gtest_main)
  gtest_discover_tests(${TEST_NAME})
  add_custom_target(CustomTarget${TEST_NAME} ${TEST_NAME})
  add_dependencies(test CustomTarget${TEST_NAME})
endforeach()
