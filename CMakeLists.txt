cmake_minimum_required(VERSION 3.6)
project(MyPassDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Release")

find_package(LLVM REQUIRED CONFIG) # 引入LLVMConfig.cmake以初始化LLVM相关变量

list(APPEND CMAKE_MODULE_PATH "${LLVM_DIR}") # 不加会导致低版本LLVM cmake失败

include(AddLLVM)                # 引入AddLLVM.cmake以导入add_llvm_pass_plugin函数
include(HandleLLVMOptions)      # 不加会导致低版本LLVM cmake失败

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_llvm_pass_plugin(MyPassDemo${LLVM_VERSION_MAJOR}
    demo.cpp
)