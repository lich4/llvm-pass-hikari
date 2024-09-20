
Example LLVM passes - based on LLVM 12-18, LLVM11- is not tested.

## build

```bash
export LLVM_DIR=/path/to/llvm/build/lib/cmake/llvm
cmake -B build --fresh
cmake --build build
```

## Test

Test environment:   MacOS 13.x

### Test with clang

```bash
# for LLVM<=12      Legacy Pass
llvm12/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -Xclang -load -Xclang build/MyPassDemo12.dylib /tmp/test.cpp
# equal to above
llvm12/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fplugin=build/MyPassDemo12.dylib /tmp/test.cpp

# for LLVM=13/14    Legacy Pass
llvm13/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -flegacy-pass-manager -fplugin=build/MyPassDemo13.dylib /tmp/test.cpp

# for LLVM=13/14    New Pass
llvm13/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fpass-plugin=build/MyPassDemo13.dylib /tmp/test.cpp

# for LLVM>=15      New Pass
llvm15/build/bin/clang -isysroot `xcrun --sdk macosx --show-sdk-path` -fpass-plugin=build/MyPassDemo15.dylib /tmp/test.cpp
```

### Test with opt

NOTICE: opt support ll as input from LLVM15 
```bash
llvm15/build/bin/clang -S -emit-llvm -isysroot `xcrun --sdk macosx --show-sdk-path` -o /tmp/test.ll /tmp/test.cpp
llvm15/build/bin/opt -load-pass-plugin build/MyPassDemo15.dylib -passes all -S -o /tmp/test_new.ll /tmp/test.ll 
```

