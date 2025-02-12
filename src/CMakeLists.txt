project(planning_main)

add_subdirectory(pnc_map)
add_subdirectory(process)
add_subdirectory(show_result)

# 生成可执行文件
add_executable(${PROJECT_NAME} planning_main.cpp)

# 指定头文件 process.h 的搜索路径 
target_include_directories(${PROJECT_NAME}
PUBLIC
${Process_Dir} # ${CMAKE_SOURCE_DIR}/src/process
)

# 链接动态库 process
target_link_libraries(${PROJECT_NAME}
PUBLIC
process
)


# 指定头文件 show_result.h 的搜索路径
target_include_directories(${PROJECT_NAME}
PUBLIC
${CMAKE_SOURCE_DIR}/src/show_result
)


# 链接动态库 show_result
target_link_libraries(${PROJECT_NAME}
PUBLIC
show_result
)