cmake_minimum_required(VERSION 3.6)
project(BasicFS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DiskManager.cpp DiskManager.h BasicFileSystem.cpp BasicFileSystem.h FileSystem.cpp FileSystem.h SuperBlock.cpp SuperBlock.h Block.cpp Block.h)
add_executable(BasicFS ${SOURCE_FILES})