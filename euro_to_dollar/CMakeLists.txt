set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(SOURCES main.cpp EuroToDollarCalculatorApplication.cpp)
#set(MOC_HEADERS EuroToDollarCalculatorApplication.h)
set(UIS EuroToDollarCalculatorApplication.ui)
#set(RESOURCES EuroToDollarCalculatorApplication.qrc)

qt_wrap_ui(SOURCES EuroToDollarCalculatorApplication.ui)
add_executable(euro_to_dollar ${SOURCES})

target_link_libraries(euro_to_dollar Qt6::Core Qt6::Gui Qt6::Widgets)

install(TARGETS euro_to_dollar RUNTIME DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (APPLE)
    # Since there appear to exist problems with NOT setting the RPATH when building
    # by enabling CMAKE_KEEP_RPATH and others, we just set the libs absolute paths
    # to the conan lib dir.

    function(ChangeRPath target file new)
        message("Change RPATH for target ${target} from @rpath/${file} to ${new}.")
        add_custom_command(TARGET euro_to_dollar
                POST_BUILD COMMAND
                ${CMAKE_INSTALL_NAME_TOOL} -change @rpath/${file} ${new}/${file}
                $<TARGET_FILE:euro_to_dollar>)
    endfunction()

    foreach (qt_lib IN LISTS CONAN_LIBS_QT)
        ChangeRPath(euro_to_dollar lib${qt_lib}.dylib ${CONAN_LIB_DIRS_QT})
    endforeach ()
endif ()