cmake_minimum_required(VERSION 2.8)
project(markdown-editor)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE Debug)
set (source main.cpp
	CommandLine.cpp
	Translator.cpp)
add_executable(${PROJECT_NAME} ${source})
