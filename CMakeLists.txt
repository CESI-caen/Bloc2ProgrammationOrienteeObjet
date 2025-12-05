cmake_minimum_required(VERSION 3.10)

project(exe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Récupère tous les fichiers .cpp dans src/
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(exe ${SOURCES})

target_include_directories(exe PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
# Liens avec SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(exe PRIVATE
    sfml-graphics sfml-window sfml-system sfml-audio
)

# Tests avec Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TEST_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM TEST_SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_executable(run_tests ${TEST_SOURCES} ${TEST_FILES})

target_include_directories(run_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(run_tests PRIVATE
    ${GTEST_LIBRARIES}
    pthread
    sfml-graphics sfml-window sfml-system sfml-audio
)

add_test(NAME GeneralTests COMMAND run_tests)
