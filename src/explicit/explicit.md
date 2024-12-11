# `explicit`

​	**在 C++ 中，`explicit` 关键字用于类中的构造函数，它阻止了编译器使用这些构造函数进行隐式类型转换。`explicit` 关键字的主要目的是防止意外的类型转换，这可以提高程序的健壮性和可读性。**

1. **防止隐式转换**：没有 `explicit` 关键字的单参数构造函数可能会被编译器用来隐式地将参数类型转换为类类型，这可能会导致不易察觉的类型转换错误。
2. **提高代码清晰度**：当构造函数被标记为 `explicit` 时，任何将参数转换为类类型的尝试都必须是显式的，这使得代码的意图更加明确。

## 如何使用 `explicit`

​	`explicit` 关键字被放置在构造函数声明的开始处，如下所示：

```
class MyClass {
public:
    explicit MyClass(int value) {
        // 构造函数实现
    }
};
```

​	在这个例子中，`MyClass` 的构造函数被声明为 `explicit`，因此不能被用来隐式地将 `int` 类型转换为 `MyClass` 类型。

## 示例

```
#include <iostream>

class MyClass {
public:
    explicit MyClass(int value) : val(value) {}

    // 显示转换
    operator int() const { return val; }

private:
    int val;
};

int main() {
    MyClass obj1(10); // 正确：显式构造
    int i = MyClass(20); // 错误：隐式构造被禁止

    // 显示转换
    int j = static_cast<int>(obj1); // 正确：显示转换
    std::cout << "j: " << j << std::endl;

    return 0;
}
```

​	在这个例子中，尝试将 `MyClass(20)` 隐式转换为 `int` 类型会失败，因为构造函数是 `explicit` 的。但是，你可以使用显示转换（如 `static_cast<int>(obj1)`）来获取 `MyClass` 对象的 `int` 值。