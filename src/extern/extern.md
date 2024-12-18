# extern

**在 C 和 C++ 中，`extern` 关键字用于声明一个变量或函数是从另一个文件或编译单元中引用过来的。它告诉编译器，所声明的变量或函数的定义存在于程序的其他地方。`extern` 的主要用途是用于在多个文件之间共享全局变量和函数。**

## 全局变量的声明和定义

1. **定义**：全局变量只能在一个编译单元中定义一次，但可以使用 `extern` 关键字在其他编译单元中声明，以便在这些单元中使用该变量。
2. **声明**：当一个全局变量在另一个文件中定义时，你可以在当前文件中使用 `extern` 来声明它，这样你就可以在当前文件中访问该变量。

### 示例

假设有两个文件 `file1.cpp` 和 `file2.cpp`

**file1.cpp:**

```
// 定义一个全局变量
int globalVar = 42;
```

**file2.cpp:**

```
// 声明一个在 file1.cpp 中定义的全局变量
extern int globalVar;

#include <iostream>

int main() {
    // 使用全局变量
    std::cout << "Global variable value: " << globalVar << std::endl;
    return 0;
}
```

在这个例子中，`globalVar` 在 `file1.cpp` 中定义，并在 `file2.cpp` 中通过 `extern` 声明。这样，`main` 函数就可以访问在 `file1.cpp` 中定义的 `globalVar`。



- **在 C++ 中，通常使用头文件（`.h` 或 `.hpp`）来声明函数和类，而不是 `extern`。头文件中包含了函数原型和类的声明，而定义则放在 `.cpp` 文件中。**

- **`extern` 在 C++ 中主要用于声明在 C 语言库中定义的变量和函数，因为 C 语言库通常不使用头文件。**

- **在 C++ 中，如果你在头文件中声明了一个 `extern` 变量，实际上你是在告诉编译器这个变量的定义在其他地方，编译器会在整个程序中只保留一个定义。**

- **使用 `extern` 时，变量或函数的定义必须在程序的某个地方存在，否则链接器会报错。**



**全局变量需要在声明时使用 `extern`，因为它告诉编译器变量的定义在别处。如果一个全局变量在多个文件中使用，它必须在其中一个文件中定义，并在其他文件中用 `extern` 声明。**