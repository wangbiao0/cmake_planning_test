# cmake_planning_test
cmake planning project test

```bash
git status  
git add .  
git commit -m "version 0.0.1"  
git push  
git push --set-upstream origin v1  
```



在此项目中使用了两个第三方库：EasyX 和 Egine 
使用EasyX时，将EasyX的库文件和头文件复制到MinGW的头文件和库文件内，使用时直接将其作为公共库链接即可，如下：  

```cmake
# 使用EasyX库的当级CMakeLists.txt
# 指定 show_result 库链接 easyx 库，并且将 show_result 作为公共依赖传递给依赖 show_result 的其他目标。
target_link_libraries(${PROJECT_NAME} PUBLIC easyx)
```

在使用Egine库时，可以任意位置放置Egine库的源码，然后使用CMake 脚本用于配置和查找 Eigen3 库，并在构建过程中输出相关信息，如下： 

```cmake
使用Egine库的当级CMakeLists.txt
# 指定 process 库链接 Eigne 库，并且将 process 作为公共依赖传递给依赖 process 的其他目标。  
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)  

# 最上级CMakeLists.txt
set(EIGEN3_INCLUDE_DIR "D:/Programs/eigen-3.4.0")  # eigen 是一个矩阵计算相关的库  
list(APPEND CMAKE_MODULE_PATH "${EIGEN3_INCLUDE_DIR}/cmake") # 通过追加将 Eigen3 库的 CMake 配置目录添加到 CMake 的模块路径中。  
message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")  # 向命令行打印信息  

find_package(Eigen3 3.4 REQUIRED) # 使用 find_package 查找指定版本(3.4)的 Eigen3 库  
if(TARGET Eigen3::Eigen)  
    message(STATUS "******* Egien3 3.4 found in ${EIGEN3_INCLUDE_DIR} *******")  
endif()  
```

