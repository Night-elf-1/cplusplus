# virtual

**在C++中，`virtual` 关键字用于声明虚函数，它允许我们在派生类（子类）中覆盖（override）基类中的函数。使用虚函数是实现多态性（Polymorphism）的基础，多态性是面向对象编程的四大基本特征之一，指的是同一个函数或方法在不同对象中可以有不同的实现。**

## 虚函数的声明

在基类中，你可以通过在函数声明前加上 `virtual` 关键字来声明一个虚函数：

```
class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }
};
```

## 覆盖虚函数

在派生类中，你可以提供一个与基类中虚函数**具有相同签名的函数来覆盖**它：

```
class Derived : public Base {
public:
    void show() override { // 使用override关键字明确表示覆盖基类函数
        std::cout << "Derived show" << std::endl;
    }
};
```

使用 `override` 关键字是一个好的实践，因为它可以让编译器检查你是否真的覆盖了一个基类中的虚函数，如果没有，编译器会报错。

## 虚函数调用

当你通过基类的指针或引用调用一个虚函数时，如果对象实际上是一个派生类的对象，那么会调用派生类的版本：

```
Base* b = new Derived();
b->show(); // 调用Derived::show()
delete b;
```

在这个例子中，尽管指针 `b` 是基类 `Base` 的类型，但是它实际上指向一个 `Derived` 类的对象。因此，调用 `show()` 函数时，会调用 `Derived` 类中的版本。

## 虚析构函数

虚析构函数是非常重要的，因为它确保了当你删除一个基类指针时，派生类的析构函数也会被调用，这样可以正确地清理资源：

```
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; // 首先调用Derived的析构函数，然后调用Base的析构函数
    return 0;
}
```

## 纯虚函数和抽象类

你可以将一个虚函数声明为纯虚函数，这样包含纯虚函数的类就成为了抽象类，这意味着你不能实例化这样的类，它只能作为基类来使用：

```
class Base {
public:
    virtual void pureVirtual() = 0; // 纯虚函数
};

// 你不能实例化Base，因为它包含纯虚函数
```

任何包含纯虚函数的派生类都必须提供纯虚函数的实现，否则它也将成为抽象类。