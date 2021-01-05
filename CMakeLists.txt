cmake_minimum_required(VERSION 3.17)
project(cmake_conan_gtest)
set(CMAKE_CXX_STANDARD 17)

include(cmake/conan.cmake)
conan_cmake_run(REQUIRES
        gtest/1.10.0
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

add_executable(main main.cpp)

add_subdirectory(multiplier)
add_subdirectory(piggy)
add_subdirectory(person_service)