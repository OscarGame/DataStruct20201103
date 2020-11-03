

cmake_minimum_required(VERSION 3.8)
project(DataStruct20201103)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-std=c++11)


#set(ReflectiveSystemRootDir ${CMAKE_CURRENT_SOURCE_DIR})





message("===============start DataStruct======================")

#添加system的内容
#SET(system_source_dir ${CMAKE_SOURCE_DIR}/System)
#file(GLOB SystemSourceFiles "${system_source_dir}/*.*")


SET(source_dir ${CMAKE_SOURCE_DIR}/Sources)
#message("message ="${CMAKE_SOURCE_DIR}/Sources)
#添加当前cmakelist文件所在文件夹的所有文件


file(GLOB SourceFiles "${source_dir}/*.*")


AUX_SOURCE_DIRECTORY(. SRC_LIST)
add_executable(DataStruct ${SRC_LIST} ${SourceFiles})


message("===============end  DataStruct======================")