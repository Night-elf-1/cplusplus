# sizeof

**`sizeof` 是一个非常有用的工具，可以帮助你理解数据类型在内存中的布局，优化内存使用，以及进行跨平台兼容性检查**

**`sizeof` 是 C++ 中的一个编译时运算符，它可以用于获取任何数据类型或对象在内存中所占的字节数**

## **基本数据类型**：

可以计算基本数据类型（如 `int`、`float`、`double`、`char` 等）的大小

```
sizeof(int); // 通常返回 4 字节
sizeof(float); // 通常返回 4 字节
sizeof(double); // 通常返回 8 字节
sizeof(char); // 返回 1 字节
```

## **数组**：

可以计算数组的总大小，即数组中所有元素的大小之和

```
int arr[10];
sizeof(arr); // 返回整个数组的大小，即 10 个 int 的大小
sizeof(arr) / sizeof(arr[0]); // 返回数组的元素个数
```

## **指针类型：**

可以计算指针本身的大小，而不是指针所指向的数据的大小

```
int *p;
sizeof(p); // 返回指针的大小，通常是 4 字节或 8 字节，取决于系统架构
```

## 类：

```
#include <iostream>

struct MyStruct {
    int a;
    char b;
    double c;
};

int main() {
    std::cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << std::endl;
    return 0;
}
```

输出 `MyStruct` 的大小，这个大小包括了所有数据成员的大小加上必要的填充