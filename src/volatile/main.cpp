#include <iostream>

volatile int sharedVar = 0;

void modifySharedVar() {
    sharedVar = 42; // 修改共享变量
}

int main() {
    std::cout << "Initial value: " << sharedVar << std::endl;

    modifySharedVar();

    std::cout << "Modified value: " << sharedVar << std::endl;

    return 0;
}