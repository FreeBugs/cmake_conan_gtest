add_executable(test_personen_service person_service_tests.cpp person.cpp person_service_impl.cpp)
target_link_libraries(test_personen_service ${CONAN_LIBS})
target_include_directories(test_personen_service PUBLIC ${CONAN_INCLUDE_DIRS_GTEST})
target_link_directories(test_personen_service PUBLIC ${CONAN_LIB_DIRS})
