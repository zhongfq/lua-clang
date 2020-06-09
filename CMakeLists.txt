cmake_minimum_required(VERSION 3.10)

project(luaclang)

set(LUA_VERSION "lua54" CACHE STRING "lua version to use, default is lua54")

if(WIN32)
    add_definitions(-D_CINDEX_LIB_)
endif()

add_subdirectory(llvm-project/llvm)

if(LUA_VERSION STREQUAL "lua54")
    add_subdirectory(lua)
elseif(LUA_VERSION STREQUAL "lua53")
    add_subdirectory(lua53)
else()
    message(FATAL_ERROR "only support lua53 or lua54")
endif()

add_library(luaclang MODULE lua_clang.cpp olua/olua.c)
set_target_properties(luaclang PROPERTIES 
    PREFIX ""
    OUTPUT_NAME clang
)
target_include_directories(luaclang PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm-project/clang/include
)

if(LUA_VERSION STREQUAL "lua54")
    target_include_directories(luaclang PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lua
    )
elseif(LUA_VERSION STREQUAL "lua53")
    target_include_directories(luaclang PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lua53
    )
endif()

if(APPLE)
    target_link_options(luaclang PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luaclang liblua)
    set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
endif()

target_link_libraries(luaclang libclang_static)

