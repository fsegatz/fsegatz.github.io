cmake_minimum_required(VERSION 3.16)

project(index
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(main)
add_subdirectory(widgets/mainwidget)
add_subdirectory(widgets/menuwidget)
add_subdirectory(widgets/aboutmewidget)
