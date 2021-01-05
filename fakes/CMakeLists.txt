add_library(dep_to_fake_lib dependency_to_fake.cpp)

add_executable(test_fake my_service_using_dependency_test.cpp)
target_link_libraries(test_fake dep_to_fake_lib ${CONAN_LIBS})
target_include_directories(test_fake PUBLIC ${CONAN_INCLUDE_DIRS_GTEST})
target_link_directories(test_fake PUBLIC ${CONAN_LIB_DIRS})
