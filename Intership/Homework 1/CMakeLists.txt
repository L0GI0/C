cmake_minimum_required(VERSION 2.6)

project(Program C)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall -O0  -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-Wall -O0")
set(SRC 
	BST.c
	BST.h
	main.c
	)

add_compile_options(-Wall -g -pedantic -pedantic-errors -Wextra)	

add_executable(Program ${SRC})
