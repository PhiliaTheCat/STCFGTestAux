cmake_minimum_required(VERSION 3.28)

project(STCFGTestAux)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Werror -Wall -Wextra -pedantic-errors -fanalyzer)

add_executable(coder src/main.c src/Cipher.c src/IO.c)

target_include_directories(coder PRIVATE include)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_options(-Og)
elseif (CMAKE_BUILD_TYPE STREQUAL Release)
    add_compile_options(-O2)
elseif (CMAKE_BUILD_TYPE STREQUAL Default)
    add_compile_options(-O1)
endif ()
