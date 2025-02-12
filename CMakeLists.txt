cmake_minimum_required(VERSION 3.29.0)
project(planning
    VERSION 0.0.1
    DESCRIPTION "a demo of cmake planning"
    HOMEPAGE_URL ""
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

# 变量和目录设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # PROJECT_SOURCE_DIR
set(Process_Dir ${CMAKE_SOURCE_DIR}/src/process)
set(Pnc_Map_Dir ${CMAKE_SOURCE_DIR}/src/pnc_map)
set(Show_Result_Dir ${CMAKE_SOURCE_DIR}/src/show_result)

# 第三方库
set(EIGEN3_INCLUDE_DIR "D:/Programs/eigen-3.4.0")  # eigen 是一个矩阵计算相关的库
list(APPEND CMAKE_MODULE_PATH "${EIGEN3_INCLUDE_DIR}/cmake") # 通过追加将 Eigen3 库的 CMake 配置目录添加到 CMake 的模块路径中。
message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")  # 向命令行打印信息

find_package(Eigen3 3.4 REQUIRED) # 使用 find_package 查找指定版本(3.4)的 Eigen3 库
if(TARGET Eigen3::Eigen)
    message(STATUS "******* Egien3 3.4 found in ${EIGEN3_INCLUDE_DIR} *******")
endif()


# 添加子目录
add_subdirectory(src)