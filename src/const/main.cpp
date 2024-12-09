#include <iostream>
#include <string>

// 定义一个名为Person的类
class Person {
private:
    std::string name; // 姓名成员变量
    int age;          // 年龄成员变量

public:
    // 构造函数
    Person(const std::string& name, int age) : name(name), age(age) {}

    // 获取姓名的常量成员函数
    std::string getName() const {
        return name; // 返回姓名，不修改任何成员变量
    }

    // 获取年龄的常量成员函数
    int getAge() const {
        return age; // 返回年龄，不修改任何成员变量
    }

    // 修改年龄的非常量成员函数
    void setAge(int newAge) {
        age = newAge; // 修改年龄
    }
};

int main() {
    // 创建一个const对象p1，表示不能通过p1调用任何非常量成员函数
    const Person p1("Alice", 30);

    // 以下语句是合法的，因为getName是一个常量成员函数
    std::cout << "Name: " << p1.getName() << std::endl;

    // 以下语句是非法的，因为setAge不是一个常量成员函数
    // p1.setAge(31); // 错误：不能在const对象上调用非常量成员函数

    // 创建一个非const对象p2
    Person p2("Bob", 25);

    // 以下语句是合法的，因为p2不是const对象
    p2.setAge(26); // 修改p2的年龄

    // 以下语句是合法的，因为getAge是一个常量成员函数
    std::cout << "Age: " << p2.getAge() << std::endl;

    return 0;
}