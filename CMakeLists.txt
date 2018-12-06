cmake_minimum_required(VERSION 3.8)
project(my_opus_121)

set(CMAKE_C_STANDARD 90)

#add_definitions(-DVAR_ARRAYS)
add_definitions(-DUSE_ALLOCA)
add_definitions(-DCUSTOM_MODES)
add_definitions(-DFIXED_POINT)
add_definitions(-DDISABLE_FLOAT_API)
add_definitions(-DUSE_SMALL_DIV_TABLE)
#add_definitions(-DEC_CLZ)
#set(CXX_PLATFORM_DEPENDENT_FLAGS_DEBUG      "-DDEBUG -DACSDK_DEBUG_LOG_ENABLED -Wall -Werror -Wsign-compare -g")

#include_directories(silk silk/float silk/fixed  celt opus_include)
file(GLOB BASE_SOURCES src/*.c )
file(GLOB CELT_SOURCES celt/*.c )
file(GLOB SILK_SOURCES silk/*.c )
file(GLOB FIXED_SILK_SOURCES silk/fixed/*.c )
file(GLOB FLOAT_SILK_SOURCES silk/float/*.c )

set(SOURCE_FILES main.c
        src/opus.c
        src/opus_encoder.c
        src/repacketizer.c
        "${BASE_SOURCES}"
        "${CELT_SOURCES}"
        "${SILK_SOURCES}"
#        "${FLOAT_SILK_SOURCES}"
                "${FIXED_SILK_SOURCES}"
        )
add_executable(my_opus_121 ${SOURCE_FILES})