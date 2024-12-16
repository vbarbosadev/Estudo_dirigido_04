cmake_minimum_required(VERSION 3.14)
project(TestProject)

# Habilitar C++17
set(CMAKE_CXX_STANDARD 17)

# Adicionar o Google Test como subdiretório
add_subdirectory(googletest)

# Adicionar o executável
add_executable(tests main.cpp)

# Linkar o Google Test ao executável
target_link_libraries(tests gtest gtest_main)
