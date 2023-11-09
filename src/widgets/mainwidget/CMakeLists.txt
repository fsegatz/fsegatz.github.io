add_library(mainwidget STATIC
    mainwidget.cpp
    mainwidget.h
)

target_link_libraries(mainwidget PRIVATE
    aboutmewidget
    menuwidget
    Qt6::Widgets
)

target_include_directories(mainwidget INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
