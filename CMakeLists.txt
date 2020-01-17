cmake_minimum_required(VERSION 3.10)

# mkdir -p build/mac-build && cd build/mac-build
# cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON ../..

# mkdir -p build\vs-build && cd build\vs-build
# cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON -DENABLE_STATIC=STATIC -A Win32 -Thost=x64 -G "Visual Studio 15 2017" ../..
# cmake --build . --config release --target luaclang

project(luaclang)

set(LLVM_PROJECT ${CMAKE_CURRENT_SOURCE_DIR}/../llvm-project)

if(WIN32)
    add_definitions(-D_CINDEX_LIB_)
endif()

add_subdirectory(${LLVM_PROJECT}/llvm ${CMAKE_CURRENT_BINARY_DIR}/llvm)

add_library(luaclang MODULE lua_clang.cpp olua/olua.c)
set_target_properties(luaclang PROPERTIES 
    PREFIX ""
    OUTPUT_NAME clang
)
target_include_directories(luaclang PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/lua
    ${LLVM_PROJECT}/clang/include
)
if(APPLE)
    target_link_options(luaclang PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    find_library(LIBLUA NAMES lua)
    target_link_libraries(luaclang ${LIBLUA})
    set_target_properties(libclang_static PROPERTIES OUTPUT_NAME libclang_static)
endif()

target_link_libraries(luaclang libclang_static)