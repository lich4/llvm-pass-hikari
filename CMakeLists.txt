cmake_minimum_required(VERSION 3.6)
project(MyPassDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")

find_package(LLVM REQUIRED CONFIG)              # LLVMConfig.cmake初始化环境

list(APPEND CMAKE_MODULE_PATH "${LLVM_DIR}")    # 兼容LLVM<=13

include(AddLLVM)                                # 导入add_llvm_pass_plugin函数
include(HandleLLVMOptions)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS}) 

if(NOT COMMAND add_llvm_pass_plugin)            # 兼容LLVM<=9
  message(WARNING "add_llvm_pass_plugin not exist")
  function(add_llvm_pass_plugin name)         
    cmake_parse_arguments(ARG "NO_MODULE" "SUBPROJECT" "" ${ARGN})
    set(link_into_tools_default OFF)
    add_llvm_library(${name} MODULE ${ARG_UNPARSED_ARGUMENTS})
    message(STATUS "Registering ${name} as a pass plugin (static build: ${LLVM_${name_upper}_LINK_INTO_TOOLS})")
  endfunction(add_llvm_pass_plugin)
endif()

add_llvm_pass_plugin(MyPassDemo${LLVM_VERSION_MAJOR}
    demo.cpp
)

