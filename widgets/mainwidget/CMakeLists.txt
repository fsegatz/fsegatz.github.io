add_library(mainwidget STATIC
    mainWidget.cpp
    mainWidget.h
)

target_link_libraries(mainwidget PRIVATE
    aboutmewidget
    menuwidget
    Qt6::Widgets
)

qt_finalize_target(mainwidget)

target_include_directories(mainwidget INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
