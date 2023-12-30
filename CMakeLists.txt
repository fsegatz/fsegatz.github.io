cmake_minimum_required(VERSION 3.16)

project(index VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find the required Qt libraries
find_package(Qt6 REQUIRED COMPONENTS Widgets Test)
qt_standard_project_setup()
enable_testing()

# Add the src subdirectory
add_subdirectory(src)
