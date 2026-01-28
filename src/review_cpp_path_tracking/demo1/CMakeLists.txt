# 定义该模块的源文件
set(SOURCES
    main.cpp
)

# 创建可执行文件 (名称为 extern_demo)
add_executable(path_tracking_demo1 ${SOURCES})

# 如果需要链接库（比如 pthread），只需在此处针对该目标设置
# target_link_libraries(extern_demo PRIVATE Threads::Threads)