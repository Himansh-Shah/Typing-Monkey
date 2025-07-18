cmake_minimum_required(VERSION 3.10)
project(Typing_Monkey CXX)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


add_executable(typing_monkey src/test.cpp src/WordGenerator.cpp)
target_link_libraries(typing_monkey ${CURSES_LIBRARIES})
