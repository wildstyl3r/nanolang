cmake_minimum_required(VERSION 3.14...3.18)

project(
  nanolang
  VERSION 0.1
  LANGUAGES C)

set(PROJECT_SOURCES
        src/main.c
        src/nanocore.c
        src/nanotools.c
        src/nanoshell.c)

target_include_directories(
  nanolang
  PRIVATE $<BUILD_INTERFACE:${nanolang_SOURCE_DIR}/src>
  PUBLIC $<BUILD_INTERFACE:${nanolang_SOURCE_DIR}/>)
