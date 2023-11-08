add_library(aboutmewidget STATIC
    aboutmewidget.cpp
    aboutmewidget.h
    resources.qrc
)


target_link_libraries(aboutmewidget PRIVATE
    Qt6::Widgets
)

target_include_directories(aboutmewidget INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
