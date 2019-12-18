#include <iostream>

using namespace std;

// определение структуры Point уже подключено
struct Point {
    constexpr Point(double x, double y)
            : x(x), y(y) {}
    double x = 0;
    double y = 0;
};

//constexpr double getX() const { return x; }
//constexpr double getY() const { return y; }

// сложение
constexpr Point operator+(Point const &p1, Point const &p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// вычитание
constexpr Point operator-(Point const &p1, Point const &p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}

// скалярное произведение
constexpr double operator*(Point const &p1, Point const &p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

void testAll() {
    constexpr size_t size = static_cast<size_t>(Point(2, 4) * Point(4, 3));
    int m[size]; // массив из 20 элементов
}

int main() {
    testAll();
    return 0;
}