#include <iostream>

int main() {
    return 0;
}

/*
 * В некоторых случаях можно избежать использования RTTI. В этом примере показывается,
 * как можно избежать использования RTTI при реализации мультиметодов.
 * Мультиметод — это обобщение понятия виртуального метода.
 * При вызове виртуального метода выбор конкретной реализации зависит от типа одного объекта
 * (от типа того объекта, у которого этот виртуальный метод вызывается).
 * При вызове мультиметода выбор реализации может зависеть от типов нескольких объектов.
 *
 * Рассмотрим следующий пример. У класса Shape (фигура) есть три наследника:
 * Rectangle (прямоугольник), Triangle (треугольник) и Circle (круг).
 * Мы хотим реализовать функцию is_intersect, которая проверяет две фигуры на пересечение.
 * Предположим, что у нас уже реализованы 6 необходимых функций,
 * которые умеют пересекать все комбинации фигур (круг-круг, круг-прямоугольник,...).
 *
 * Как реализовать функцию is_intersect, которая принимает фигуры по указателю на базовый класс?
 * Можно было бы написать что-то подобное.
 */
// first variant of this function:
//bool is_intersect(Shape *a, Shape *b) {
//    if (Rectangle * ra = dynamic_cast<Rectangle *>(a)) {
//        if (Rectangle * rb = dynamic_cast<Rectangle *>(b)) {
//             вызываем реализацию для двух прямоугольников
//        } else if (Triangle * tb = dynamic_cast<Triangle *>(b)) {
//             вызываем реализацию для прямоугольника и треугольника
//        }
//         ....
//    } else if (Triangle * ta = dynamic_cast<Triangle *>(a))
//    ....
//}
/*
 * Однако такой код нельзя назвать хорошим:
 * реализация этой функции будет состоять из 9 веток if-else,
 * кроме того нам потребуется сделать множество dynamic_cast.
 *
 * В следующем решении этой задачи используется так называемая "двойная диспетчеризация",
 * которая позволяет избежать использования dynamic_cast.
 */
// объявляем наследников Shape
struct Rectangle;
struct Triangle;
struct Circle;

// все 6 вариантов функций пересечения
bool is_intersect(Rectangle *a, Rectangle *b) {
    std::cout << "R x R\n";
    return true;
}
bool is_intersect(Rectangle *a, Triangle *b) {
    std::cout << "R x T\n";
    return true;
}
bool is_intersect(Rectangle *a, Circle *b) {
    std::cout << "R x C\n";
    return true;
}
bool is_intersect(Triangle *a, Triangle *b) {
    std::cout << "T x T\n";
    return true;
}
bool is_intersect(Triangle *a, Circle *b) {
    std::cout << "T x C\n";
    return true;
}
bool is_intersect(Circle *a, Circle *b) {
    std::cout << "C x C\n";
    return true;
}

// базовый класс фигуры
struct Shape {
    virtual ~Shape() {}
    virtual bool intersect(Rectangle *r) = 0;
    virtual bool intersect(Triangle *t) = 0;
    virtual bool intersect(Circle *c) = 0;
    virtual bool intersect(Shape *s) = 0;
};

// прямоугольник
struct Rectangle : Shape {
    bool intersect(Rectangle *r) { return is_intersect(this, r); }
    bool intersect(Triangle *t) { return is_intersect(this, t); }
    bool intersect(Circle *c) { return is_intersect(this, c); }
    bool intersect(Shape *s) { return s->intersect(this); }
};

// треугольник
struct Triangle : Shape {
    bool intersect(Rectangle *r) { return is_intersect(r, this); }
    bool intersect(Triangle *t) { return is_intersect(t, this); }
    bool intersect(Circle *c) { return is_intersect(this, c); }
    bool intersect(Shape *s) { return s->intersect(this); }
};

// круг
struct Circle : Shape {
    bool intersect(Rectangle *r) { return is_intersect(r, this); }
    bool intersect(Triangle *t) { return is_intersect(t, this); }
    bool intersect(Circle *c) { return is_intersect(c, this); }
    bool intersect(Shape *s) { return s->intersect(this); }
};

// реализация самой функции
bool is_intersect(Shape *a, Shape *b) { return a->intersect(b); }