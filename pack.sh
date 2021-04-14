#!/bin/bash

mkdir -p build/lib/lua54/windows
mkdir -p build/lib/lua54/linux
mkdir -p build/lib/lua54/macosx

cp -fv build/mac-build/clang.so build/lib/lua54/macosx
cp -fv build/linux-build/clang.so build/lib/lua54/linux
cp -fv build/win32-build/Release/clang.dll build/lib/lua54/windows

mkdir -p build/lib/lua53/windows
mkdir -p build/lib/lua53/linux
mkdir -p build/lib/lua53/macosx

cp -fv build/mac-build-lua53/clang.so build/lib/lua53/macosx
cp -fv build/linux-build-lua53/clang.so build/lib/lua53/linux
cp -fv build/win32-build-lua53/Release/clang.dll build/lib/lua53/windows