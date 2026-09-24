cmake_minimum_required(VERSION 3.16)

project(TOAN_OOP
    VERSION 1.0.0
    DESCRIPTION "He thong mo hinh hoa va sinh bai toan Toan bang C++ OOP"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(toan_geometry
    src/geometry/Diem.cpp
    src/geometry/DoanThang.cpp
    src/geometry/TamGiac.cpp
)

target_include_directories(toan_geometry
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(toan_geometry PUBLIC cxx_std_17)

if (MSVC)
    target_compile_options(toan_geometry PRIVATE /W4 /permissive-)
else()
    target_compile_options(toan_geometry PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_library(toan_core
    src/core/BaiToan.cpp
)

target_include_directories(toan_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(toan_core PUBLIC toan_geometry)

target_compile_features(toan_core PUBLIC cxx_std_17)

add_executable(toan_app src/main.cpp)
target_link_libraries(toan_app PRIVATE toan_core toan_geometry)

include(CTest)
if (BUILD_TESTING)
    add_executable(toan_tests tests/geometry_tests.cpp)
    target_link_libraries(toan_tests PRIVATE toan_core toan_geometry)
    add_test(NAME geometry_tests COMMAND toan_tests)
endif()
