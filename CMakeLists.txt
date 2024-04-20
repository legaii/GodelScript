cmake_minimum_required(VERSION 3.17)
project(godel_script)

add_library(godel_lib
  src/Compose.cpp
  src/Min.cpp
  src/Namespace.cpp
  src/Recur.cpp
)

target_include_directories(godel_lib PUBLIC include)

add_executable(godel src/Main.cpp)
target_link_libraries(godel godel_lib)
