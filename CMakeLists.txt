cmake_minimum_required(VERSION 3.10)

project(luaclang)

if(WIN32)
    add_definitions(-D_CINDEX_LIB_)
endif()

add_subdirectory(llvm-project/llvm)
add_subdirectory(lua)

add_library(luaclang MODULE lua_clang.cpp olua/olua.c)
set_target_properties(luaclang PROPERTIES 
    PREFIX ""
    OUTPUT_NAME clang
)
target_include_directories(luaclang PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/lua
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm-project/clang/include
)
if(APPLE)
    target_link_options(luaclang PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luaclang liblua)
    set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
endif()

target_link_libraries(luaclang libclang_static)

