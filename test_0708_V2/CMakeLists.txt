cmake_minimum_required(VERSION 3.15)

# 指定构建的项目名
project(test)

# add_executable(hello hello.cc)


# 可执行文件名称映射
# 方式1: 各个源文件之间使用空格间隔
# set(SRC_LIST add.c  div.c   main.c  mult.c  sub.c)
# 方式2: 各个源文件之间使用分号 ; 间隔
# set(SRC_LIST hello.cc; main.cc)


# 查找所有源文件，用SRC表示
# ${PROJECT_SOURCE_DIR}表示路径CMakeLists所在的路径
# ${CMAKE_CURRENT_SOURCE_DIR}表示CMakeLists所在的路径，和${PROJECT_SOURCE_DIR}一致
# 方式1
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
# 方式2
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)



# 可执行文件存放位置 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# set(EXECUTABLE_OUTPUT_PATH ../bin) #这个也可以，因为make时在build目录下，需要..



# 指定头文件的路径(这里只要指定目录，不需要指定具体文件)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)



# 可执行文件名称映射
# add_executable(main ${SRC})


#增加-std=c++17 指定CPP标准
set(CMAKE_CXX_STANDARD 17)


# 生成动态库 (生成到build目录下libhello.so，so表示动态库，ls显示为绿色表示有可执行权限)
add_library(helloShared SHARED ${SRC})

# 生成静态库（生成到build目录下libhello.a，a表示静态库，ls显示为白色表示没有可执行权限）
add_library(helloStatic STATIC ${SRC})

# 设置动态库/静态库生成的路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
