cmake_minimum_required(VERSION 3.29.0)
project(planning)
set(CMAKE_CXX_STANDARD 17)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) # 动态库和可执行文件都放在bin目录下
# windows: CMAKE_RUNTIME_OUTPUT_DIRECTORY
# linux  : CMAKE_LIBRARY_OUTPUT_DIRECTORY
# 静态库：CMAKE_ARCHIVE_OUTPUT_DIRECTORY  # 静态库只指定库文件，不会指定可执行文件

# 查找指定目录（这里是src目录中的所有源文件（例如 .cpp 文件），并将它们的路径存储在变量 SRC_LISTS 中。
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)
# 将src下面的cpp文件编译创建一个名为 common 的动态库（SHARED）
add_library(common
    SHARED
    ${SRC_LISTS}
)

# 设置了 common 动态库的头文件路径为 include 目录
target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
# 定义了一个名为 planning_main 的可执行文件，源文件为 planning_main.cpp。该可执行文件将在项目编译时生成。
add_executable(planning_main planning_main.cpp)

# 设置了可执行文件 planning_main 的头文件搜索路径为 include 目录
target_include_directories(planning_main
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# 链接了 planning_main 可执行文件和 common 动态库
target_link_libraries(planning_main
PUBLIC
common
)
# 可执行文件运行时需要加载动态库，所以，两者需要在同一个文件夹下