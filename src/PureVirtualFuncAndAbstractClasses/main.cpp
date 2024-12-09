#include <iostream>
#include <memory>

// 定义一个抽象类 Animal
class Animal {
public:
    // 纯虚函数，要求派生类必须实现这个函数
    virtual void makeSound() const = 0;

    // 虚析构函数，确保派生类的析构函数被调用
    virtual ~Animal() {}
};

// Dog 类继承自 Animal
class Dog : public Animal {
public:
    // Dog 必须实现 makeSound 函数
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// Cat 类继承自 Animal
class Cat : public Animal {
public:
    // Cat 必须实现 makeSound 函数
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

// 一个函数，接受 Animal 类型的指针，并调用 makeSound 函数
void makeAnimalSound(const std::shared_ptr<Animal>& animal) {
    animal->makeSound();
}

int main() {
    // 创建 Dog 和 Cat 的对象，分别存储在智能指针中
    std::shared_ptr<Animal> myDog = std::make_shared<Dog>();
    std::shared_ptr<Animal> myCat = std::make_shared<Cat>();

    // 使用智能指针调用 makeAnimalSound 函数
    makeAnimalSound(myDog); // 输出: Woof! Woof!
    makeAnimalSound(myCat); // 输出: Meow! Meow!

    return 0;
}