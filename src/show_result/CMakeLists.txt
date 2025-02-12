project(show_result)

#创建一个共享库（show_result），该库的源文件是 show_result.cpp。
add_library(${PROJECT_NAME} SHARED show_result.cpp)

# 头文件搜索,在process下搜索头文件
#target_include_directories(${PROJECT_NAME} PUBLIC ${Process_Dir})

# 指定 show_result 库链接 process 库，并且将 show_result 作为公共依赖传递给依赖 show_result 的其他目标。
#target_link_libraries(${PROJECT_NAME} PUBLIC process)

# 指定 show_result 库链接 easyx 库，并且将 show_result 作为公共依赖传递给依赖 show_result 的其他目标。
target_link_libraries(${PROJECT_NAME} PUBLIC easyx)

