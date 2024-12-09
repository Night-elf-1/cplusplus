// file1.cpp
#include "extern/globals.hpp"

// 定义全局变量
int sharedVar = 10;

// 定义全局函数
void modifySharedVar(int value) {
    sharedVar = value;
}