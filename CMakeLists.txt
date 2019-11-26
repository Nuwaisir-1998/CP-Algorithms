cmake_minimum_required(VERSION 3.15)
project(CP_Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(sieve sieve.cpp)
add_executable(DFS DFS.cpp)
add_executable(BFS BFS.cpp)
add_executable(BigInteger BigInteger.cpp)
add_executable(random_workspace random_workspace.cpp)
add_executable(BigMod BigMod.cpp)
add_executable(DSU DSU.cpp)