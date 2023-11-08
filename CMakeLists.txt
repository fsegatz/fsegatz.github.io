cmake_minimum_required(VERSION 3.16)

project(MyQtProject VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt libraries
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Add the src subdirectory
add_subdirectory(src)
