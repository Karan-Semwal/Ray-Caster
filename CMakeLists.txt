cmake_minimum_required(VERSION 3.0)

project(Ray-Caster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files to your project
file(GLOB SOURCE_FILES 
    src/*.cpp
)

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/Linux/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Set the include directories
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} 
    sfml-system 
    sfml-window 
    sfml-graphics
)