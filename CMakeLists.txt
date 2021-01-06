cmake_minimum_required(VERSION 3.17)
project(cmake_conan_gtest)
set(CMAKE_CXX_STANDARD 17)

include(cmake/conan.cmake)

### Required remotes:
# conan-center: conan remote add conan-center https://conan.bintray.com
# bincrafters:  conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

conan_cmake_run(REQUIRES
        gtest/1.10.0
        qt/6.0.0@bincrafters/stable
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

add_executable(main main.cpp)

add_subdirectory(multiplier)
add_subdirectory(piggy)
add_subdirectory(person_service)
add_subdirectory(fakes)
add_subdirectory(qt_minimal)
add_subdirectory(euro_to_dollar)