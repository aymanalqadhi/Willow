cmake_minimum_required(VERSION 3.10)

# Project name
project(willow C)

# Project files
set(SOURCE_FILES src/error.c
                 src/logger.c
                 src/memory.c
                 src/lexer_token.c
                 src/main.c)
include_directories(include)

# Project targets
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
