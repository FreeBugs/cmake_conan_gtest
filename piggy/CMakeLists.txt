add_executable(test_piggy pig_test.cpp piggy.cpp)
target_link_libraries(test_piggy ${CONAN_LIBS})
target_include_directories(test_piggy PUBLIC ${CONAN_INCLUDE_DIRS_GTEST})
target_link_directories(test_piggy PUBLIC ${CONAN_LIB_DIRS})