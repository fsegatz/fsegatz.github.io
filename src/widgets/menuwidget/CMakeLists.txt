add_library(menuwidget STATIC
    menuwidget.cpp
    menuwidget.h
)

target_link_libraries(menuwidget PRIVATE
    Qt6::Widgets
)

target_include_directories(menuwidget INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
