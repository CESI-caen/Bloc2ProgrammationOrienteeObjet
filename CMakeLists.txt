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

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(exe PRIVATE
    sfml-graphics sfml-window sfml-system sfml-audio
)
