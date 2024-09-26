
Example LLVM passes - based on LLVM 8-18, LLVM7- is not tested.

## build

Build LLVM
```bash
cd /path/to/llvm
cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS="clang;lld" -DCMAKE_BUILD_TYPE=Debug 
cmake --build build
```

Build Demo
```bash
cd /path/to/llvm-pass-hikari
export LLVM_DIR=/path/to/llvm/build/lib/cmake/llvm
cmake -B build --fresh
cmake --build build
```

## Test

Test environment:   MacOS 13.x

### Test with clang

```bash
# for LLVM<=12      Legacy Pass
llvm12/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -Xclang -load -Xclang build/MyPassDemo12.dylib /tmp/1.cpp
# for LLVM<=12      Legacy Pass (Equal to above)
llvm12/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fplugin=build/MyPassDemo12.dylib /tmp/1.cpp
# for LLVM=9/10/11  New Pass (O3 required)
llvm11/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fexperimental-new-pass-manager -fpass-plugin=build/MyPassDemo11.dylib /tmp/1.cpp -O3
# for LLVM=12       New Pass
llvm12/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fexperimental-new-pass-manager -fpass-plugin=build/MyPassDemo12.dylib /tmp/1.cpp
# for LLVM=13/14    Legacy Pass
llvm13/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -flegacy-pass-manager -fplugin=build/MyPassDemo13.dylib /tmp/1.cpp
# for LLVM=13/14    New Pass
llvm13/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fpass-plugin=build/MyPassDemo13.dylib /tmp/1.cpp
# for LLVM>=15      New Pass
llvm15/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fpass-plugin=build/MyPassDemo15.dylib /tmp/1.cpp
```

### Test with opt

```bash
# for LLVM all versions
llvm8/build/bin/clang -emit-llvm -c -isysroot `xcrun --sdk macosx --show-sdk-path` -o /tmp/test.bc /tmp/test.cpp
llvm8/build/bin/opt -load-pass-plugin build/MyPassDemo8.dylib -passes all -S -o /tmp/test_new.bc /tmp/test.bc
```

NOTICE: opt support ll as input from LLVM15  

```bash
llvm15/build/bin/clang -emit-llvm -S -isysroot `xcrun --sdk macosx --show-sdk-path` -o /tmp/test.ll /tmp/test.cpp
llvm15/build/bin/opt -load-pass-plugin build/MyPassDemo15.dylib -passes all -S -o /tmp/test_new.ll /tmp/test.ll 
```

### compile

* c/cpp -> bc `clang -emit-llvm -c`
* c/cpp -> ll `clang -emit-llvm -S`
* c/cpp -> obj `clang -c`
* ll/bc -> obj/asm `llc`
* bc/obj -> bin `lld`
* ll/bc -> ll `opt -S` (ll -> ll in LLVM>=15)
* ll/bc -> bc `opt` (ll -> bc in LLVM>=15)
* ll -> bc `llvm-as`
* bc -> ll `llvm-dis`
* c/cpp/obj/asm -> bin `clang`

