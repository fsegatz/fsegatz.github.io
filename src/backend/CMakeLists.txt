# Add the markdownFileReader.cpp file to the library
add_library(backend_lib markdownFileReader.cpp)
target_include_directories(backend_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(markdownFileReaderTest test_markdownFileReader.cpp)
target_link_libraries(markdownFileReaderTest PRIVATE
    backend_lib 
    Qt6::Test
)
# set_target_properties(markdownFileReaderTest PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests
# )

add_test(
    NAME markdownFileReaderTest 
    COMMAND markdownFileReaderTest
)
