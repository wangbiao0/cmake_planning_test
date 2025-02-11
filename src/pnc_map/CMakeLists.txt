project(pnc_map)

#创建一个共享库（pnc_map），该库的源文件是 pnc_map.cpp。
# 最终 CMake 会根据此规则编译源文件并生成共享库文件，库文件名通常为 libpnc_map.so（Linux）或 pnc_map.dll（Windows）。
add_library(${PROJECT_NAME}
SHARED
pnc_map.cpp
)
# cmake会默认在同级目录搜索头文件，所以不用指定头文件的搜索路径