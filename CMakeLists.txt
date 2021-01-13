cmake_minimum_required(VERSION 3.10)

# Project name
project(willow C)

# Project files
set(SOURCE_FILES src/type.c
                 src/error.c
                 src/parse.c
                 src/willow.c
                 src/check_words.c)
include_directories(include)

# Project targets
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
