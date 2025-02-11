cmake_minimum_required(VERSION 3.29.0)
project(planning)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) # 动态库和可执行文件都放在bin目录下
# windows: CMAKE_RUNTIME_OUTPUT_DIRECTORY
# linux  : CMAKE_LIBRARY_OUTPUT_DIRECTORY

# 静态库：CMAKE_ARCHIVE_OUTPUT_DIRECTORY  # 静态库只指定库文件，不会指定可执行文件

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)
# 将src下面的cpp文件生成一个动态库
add_library(common
    SHARED
    ${SRC_LISTS}
)

# 链接动态库和include下的头文件
target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
add_executable(planning_main planning_main.cpp)

# 链接动态库和include下的头文件
target_include_directories(planning_main
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# 链接可执行文件和动态库
target_link_libraries(planning_main
PUBLIC
common
)
# 可执行文件运行时需要加载动态库，所以，两者需要在同一个文件夹下