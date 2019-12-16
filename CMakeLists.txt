# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeProject2")

# 包含子项目。
add_subdirectory ("CMakeProject2")
add_subdirectory ("shared_ptr")
add_subdirectory ("tuple")
add_subdirectory ("stack")
add_subdirectory ("classConstruct")
add_subdirectory ("CopyTest")
add_subdirectory ("ChronoTest")
add_subdirectory ("RecursionProblems")
add_subdirectory ("QuickSort")
add_subdirectory ("MapTest")

