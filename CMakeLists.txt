cmake_minimum_required(VERSION 3.16)

project(Printout VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets)

set(TS_FILES Printout_ru_RU.ts)
qt_add_translation(QM_FILES ${TS_FILES})

set(PROJECT_SOURCES
        excelmanager.cpp
    	main.cpp
    	printoutmainwin.cpp
    	printouttabledialog.cpp
    	api/db/Dao.cpp
    	excelmanager.h
    	printQt.h
    	printoutmainwin.h
    	printouttabledialog.h
    	api/Printout.h
    	api/Record.h
    	api/Definitions.h
    	api/Printer.h
    	api/TableStructure.h
    	api/db/Dao.h
    	api/excelManager/excelManager.h
    	printoutmainwin.ui
    	printouttabledialog.ui
        ${TS_FILES}
)

    
add_custom_target(translations ALL DEPENDS ${QM_FILES})
add_custom_target(resources ALL DEPENDS ${RESOURCE_FILES})
add_dependencies(resources translations)
#add_executable(${CMAKE_PROJECT_NAME} WIN32
#  ${UI_HEADERS}
#  ${CODE_FILES}
#  ${RESOURCE_FILES}
#  ${WINDOWS_RES_FILE}
#)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Printout
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${RESOURCE_FILES}
    )
else()
    if(ANDROID)
        add_library(Printout SHARED
            ${PROJECT_SOURCES}
             ${RESOURCE_FILES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Printout
            ${PROJECT_SOURCES}
             ${RESOURCE_FILES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

add_dependencies(${CMAKE_PROJECT_NAME} resources)

target_link_libraries(Printout PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport OpenXLSX::OpenXLSX sqlite3)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled)
endif()
set_target_properties(Printout PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Printout
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
