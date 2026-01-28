#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point
{
    /* data */
    double x, y;
};

double calculateDistance(Point &p1, Point &p2){
    return std::hypot(p1.x - p2.x, p1.y- p2.y);
}

int main(int argc, char const *argv[])
{
    // 模拟一条路径
    vector<Point> path = {{0, 0}, {0.5, 0.5}, {1, 1}, {1.5, 1.5}, {2.0, 1.0}, {2.5, 0.5}, {3.0, 0.0}}; 
    

    return 0;
}
