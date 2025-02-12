project(process)

#创建一个共享库（process），该库的源文件是 process.cpp。
add_library(${PROJECT_NAME} SHARED process.cpp)

# 头文件搜索 pnc_map.h
target_include_directories(${PROJECT_NAME} PUBLIC ${Pnc_Map_Dir})

# 指定 process 库链接 pnc_map 库，并且将 process 作为公共依赖传递给依赖 process 的其他目标。
target_link_libraries(${PROJECT_NAME} PUBLIC pnc_map)

# 指定 process 库链接 Eigne 库，并且将 process 作为公共依赖传递给依赖 process 的其他目标。
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)


