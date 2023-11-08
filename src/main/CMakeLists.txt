add_executable(index
    main.cpp
    mainWindow.cpp
    mainWindow.h
)

target_link_libraries(index PRIVATE
    mainwidget
    Qt6::Widgets
)

qt_finalize_executable(index)
