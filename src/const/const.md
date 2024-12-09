# const

在C++中，`const` 关键字有多个用途，主要用于定义常量、保证数据的不变性以及提高代码的可读性。

## 定义常量

`const` 可以用来定义常量值，这些值在初始化后不能被修改

```
const int MAX_USERS = 100; // 定义一个常量，其值不能被改变
```

## 修饰函数参数

当`const`用于函数参数时，它表示该参数在函数内部不能被修改。

```
void printMessage(const std::string& message) {
    // message 在这个函数内是只读的，不能被修改
}
```

## 修饰返回值

当`const`用于函数返回值时，它表示返回的值在表达式中是只读的。

```
const int getValue() {
    return 42; // 返回一个常量值
}
```

## 修饰成员变量和成员函数

在类中，`const` 可以修饰成员变量和成员函数，表示它们是不可变的。

```
class MyClass {
    const int value; // 常量成员变量，必须在构造函数初始化列表中初始化

public:
    MyClass(int v) : value(v) {} // 在构造函数初始化列表中初始化常量成员变量

    const int getValue() const { // 常量成员函数，不能修改任何成员变量
        return value;
    }
};	
```

```
const int getValue() const {
    return value;
}
```

这里的`const`有两个作用：

- **函数返回值**：第一个`const`修饰返回值，表示返回值是一个常量，不能被修改。这个`const`实际上是多余的，因为`int`是一个基本数据类型，它本身就是不可变的。对于基本数据类型来说，返回值前的`const`没有实际作用。
- **函数本身**：第二个`const`（位于函数参数列表之后）表示这是一个常量成员函数，它不会修改类的任何成员变量，并且可以被`const`对象调用。

## 修饰指针

`const` 可以修饰指针，表示指针指向的数据不能被修改，或者指针本身不能被修改。

```
const int* ptr; // ptr 指向的值不能被修改，但 ptr 可以指向其他地址

int* const ptr = &someInt; // ptr 指向的地址不能被修改，但可以通过 ptr 修改指向的值

const int* const ptr = &someInt; // ptr 指向的地址和值都不能被修改
```

## 修饰类类型

当`const`用于类类型时，它表示该类型的所有成员函数都是常量成员函数，即它们不会修改任何成员变量。

```
class ConstClass {
    int value;

public:
    ConstClass(int v) : value(v) {}

    void modifyValue(int v) {
        value = v; // 如果 ConstClass 被声明为 const，则此函数不能被调用
    }

    int getValue() const {
        return value;
    }
};

const ConstClass obj(10); // obj 是一个常量对象，不能调用非 const 成员函数
```

## 修饰数组

`const` 可以修饰数组，表示数组的元素不能被修改。

```
const int arr[] = {1, 2, 3}; // arr 是一个常量数组，其元素不能被修改
```

## 修饰模板参数

`const` 可以作为模板参数，表示模板参数是一个常量。

```
template <const int N>
void printArray(const int (&arr)[N]) {
    // ...
}
```

