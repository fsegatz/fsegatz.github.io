qt_add_executable(index
    MANUAL_FINALIZATION
    main.cpp
    mainWindow.cpp
    mainWindow.h
)

target_link_libraries(index PRIVATE Qt6::Widgets)

qt_finalize_executable(index)

