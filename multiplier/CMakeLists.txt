add_executable(test_mult mult_test.cpp)
target_link_libraries(test_mult ${CONAN_LIBS})
target_include_directories(test_mult PUBLIC ${CONAN_INCLUDE_DIRS_GTEST})
target_link_directories(test_mult PUBLIC ${CONAN_LIB_DIRS})