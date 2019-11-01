# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("cppNote")

# 包含子项目。
add_subdirectory ("cppNote")
add_subdirectory ("shared_ptr")