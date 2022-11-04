add_library(aboutmewidget STATIC
    aboutmewidget.cpp
    aboutmewidget.h
)

target_link_libraries(aboutmewidget PRIVATE
    Qt6::Widgets
)

qt_finalize_target(aboutmewidget)

target_include_directories(aboutmewidget INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
