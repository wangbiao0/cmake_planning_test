project(planning_main)

add_subdirectory(pnc_map)
add_subdirectory(process)

# 生成可执行文件
add_executable(${PROJECT_NAME} planning_main.cpp)

# 指定头文件的搜索路径
target_include_directories(${PROJECT_NAME}
PUBLIC
${Process_Dir} # ${CMAKE_SOURCE_DIR}/src/process
)

# 链接动态库
target_link_libraries(${PROJECT_NAME}
PUBLIC
process
)