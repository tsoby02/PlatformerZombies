cmake_minimum_required(VERSION 3.28)
project(PlatformerZombies)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(
        INCLUDE_FILES
        include/Game.h
        include/Window.h
        include/StateInterface.h
        include/MenuState.h
        include/GameState.h
        include/ExitState.h
)
set(
        SRC_FILES
        src/Game.cpp
        src/Window.cpp
        src/MenuState.cpp
        src/GameState.cpp
        src/ExitState.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${INCLUDE_FILES} ${SRC_FILES})

target_link_libraries(
        ${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)
