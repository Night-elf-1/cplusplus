# friend

​	在 C++ 中，`friend` 是一个关键字，它用于声明友谊关系，允许一个类（称为朋友类）或函数访问另一个类（称为被友元类）的私有（private）和保护（protected）成员。`friend` 关键字可以用于多种情况，包括非成员函数、成员函数、整个类等。

## 使用 `friend` 的原因

1. **访问控制**：允许非成员函数或另一个类的成员函数访问类的私有和保护成员，这在某些设计中是必要的，比如实现某些操作符重载、辅助函数或与其他类共享数据。
2. **设计灵活性**：`friend` 提供了一种方式，使得类的设计更加灵活，允许在不同的类之间共享数据和行为。

## 如何使用 `friend`

**friend函数**

```
class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // 声明一个非成员函数为朋友
    friend void displayValue(MyClass obj);
};

// 朋友函数实现
void displayValue(MyClass obj) {
    std::cout << "Value: " << obj.value << std::endl; // 直接访问私有成员
}
```

​	在这个例子中，`displayValue` 函数被声明为 `MyClass` 的朋友，因此它可以直接访问 `MyClass` 的私有成员 `value`。

**friend类**

```
class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // 声明另一个类为朋友
    friend class FriendClass;
};

class FriendClass {
public:
    void displayValue(MyClass obj) {
        std::cout << "Value: " << obj.value << std::endl; // 直接访问私有成员
    }
};
```

​	在这个例子中，`FriendClass` 被声明为 `MyClass` 的朋友，因此 `FriendClass` 的成员函数 `displayValue` 可以直接访问 `MyClass` 的私有成员 `value`。

## 注意事项

1. **封装破坏**：过度使用 `friend` 可能会破坏类的封装性，因为 `friend` 允许外部代码直接访问类的私有和保护成员。
2. **维护难度**：使用 `friend` 可能会增加代码的维护难度，因为朋友函数或类可以访问类的内部实现细节，这可能会导致代码之间的耦合度增加。
3. **继承和友元**：友元关系不会被继承。如果一个类派生自一个有朋友类的基类，派生类不会自动成为那些朋友类的友元。
4. **模板和友元**：在模板编程中，友元声明需要特别小心，因为模板实例化可能会导致友元关系不正确。