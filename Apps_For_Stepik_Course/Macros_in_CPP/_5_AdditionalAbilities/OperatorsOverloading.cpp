#include <iostream>
using namespace std;

struct Vector
{
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}
    void print()
    {
        cout << "x=" << x << ",y=" << y << endl;
    }

    // samples of overloading operators in methods - having implicit link to 'this' object //
    Vector operator-() const { return Vector(-x, -y); }
    Vector operator-(Vector const &p) const { return Vector(x - p.x, y - p.y); }
    Vector &operator*=(int n) // overloading operator *=
    {
        x *= n;
        y *= n;
        return *this;
    }
    int operator[](size_t i) const { return (i == 0) ? x : y; } // overloading operator []
    bool operator()(int i) const {}                             // now this operator will behave like a function
    bool operator()(int i1, int i2) {}                          // wil act like another function with 2 parameters
};

struct Num
{
    int n;
    Num(int n) : n(n) {}
    // overloading PREFIX form of operator:
    Num &operator++() // prefix form always has no parameters in overloading method //
    {
        n += 1;
        return *this;
    }
    // overloading POSTFIX form of operator:
    Num operator++(int) // this nameless int is a dummy parameter - just for having another method signature
    {
        Num tmp(*this); // creating a copy of instance with current state - we'll have to return it
        ++(*this);      // changing original instance
        return tmp;     // returning previously saved state of original instance - but in fact this is its copy
    }
    // that's why prefix form of increment/decrement is considered FASTER and is more likey to be used
};

// overloading of >> and << operators has to be done outside structures as we don't have access to their classes
std::istream &operator>>(std::istream &is, Vector &v) // input stream
{
    is >> v.x >> v.y; // here we have 2 invocations of reading values from keyboard
    return is;
}
std::ostream &operator<(std::ostream &os, Vector const &v)
{
    os << "overloaded <<: x=" << v.x << ",y=" << v.y;
    return os;
}
// cin & cout are in fact objects of istream & ostream that have overloaded operators of bit shifting //
// istream & ostream are base classes for all streams of input-output //

struct String
{
    String(char *data) : data_(data) {}
    // type casting operator MUST be overloaded only as a method - and it must have NO type of returned value //
    operator bool() const { return size_ != 0; } // casting (String) to (bool)
    operator char const *() const                // castin (String) to (char const *)
    // in C++2003 standart there is no way of using 'explicit' before overloading type-casting operator //
    {
        if (*this) // WARNING: there is implicit cast from String to bool here //
            return data_;
        return ""; // this empty string will not be deleted on } as it lives in constant pool region of memory
    }
    size_t size() const { return size_; }
    char *data() const { return data_; }
    String(size_t size)
    {
        size_ = size;
        delete[] data_;
        data_ = new char[size_];
    }

    // overloading of arithmetic & bit operators:
    String(char const *cstr) // as a constant link is given here - we cannot simply reassign inner data_ to it //
    {
        size_t i = 0;
        for (; cstr[i] != '\0'; ++i)
            ;
        size_ = i;
        data_ = new char[size_];
        for (size_t j = 0; j != size_; ++j)
            data_[j] = cstr[j];
    }
    String &operator+=(String const &s) // having this operator here is nice because it changes left object 'this' //
    {
        *this = *this && s;
        return *this;
    }
    // String operator+(String const & s) const {...} - if we did that - implicit cast for first element would not work
    // for that reason it's much better to have overloading of '+' operator outside String structure,
    // because at first any char array will be implicitly converteed to String using constructor from above,
    // and only then operator will process two instances of String class //

private:
    char *data_;
    size_t size_;
};

String operator+(String s1, String const &s2) { return s1 += s2; }
// using const for s2 allows to save memory on copying s2 object by passing only the link to it //

// this is NOT finished
String operator&&(String const &s1, String const &s2)
{
    size_t size_new = s1.size() + s2.size();
    String *s = new String(size_new);
    // copy all values from s1 to s, than copy all values from s2 to s
    for (size_t i1 = 0; i1 != s1.size(); ++i1)
        s[i1] = s1[i1];
    for (size_t i2 = 0; i2 != s2.size(); ++i2)
        s[s1.size() + i2] = s1[i2];
    return *s;
}

void useAllOverloadedOperators()
{
    Vector v(1, 2);
    cout << "initial v: ";
    v.print();
    Vector v1 = -v;
    cout << "v1 = -v: ";
    v1.print();
    Vector v2(3, 4);
    cout << "v2 initial: ";
    v2.print();
    cout << "v2 = v1 - v: ";
    v2 = v1 - v;
    v2.print();
    cout << "v2 *= 2: ";
    v2 *= 2;
    v2.print();
    cout << "v2[0]: " << v2[0] << endl;
    cout << "v2(2):" << v2(2) << endl;
    cout << "v2(3, 4):" << v2(3, 4) << endl;

    Num n1(5);
    cout << "n1 = " << n1.n << endl;
    Num n2 = ++n1;
    cout << "n2 = ++n1: " << n2.n << endl;
    cout << "new n1: " << n1.n << endl;
    Num n3 = n1++;
    cout << "n3 = n1++: " << n3.n << endl;
    cout << "new n1: " << n1.n << endl;

    cout << &v1 << endl;
    Vector v4(4, 5);
    cout << "initial value for v4: " << &v4 << endl;
    cout << "now set new values for x & y in v4: ";
    cin >> v4;
    cout << "changed value for v4: " << &v4 << endl;
    // for now there are some problems with output - 0xSOMETHING is printed instead of what we'd set before
    v4.print(); // but overloaded operator >> for cin works well //

    char c[] = {'O', 'K'};
    String s(c);
    cout << "casting String to bool: " << (bool)s << endl;
    cout << "casting String to char const *: " << (char const *)s << endl;

    String ss(s && s);
    cout << "custom && result: " << &ss << endl;
    delete ss;
}

// note that operators (type) [] () -> ->* = can be overloaded ONLY INSIDE CLASSES //

main()
{
    useAllOverloadedOperators();
    return 0;
}