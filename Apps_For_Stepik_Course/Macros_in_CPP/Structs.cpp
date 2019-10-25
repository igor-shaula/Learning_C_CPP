#include <cmath>
#include <iostream>
using namespace std;

struct Point
{
    double x, y;
    void shift(double x, double y)
    {
        this->x += x;
        this->y += y;
    }
};

struct Segment
{
    Point p1, p2;
    double length() // this method has implicit access to all data of this structure
    {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }
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
    Segment sm = {{0.5, 1.5}, {1.0, 6.5}};
    cout << sm.length() << endl;

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

    // ABSTRACTION - using 1d array as 2d from outside:
    struct IntArray2d
    {
        size_t a, b;
        int *data;
        int &get(size_t i, size_t j) // link to an element of the array
        {
            return data[i * b + j];
        };
    };
    int *array = new int[5];
    IntArray2d m = {3, 5, array};
    for (size_t i = 0; i < m.a; i++)
        for (size_t j = 0; j < m.b; j++)
            if (m.get(i, j) < 0)
                m.get(i, j) = 0; // we can write because link is an L-value type
}

int main()
{
    useAllStructs();
    return 0;
}