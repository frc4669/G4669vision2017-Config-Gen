cmake_minimum_required(VERSION 2.8)

project(configGen)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_configGen configGen.cpp)

target_link_libraries(cv_configGen ${OpenCV_LIBS})
