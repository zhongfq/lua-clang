# lua-clang
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

- build on windows:
    ```sh
    mkdir build\vs-build && cd build\vs-build
    cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON -DENABLE_STATIC=STATIC ../..
    cmake --build . --config release --target luaclang
    ```

- build on mac:
    ```sh
    mkdir -p build/mac-build && cd build/mac-build
    cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON ../..
    cmake --build . --config release --target luaclang
    ```

- build on linux:
    ```sh
    mkdir -p build/linux-build && cd build/linux-build
    cmake -DLLVM_ENABLE_PROJECTS=clang -DLIBCLANG_BUILD_STATIC=ON ../..
    cmake --build . --config release --target luaclang
    ```

- you also can build lua:
    ```sh
    cmake --build . --config release --target lua
    cmake --build . --config release --target luac
    cmake --build . --config release --target liblua
    ```

how to use clang see [cocos-lua bindings geneator](https://github.com/zhongfq/cocos-lua/tree/v4/tools/lua-bindings).
