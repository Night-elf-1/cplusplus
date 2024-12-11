#include <iostream>
#include <string>

// 定义一个简单的类，带有一个明确的构造函数
class Person {
public:
    // 明确告诉编译器这个构造函数不应该用于隐式转换
    explicit Person(const std::string& name) : name_(name) {}

    // 获取 Person 的名字
    std::string getName() const { return name_; }

private:
    std::string name_;
};

int main() {
    // 尝试隐式转换将失败，因为构造函数是 explicit 的
    // Person implicitPerson = "John"; // 这将导致编译错误

    // 正确的方式是显式地调用构造函数
    Person explicitPerson("John");
    std::cout << "Person's name: " << explicitPerson.getName() << std::endl;

    // 显式构造也是允许的
    Person anotherPerson = Person("Alice");
    std::cout << "Another person's name: " << anotherPerson.getName() << std::endl;

    return 0;
}