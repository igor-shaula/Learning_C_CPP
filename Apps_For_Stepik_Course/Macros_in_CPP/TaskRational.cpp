#include <iostream>
using namespace std;

struct Rational
{
private:
    int numerator_;
    int denominator_;

public:
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}

    void add(Rational rational)
    {
        numerator_ += rational.numerator_;
        denominator_ += rational.denominator_;
    }
    void sub(Rational rational)
    {
        numerator_ -= rational.numerator_;
        denominator_ -= rational.denominator_;
    }
    void mul(Rational rational)
    {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }
    void div(Rational rational)
    {
        numerator_ /= rational.numerator_;
        denominator_ /= rational.denominator_;
    }

    void neg()
    {
        numerator_ = -numerator_; // denominator remains the same because '-' affects numerator at first
    }
    // following two methods are not mentioned in task's description but were present in given presample of code //
    void inv();
    double to_double() const;

    // UTILS = = =

    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }
    void print() const
    {
        cout << numerator_ << '/' << denominator_;
    }
    void println() const
    {
        print();
        cout << endl;
    }
    void println(char const *c) const
    {
        cout << c << ':';
        println();
    }
    Rational inverted()
    {
        return Rational(denominator_, numerator_);
    }

    // all variants of overloading operators as methods = = =

    Rational operator+() { return *this; } // PREFIX form - it has to leave all values as they are - so obviously do nothing here //
    Rational operator+(Rational const &r)
    {
        numerator_ = numerator_ * r.denominator_ + r.numerator_ * denominator_;
        denominator_ = denominator_ * r.denominator_;
        return Rational(numerator_, denominator_);
    }
    Rational operator+=(Rational const &r) { return *this + r; }
    Rational operator+(int i)
    {
        numerator_ += i * denominator_;
        return Rational(numerator_, denominator_);
    }
    Rational operator+=(int n) { return *this + n; }

    Rational operator-() // cannot be const method as we use non-const neg() inside - and it changes numerator //
    {
        neg();
        return *this;
    }
    Rational operator*(int n)
    {
        return Rational(numerator_ * n, denominator_);
    }
};

bool verify(const Rational &r, int num, int denom, string comment = "") // last parameter here has default value //
{
    r.print();
    bool result = r.numerator() == num && r.denominator() == denom;
    cout << ':' << (result ? "_OK" : "_FAILED") << '_' << comment << endl;
}

Rational r;
// void prepareValueR()
// {
//     r = {1, 2}; // compelled action to restore initial value of this object //
// }

void prepareValueR()
{
    // r.println("before R");
    // cout << &r << endl;
    r = {1, 2}; // compelled action to restore initial value of this object //
    // r = Rational(1, 2); // compelled action to restore initial value of this object //
    // cout << &r << endl;
    // r.println("after R");
}

Rational operator+(int i, Rational r) { return r + i; }
Rational operator-(int i, Rational r) { return -r + i; }
Rational operator*(int i, Rational r) { return r * i; }
Rational operator/(int i, Rational r) { return r.inverted() * i; }

void testOverloadedOperators()
{
    prepareValueR();
    verify(r, 1, 2, "r");

    Rational r1 = +r;
    verify(r1, 1, 2, "r1");

    Rational r2 = -r;
    verify(r2, -1, 2, "r2");

    prepareValueR();
    Rational r3 = r + r;
    verify(r3, 4, 4, "r3");

    Rational r4 = r + 1;
    verify(r4, 8, 4, "r4");

    prepareValueR();
    Rational r5 = 1 + r;
    verify(r5, 3, 2, "r5");

    Rational r6 = r * 2;
    verify(r6, 2, 2, "r6");

    prepareValueR();
    Rational r7 = 2 * r;
    verify(r7, 2, 2, "r7");
}

int main()
{
    testOverloadedOperators();
    return 0;
}