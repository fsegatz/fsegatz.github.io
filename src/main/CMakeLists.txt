add_executable(index
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(index PRIVATE
    mainwidget
    Qt6::Widgets
)

# Create ${target}.html (a target-specific wasm_shell.html file), qtloader.js, and qtlogo.svg files in the CMAKE_CURRENT_BINARY_DIR.
qt_finalize_target(index)

set(INDEX_MAIN_DIR ${index_BINARY_DIR}/src/main)

#Specify the source files
set(INDEX_FILES
    ${INDEX_MAIN_DIR}/index.html
    ${INDEX_MAIN_DIR}/qtloader.js
    ${INDEX_MAIN_DIR}/qtlogo.svg
    ${INDEX_MAIN_DIR}/index.js
    ${INDEX_MAIN_DIR}/index.wasm
)

# Specify the destination directory
set(INDEX_APP_DIR ${index_BINARY_DIR}/app)

#Create a custom command for copying files after build
add_custom_command(
    TARGET index POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${INDEX_APP_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${INDEX_FILES} ${INDEX_APP_DIR}
    COMMENT "Copying resources to ${INDEX_APP_DIR}"
)
