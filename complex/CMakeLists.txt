# CMakeList.txt: проект CMake для complex; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в библиотеку этого проекта.
add_library(complex STATIC "complex.cpp" "complex.hpp")

# Добавьте исполняемый файл этого проекта и свяжите его с библиотекой.
add_executable(test_complex "test_complex.cpp")
target_link_libraries(test_complex complex)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET complex PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
