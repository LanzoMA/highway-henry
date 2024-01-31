cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("highway-henry")

add_executable (${PROJECT_NAME} "src/main.cpp" "include/sprite.h" "src/sprite.cpp" "include/text.h" "src/text.cpp" "src/game.cpp" "include/score.h" "src/score.cpp" "include/music.h" "src/music.cpp")

# Libraries for Release
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-main.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-system.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-window.lib)

# Libraries for Debug
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-main-d.lib)
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-graphics-d.lib)
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-system-d.lib)
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-window-d.lib)
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/sfml-audio-d.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)