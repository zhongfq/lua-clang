cmake_minimum_required(VERSION 3.10)

project(luaclang)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# llvm-project/llvm/CMakeLists.txt
set(LLVM_ENABLE_PROJECTS "clang" CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD "" CACHE STRING "")
set(LLVM_ENABLE_ZSTD "OFF" CACHE STRING "")

# llvm-project/clang/tools/libclang/CMakeLists.txt
set(LIBCLANG_BUILD_STATIC ON CACHE BOOL "")

if(WIN32)
    add_definitions(-D_CINDEX_LIB_)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Od")
    set(ENABLE_STATIC STATIC CACHE UNINITIALIZED "")
endif()

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
endif()

include(lua.cmake)

add_subdirectory(llvm-project/llvm)

set(SRC
    src/lua_clang.h
    src/lua_clang.cpp
    src/clang_wrapper.h
    src/clang_wrapper.cpp
    olua/olua.h
    olua/olua.c
)

# luaclang53
add_library(luaclang53 MODULE ${SRC})
set_target_properties(luaclang53 PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "lua53"
    OUTPUT_NAME clang
)
target_include_directories(luaclang53
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/lua53
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm-project/clang/include
)

if(APPLE)
    target_link_options(luaclang53 PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luaclang53 liblua53)
    set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
endif()

target_link_libraries(luaclang53 libclang_static)

# luaclang54
add_library(luaclang54 MODULE ${SRC})
set_target_properties(luaclang54 PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "lua54"
    OUTPUT_NAME clang
)
target_include_directories(luaclang54
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/lua54
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm-project/clang/include
)

if(APPLE)
    target_link_options(luaclang54 PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luaclang54 liblua54)
    set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
endif()

target_link_libraries(luaclang54 libclang_static)

# luaclang55
# add_library(luaclang55 MODULE ${SRC})
# set_target_properties(luaclang55 PROPERTIES
# PREFIX ""
# LIBRARY_OUTPUT_DIRECTORY "lua55"
# OUTPUT_NAME clang
# )
# target_include_directories(luaclang55
# PUBLIC
# ${CMAKE_CURRENT_SOURCE_DIR}
# ${CMAKE_CURRENT_SOURCE_DIR}/lua55
# ${CMAKE_CURRENT_SOURCE_DIR}/llvm-project/clang/include
# )

# if(APPLE)
# target_link_options(luaclang55 PUBLIC -bundle -undefined dynamic_lookup)
# elseif(WIN32)
# target_link_libraries(luaclang55 liblua55)
# set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
# endif()

# target_link_libraries(luaclang55 libclang_static)
