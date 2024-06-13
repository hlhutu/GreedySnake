cmake_minimum_required(VERSION 3.28)
project(clion1)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.h")
message("Comparing: " + ${SRCS})
add_executable(clion1 ${SRCS})
