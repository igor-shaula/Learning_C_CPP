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

int main()
{
    return 0;
}