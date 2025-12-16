cmake_minimum_required(VERSION 3.10.0)
project(lab6 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Добавляем папку include в пути поиска
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    src/model/Primitive.cpp
    src/model/Document.cpp
    src/view/IView.cpp
    src/controller/IController.cpp
    src/Application.cpp
    src/main.cpp
)

set(HEADERS
    include/model/Primitive.h
    include/model/Document.h
    include/view/IView.h
    include/controller/IController.h
    include/Application.h
)

add_executable(lab6 ${SOURCES} ${HEADERS})

if(MSVC)
    # Параметры для Visual Studio
    target_compile_options(lab6 PRIVATE /W4)
else()
    # Параметры для GCC/Clang
    target_compile_options(lab6 PRIVATE -Wall -Wextra -Wpedantic -Wno-unused-parameter)
endif()

message(STATUS "===============================================")
message(STATUS "VectorEditor Project Configuration")
message(STATUS "===============================================")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Generator: ${CMAKE_GENERATOR}")
message(STATUS "===============================================")