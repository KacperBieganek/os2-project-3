cmake_minimum_required(VERSION 3.5)

set(APP_NAME Cipher)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_STANDARD 14)
project(${APP_NAME})

aux_source_directory(./src SRC)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)

add_executable(${APP_NAME} ${SRC})
include_directories(${CURSES_INCLUDE_DIR})
include_directories(include)
target_link_libraries(${APP_NAME} Threads::Threads ${CURSES_LIBRARIES})
