#include <cmath>

struct Point
{
    double x, y;
};

struct Segment
{
    Point p1, p2;
};

double length(Segment s) // 4*double in fact are copied during this function invocation
{
    double dx = s.p1.x - s.p2.x;
    double dy = s.p1.y - s.p2.y;
    return sqrt(dx * dx + dy * dy);
}

double length(Segment *sptr) // we save memory here / in fact ptr-> is the same as *(ptr)
{
    if (sptr == 0)
        return -1;
    double dx = sptr->p1.x - sptr->p2.x;
    double dy = sptr->p1.y - sptr->p2.y;
    return sqrt(dx * dx + dy * dy);
}

bool intersects(Segment s1, Segment s2, Point *p)
{
}

int **create2dArray(size_t a, size_t b)
{
    int **matrix = new int *[a];
    matrix[0] = new int[a * b];
    for (size_t i = 1; i < a; i++)
        matrix[i] = matrix[i - 1] + b;
    return matrix;
}

void useAllStructs()
{
    // simplest sample ever:
    Point p1 = {0.4, 1.4};
    Point p2 = {1.2, 6.3};
    Segment s = {p1, p2};

    // shortened form of initialization:
    Segment AB = {(Point){5.2, 0.4}, (Point){3.9, 0.8}};

    // more complex one:
    struct IntMatrix
    {
        size_t a;
        size_t b;
        int **data;
    };
    IntMatrix im = {3, 5, create2dArray(3, 5)};
}

int main()
{
    useAllStructs();
    return 0;
}