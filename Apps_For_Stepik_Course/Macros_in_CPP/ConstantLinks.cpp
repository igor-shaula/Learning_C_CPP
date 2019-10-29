int a = 10;

// a link itself is immutable - it's related only to one variable during all time of link's existence

// will give error because a link actually is constant - we can't change its variable once it's set
int &const b = a;

// this will work as we just declare a link to a constant:
int const &c = a;

// using constant links allows us to avoid copying objects during functions invocation
struct Point
{
    Point(int x, int y);
};
struct Segment
{
    Segment(Point p1, Point p2);
    Point midpoint(Segment const &s); // when this method is invoked - Segment is passed by a link - not value
};

// another benefit of constant link - we can use RValue there:
Segment s;
Point p = s.midpoint(Segment(Point(0, 0), Point(1, 1))); // inner Segment object is temporary instance

// if midpoint(Segment & s) without const - line above would not compile