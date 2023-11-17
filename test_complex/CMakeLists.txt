add_executable(test_complex test_complex.cpp)

target_link_libraries(test_complex complex)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)