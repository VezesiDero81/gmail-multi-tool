cmake_minimum_required(VERSION 3.16)
project(gmail-multi-tool CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gmailmultitool
    src/main.cpp
    src/accounts.cpp
    src/limits.cpp
    src/rotate.cpp
)

target_include_directories(gmailmultitool PRIVATE include)

if(WIN32)
    target_link_libraries(gmailmultitool PRIVATE userenv)
endif()
