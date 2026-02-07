cmake_minimum_required(VERSION 3.20)
project(pixel_platformer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL3_DIR ${CMAKE_SOURCE_DIR}/third_party/SDL3)

add_executable(pixel_platformer
    main.cpp
    engine/Application.cpp
    engine/Window.cpp
    engine/Game.cpp
)


target_include_directories(pixel_platformer PRIVATE
    ${SDL3_DIR}/include
    ${CMAKE_SOURCE_DIR}
)



target_link_directories(pixel_platformer PRIVATE
    ${SDL3_DIR}/lib/x64
)

target_link_libraries(pixel_platformer
    SDL3
)

add_custom_command(TARGET pixel_platformer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/third_party/SDL3/lib/x64/SDL3.dll
        $<TARGET_FILE_DIR:pixel_platformer>
)
