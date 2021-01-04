cmake_minimum_required(VERSION 3.17)
project(cmake_conan_gtest)
set(CMAKE_CXX_STANDARD 17)

include(cmake/conan.cmake)
conan_cmake_run(REQUIRES
        gtest/1.10.0
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

add_executable(main main.cpp)

add_executable(test test.cpp schwein.cpp schwein.hpp)
target_link_libraries(test ${CONAN_LIBS})
target_include_directories(test PUBLIC ${CONAN_INCLUDE_DIRS_GTEST})
target_link_directories(test PUBLIC ${CONAN_LIB_DIRS})