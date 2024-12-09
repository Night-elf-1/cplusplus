// file2.cpp
#include "extern/globals.hpp"
#include <iostream>

// 这个文件使用 extern 来声明全局变量，并在 main 函数中访问它。
// sharedVar在file1.cpp中定义，

int main() {
    // 访问全局变量
    std::cout << "Initial sharedVar: " << sharedVar << std::endl;

    // 修改全局变量
    modifySharedVar(20);

    // 再次访问全局变量
    std::cout << "Modified sharedVar: " << sharedVar << std::endl;

    return 0;
}