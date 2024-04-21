cmake_minimum_required(VERSION 3.17)
project(godel_script)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GODEL_FLAGS -Wall -Wextra -Werror -Wpedantic)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  list(APPEND GODEL_FLAGS
    -fsanitize=address,bounds,leak,undefined -fno-sanitize-recover -fstack-protector)
endif()

foreach(FLAG IN LISTS GODEL_FLAGS)
  message(VERBOSE "Adding ${FLAG}")
  add_compile_options(${FLAG})
  add_link_options(${FLAG})
endforeach()

add_library(godel_lib
  src/Compose.cpp
  src/Constant.cpp
  src/Expression.cpp
  src/Id.cpp
  src/Min.cpp
  src/Namespace.cpp
  src/Recur.cpp
  src/StringFunctions.cpp
  src/Succ.cpp
  src/SymbolQueue.cpp
)

target_include_directories(godel_lib PUBLIC include)

add_executable(godel src/Main.cpp)
target_link_libraries(godel godel_lib)
