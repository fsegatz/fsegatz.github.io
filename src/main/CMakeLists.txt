add_executable(index
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(index PRIVATE
    mainwidget
    Qt6::Widgets
)

qt_finalize_executable(index)
