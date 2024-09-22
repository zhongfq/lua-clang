cmake_minimum_required(VERSION 3.10)

set(LUA53SRC
    lua53/lapi.c
    lua53/lapi.h
    lua53/lauxlib.c
    lua53/lauxlib.h
    lua53/lbaselib.c
    lua53/lbitlib.c
    lua53/lcode.c
    lua53/lcode.h
    lua53/lcorolib.c
    lua53/lctype.c
    lua53/lctype.h
    lua53/ldblib.c
    lua53/ldebug.c
    lua53/ldebug.h
    lua53/ldo.c
    lua53/ldo.h
    lua53/ldump.c
    lua53/lfunc.c
    lua53/lfunc.h
    lua53/lgc.c
    lua53/lgc.h
    lua53/linit.c
    lua53/liolib.c
    lua53/llex.c
    lua53/llex.h
    lua53/llimits.h
    lua53/lmathlib.c
    lua53/lmem.c
    lua53/lmem.h
    lua53/loadlib.c
    lua53/lobject.c
    lua53/lobject.h
    lua53/lopcodes.c
    lua53/lopcodes.h
    lua53/loslib.c
    lua53/lparser.c
    lua53/lparser.h
    lua53/lprefix.h
    lua53/lstate.c
    lua53/lstate.h
    lua53/lstring.c
    lua53/lstring.h
    lua53/lstrlib.c
    lua53/ltable.c
    lua53/ltable.h
    lua53/ltablib.c
    lua53/ltests.c
    lua53/ltests.h
    lua53/ltm.c
    lua53/ltm.h
    lua53/lua.h
    lua53/luaconf.h
    lua53/lualib.h
    lua53/lundump.c
    lua53/lundump.h
    lua53/lutf8lib.c
    lua53/lvm.c
    lua53/lvm.h
    lua53/lzio.c
    lua53/lzio.h
)

if(WIN32)
    add_library(liblua53 SHARED ${LUA53SRC})
    target_compile_definitions(liblua53 PRIVATE LUA_BUILD_AS_DLL)
    set_target_properties(liblua53 PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "lua53"
        ARCHIVE_OUTPUT_DIRECTORY "lua53"
        RUNTIME_OUTPUT_DIRECTORY "lua53"
        LIBRARY_OUTPUT_NAME liblua
        RUNTIME_OUTPUT_NAME lua53
    )
else()
    add_library(liblua53 STATIC ${LUA53SRC})
    target_link_libraries(liblua53 PUBLIC readline)
    if (NOT APPLE)
        target_link_libraries(liblua53 PUBLIC m dl -Wl,-E)
        target_compile_definitions(liblua53 PUBLIC LUA_USE_LINUX)
    else()
        target_compile_definitions(liblua53 PUBLIC LUA_USE_MACOSX)
    endif()
endif()

target_include_directories(liblua53 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lua53)

add_executable(luac53 ${LUA53SRC} lua53/luac.c)
add_executable(lua53 lua53/lua.c)
set_target_properties(lua53 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "lua53"
    OUTPUT_NAME lua53)
target_link_libraries(lua53 liblua53)

set(LUA54SRC
    lua54/lapi.c
    lua54/lapi.h   
    lua54/lauxlib.c
    lua54/lauxlib.h
    lua54/lbaselib.c
    lua54/lcode.c
    lua54/lcode.h  
    lua54/lcorolib.c
    lua54/lctype.c
    lua54/lctype.h 
    lua54/ldblib.c
    lua54/ldebug.c
    lua54/ldebug.h 
    lua54/ldo.c
    lua54/ldo.h    
    lua54/ldump.c
    lua54/lfunc.c
    lua54/lfunc.h  
    lua54/lgc.c
    lua54/lgc.h    
    lua54/linit.c
    lua54/liolib.c
    lua54/llex.c
    lua54/llex.h   
    lua54/llimits.h
    lua54/lmathlib.c
    lua54/lmem.c
    lua54/lmem.h    
    lua54/loadlib.c
    lua54/lobject.c
    lua54/lobject.h 
    lua54/lopcodes.c
    lua54/lopcodes.h
    lua54/loslib.c
    lua54/lparser.c
    lua54/lparser.h 
    lua54/lprefix.h 
    lua54/lstate.c
    lua54/lstate.h  
    lua54/lstring.c
    lua54/lstring.h 
    lua54/lstrlib.c
    lua54/ltable.c
    lua54/ltable.h
    lua54/ltablib.c
    lua54/ltm.c
    lua54/ltm.h
    lua54/lua.h
    lua54/luaconf.h
    lua54/lualib.h
    lua54/lundump.c
    lua54/lundump.h
    lua54/lutf8lib.c
    lua54/lvm.c
    lua54/lvm.h
    lua54/lzio.c
    lua54/lzio.h
)

