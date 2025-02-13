project(map_test)

add_executable(${PROJECT_NAME} map_test.cpp)

# 搜索头文件 pnc_map.h
target_include_directories(${PROJECT_NAME} PUBLIC ${Pnc_Map_Dir})

# 链接库文件 pnc_map
target_link_libraries(${PROJECT_NAME} PUBLIC pnc_map)

# 添加测试, 设置测试名称为map_info_test
add_test(
    NAME map_info_test
    COMMAND ${PROJECT_NAME}
)