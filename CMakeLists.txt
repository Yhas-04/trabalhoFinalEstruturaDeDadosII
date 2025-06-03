cmake_minimum_required(VERSION 3.16)
project(TrabalhoFinal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gui)

set(SOURCES
    main.cpp
    gui/mainwindow.cpp
    gui/telaarvore.cpp
    src/Arvore.cpp
    src/Grafo.cpp
)

set(HEADERS
    gui/mainwindow.h
    gui/telaarvore.h
    src/Arvore.h
    src/Grafo.h
    src/noArvore.h
)

add_executable(TrabalhoFinal
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(TrabalhoFinal PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}  # esta linha inclui o root build, onde fica o autogen
)


target_link_libraries(TrabalhoFinal PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TrabalhoFinal)
endif()