if(WIN32)
    add_library(liblua54 SHARED ${LUA54SRC})
    target_compile_definitions(liblua54 PRIVATE LUA_BUILD_AS_DLL)
    set_target_properties(liblua54 PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "lua54"
        ARCHIVE_OUTPUT_DIRECTORY "lua54"
        RUNTIME_OUTPUT_DIRECTORY "lua54"
        LIBRARY_OUTPUT_NAME liblua
        RUNTIME_OUTPUT_NAME lua54
    )
else()
    add_library(liblua54 STATIC ${LUA54SRC})
    target_link_libraries(liblua54 PUBLIC readline)
    if (NOT APPLE)
        target_link_libraries(liblua54 PUBLIC m dl -Wl,-E)
        target_compile_definitions(liblua54 PUBLIC LUA_USE_LINUX)
    else()
        target_compile_definitions(liblua54 PUBLIC LUA_USE_MACOSX)
    endif()
endif()

target_include_directories(liblua54 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lua54)

add_executable(luac54 ${LUA54SRC} lua54/luac.c)
add_executable(lua54 lua54/lua.c)
set_target_properties(lua54 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "lua54"
    OUTPUT_NAME lua54)
target_link_libraries(lua54 liblua54)

# -----------------------------------------------------------------------------
# lua55
# -----------------------------------------------------------------------------
set(LUA55SRC
    lua55/lapi.c
    lua55/lapi.h   
    lua55/lauxlib.c
    lua55/lauxlib.h
    lua55/lbaselib.c
    lua55/lcode.c
    lua55/lcode.h  
    lua55/lcorolib.c
    lua55/lctype.c
    lua55/lctype.h 
    lua55/ldblib.c
    lua55/ldebug.c
    lua55/ldebug.h 
    lua55/ldo.c
    lua55/ldo.h    
    lua55/ldump.c
    lua55/lfunc.c
    lua55/lfunc.h  
    lua55/lgc.c
    lua55/lgc.h    
    lua55/linit.c
    lua55/liolib.c
    lua55/llex.c
    lua55/llex.h   
    lua55/llimits.h
    lua55/lmathlib.c
    lua55/lmem.c
    lua55/lmem.h    
    lua55/loadlib.c
    lua55/lobject.c
    lua55/lobject.h 
    lua55/lopcodes.c
    lua55/lopcodes.h
    lua55/loslib.c
    lua55/lparser.c
    lua55/lparser.h 
    lua55/lprefix.h 
    lua55/lstate.c
    lua55/lstate.h  
    lua55/lstring.c
    lua55/lstring.h 
    lua55/lstrlib.c
    lua55/ltable.c
    lua55/ltable.h
    lua55/ltablib.c
    lua55/ltm.c
    lua55/ltm.h
    lua55/lua.h
    lua55/luaconf.h
    lua55/lualib.h
    lua55/lundump.c
    lua55/lundump.h
    lua55/lutf8lib.c
    lua55/lvm.c
    lua55/lvm.h
    lua55/lzio.c
    lua55/lzio.h
)

if(WIN32)
    add_library(liblua55 SHARED ${LUA55SRC})
    target_compile_definitions(liblua55 PRIVATE LUA_BUILD_AS_DLL)
else()
    add_library(liblua55 STATIC ${LUA55SRC})
    target_link_libraries(liblua55 PUBLIC readline)
    if (NOT APPLE)
        target_link_libraries(liblua55 PUBLIC m dl -Wl,-E)
        target_compile_definitions(liblua55 PUBLIC LUA_USE_LINUX)
    else()
        target_compile_definitions(liblua55 PUBLIC LUA_USE_MACOSX)
    endif()
endif()

target_include_directories(liblua55 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lua55)

# add_executable(luac55 ${LUA55SRC} lua55/luac.c)
add_executable(lua55 lua55/lua.c)
set_target_properties(lua55 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "lua55"
    OUTPUT_NAME lua55)
target_link_libraries(lua55 liblua55)