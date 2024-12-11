#include <iostream>
#include <string>

// Person 类定义
class Person {
private:
    std::string name; // 私有数据成员

public:
    Person(const std::string& name) : name(name) {}

    // 声明 Printer 为友元类，允许 Printer 访问 Person 的私有成员
    friend class Printer;
};

// Printer 类定义
class Printer {
public:
    // 访问 Person 的私有成员的函数
    void printName(const Person& person) {
        std::cout << "Person's name: " << person.name << std::endl;
    }
};

int main() {
    Person person("John Doe");
    Printer printer;

    // 使用 Printer 对象访问 Person 的私有成员
    printer.printName(person);

    return 0;
}