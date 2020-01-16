cmake_minimum_required(VERSION 3.6)

# mkdir -p build/mac-build && cd build/mac-build
# cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON ../..
# cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON -DENABLE_STATIC=STATIC -A Win32 -Thost=x64 -G "Visual Studio 15 2017" ../..

project(luaclang)

add_library(luaclang MODULE lua_clang.cpp olua/olua.c)
set_target_properties(luaclang PROPERTIES 
    PREFIX ""
    OUTPUT_NAME clang
)
target_include_directories(luaclang PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/lua
    ${CMAKE_CURRENT_SOURCE_DIR}/../llvm-project/clang/include
)
if(APPLE)
    target_link_options(luaclang PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_compile_definitions(luaclang PUBLIC _CINDEX_LIB)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../llvm-project/llvm ${CMAKE_CURRENT_BINARY_DIR}/llvm)
target_link_libraries(luaclang libclang_static)
