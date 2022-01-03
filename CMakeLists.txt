cmake_minimum_required(VERSION 3.10)

project(luaclang)

# llvm-project/llvm/CMakeLists.txt
set(LLVM_ENABLE_PROJECTS "clang" CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD "" CACHE STRING "")

set(LUA "lua54" CACHE STRING "lua version to use, default is lua54")

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

add_subdirectory(llvm-project/llvm)

add_library(luaclang MODULE lua_clang.cpp olua/olua.c)
set_target_properties(luaclang PROPERTIES 
    PREFIX ""
    OUTPUT_NAME clang
)
target_include_directories(luaclang PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm-project/clang/include
)

if(LUA STREQUAL "lua54")
    add_subdirectory(lua)
    target_include_directories(luaclang PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lua
    )
elseif(LUA STREQUAL "lua53")
    add_subdirectory(lua53)
    target_include_directories(luaclang PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lua53
    )
else()
    message(FATAL_ERROR "only support lua53 or lua54")
endif()

if(APPLE)
    target_link_options(luaclang PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luaclang liblua)
    set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
endif()

target_link_libraries(luaclang libclang_static)

