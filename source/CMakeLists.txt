cmake_minimum_required(VERSION 2.8)
project(markdown-editor)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_BUILD_TYPE Debug)
set (source main.cpp
	CommandLine.cpp
	Title.cpp
	OrderedList.cpp
	BaseObject.cpp
	)
add_executable(${PROJECT_NAME} ${source})
