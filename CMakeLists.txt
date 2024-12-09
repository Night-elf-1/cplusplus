cmake_minimum_required(VERSION 3.10)
project(cplusplus)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find_package(PythonLibs REQUIRED)

# 指定头文件搜索路径
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    # ${PYTHON_INCLUDE_DIRS}
)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 指定源文件
set(INLINE src/inline/main.cpp)
set(FUNCPOINTER src/funcPointer/main.cpp)
set(PUREVIRTUALFUNCANDABSTRACTCLASSES src/PureVirtualFuncAndAbstractClasses/main.cpp)
set(CONST src/const/main.cpp)
set(VIRTUAL src/virtual/main.cpp)
set(VOLATILE src/volatile/main.cpp)
set(ASSERT src/assert/main.cpp)
set(EXTERN src/extern/file1.cpp src/extern/file2.cpp)

# 添加测试程序的可执行文件
add_executable(inline ${INLINE})
add_executable(funcPointer ${FUNCPOINTER})
add_executable(pureVirtualFuncAndAbstractClasses ${PUREVIRTUALFUNCANDABSTRACTCLASSES})
add_executable(const ${CONST})
add_executable(virtual ${VIRTUAL})
add_executable(volatile ${VOLATILE})
add_executable(assert ${ASSERT})
add_executable(extern ${EXTERN})

# 如果您的项目依赖于Eigen库，并且Eigen库位于include目录下
# find_package(Eigen3 REQUIRED)
# if(EIGEN3_FOUND)
#     include_directories(${EIGEN3_INCLUDE_DIR})
#     target_link_libraries(processData 
#                         ${EIGEN3_LIBRARIES}                    
#                         ${PYTHON_LIBRARIES}
#                         python3.10.so
#                         pthread
#                         dl
#     )
# else()
#     message(WARNING "Eigen3 not found. Please specify the path to Eigen3.")
# endif()
