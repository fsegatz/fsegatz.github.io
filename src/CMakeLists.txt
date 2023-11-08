qt_add_executable(qttest 
    main.cpp
)

target_link_libraries(qttest PRIVATE Qt6::Widgets)

set_target_properties(qttest PROPERTIES
    WIN32_EXECUTABLE ON
)