#include <iostream>

// 基类 Shape
class Shape {
public:
    // 虚函数，用于计算面积
    virtual double area() const {
        return 0;
    }

    // 虚析构函数
    virtual ~Shape() {}
};

// 派生类 Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // 覆盖基类的虚函数
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // 覆盖基类的虚函数
    double area() const override {
        return width * height;
    }
};

// 函数，接受 Shape 指针并计算面积
void calculateArea(const Shape* shape) {
    std::cout << "Area: " << shape->area() << std::endl;
}

/**
 * @param Shape 是一个基类，它声明了一个虚函数 area() 用于计算形状的面积，以及一个虚析构函数。
 * @param Circle @param Rectangle 是从 Shape 派生的两个类，它们各自覆盖了 area() 函数，以计算圆形和矩形的面积。
 * @param calculateArea 函数接受一个指向 Shape 的指针，并调用 area() 函数来计算和输出面积。
 */

int main() {
    // 创建 Circle 和 Rectangle 对象
    Circle circle(5);
    Rectangle rectangle(4, 6);

    // 将对象的地址传递给函数
    calculateArea(&circle);   // 应该输出 Circle 的面积
    calculateArea(&rectangle); // 应该输出 Rectangle 的面积

    return 0;
}