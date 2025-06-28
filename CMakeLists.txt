cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 17)

find_package(FLTK REQUIRED)

include_directories(${FLTK_INCLUDE_DIR})

add_executable(
    main.cpp
    model/student.h
    viewmodel/studentviewmodel.h viewmodel/studentviewmodel.cpp
    view/studentview.h view/studentview.cpp
)

target_link_libraries(test ${FLTK_LIBRARIES})
