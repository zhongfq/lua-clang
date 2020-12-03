# lua-clang
[![Linux Build Status](https://github.com/zhongfq/lua-clang/workflows/linux/badge.svg)](https://github.com/zhongfq/lua-clang/actions?query=workflow:linux)
[![Windows Build Status](https://github.com/zhongfq/lua-clang/workflows/macos/badge.svg)](https://github.com/zhongfq/lua-clang/actions?query=workflow:macos)
[![Macos Build Status](https://github.com/zhongfq/lua-clang/workflows/windows/badge.svg)](https://github.com/zhongfq/lua-clang/actions?query=workflow:windows)

build clang for lua

## how to use

- install cmake and python

- clone lua-clang
    ```sh
    git clone https://github.com/zhongfq/lua-clang.git
    cd lua-clang
    git submodule init
    git submodule update
    ```

- build on windows cmd, mac or linux terminal:
    ```sh
    mkdir build && cd build
    cmake ../.. -DCMAKE_BUILD_TYPE=Release
    # cmake ../.. -DCMAKE_BUILD_TYPE=Release -DLUA=lua53
    cmake --build . --config Release --target luaclang
    ```

- you also can build lua:
    ```sh
    cmake --build . --config release --target lua
    cmake --build . --config release --target luac
    cmake --build . --config release --target liblua
    ```

how to use clang see [cocos-lua bindings geneator](https://github.com/zhongfq/cocos-lua/tree/v4/tools/lua-bindings).
