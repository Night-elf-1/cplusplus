# 纯虚函数和抽象类

## 纯虚函数

纯虚函数是一种没有具体实现的虚函数，它在基类中声明，要求任何派生类都必须提供该函数的具体实现。纯虚函数的声明方式是在函数声明的末尾加上 `= 0`。

```
virtual 返回类型 函数名称(参数列表) = 0;
```

#### 作用

​	**强制派生类覆盖：**纯虚函数迫使所有派生类都必须覆盖（override）这个函数，否则派生类也会变成抽象类。

​	**定义接口：**纯虚函数用于定义一个接口，让不同的派生类按照这个接口实现自己的功能。

#### 示例

```
class Shape {
public:
    virtual void draw() const = 0; // 纯虚函数
};

class Circle : public Shape {
public:
    void draw() const override { /* 绘制圆形 */ }
};

class Square : public Shape {
public:
    void draw() const override { /* 绘制正方形 */ }
};
```

# 抽象类

抽象类是包含至少一个纯虚函数的类。由于抽象类不能被直接实例化，它通常用作基类，以确保派生类遵循某些接口规范。

#### 特点

1. **不能实例化**：你不能创建抽象类的实例。
2. **可以包含数据成员和普通成员函数**：除了纯虚函数，抽象类也可以包含数据成员和普通成员函数。
3. **可以有构造函数和析构函数**：抽象类可以有构造函数和析构函数，这对于初始化和清理资源非常有用。

#### 示例

```
class AbstractClass {
public:
    AbstractClass() {
        // 构造函数
    }

    virtual ~AbstractClass() {
        // 析构函数
    }

    virtual void pureVirtualFunc() = 0; // 纯虚函数
    void commonFunc() {
        // 普通成员函数
    }
};
```



# 纯虚函数和抽象类的关系

- **抽象类必须包含至少一个纯虚函数**：如果一个类包含纯虚函数，那么它自动成为抽象类。
- **纯虚函数是抽象类的一部分**：纯虚函数用于定义抽象类中的接口，确保派生类提供具体的实现。

# 使用场景

1. **代码复用**：当你有多个类需要实现相同功能时，可以定义一个包含纯虚函数的抽象基类，然后让这些类继承自这个基类。
2. **接口实现**：纯虚函数和抽象类允许你定义一个接口，让不同的类以不同的方式实现这个接口。
3. **设计模式**：在许多设计模式中，如工厂模式、策略模式等，抽象类和纯虚函数用于定义通用接口和行为。