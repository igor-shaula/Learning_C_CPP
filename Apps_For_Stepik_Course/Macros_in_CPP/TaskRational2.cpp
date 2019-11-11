#include <iostream>
using namespace std;

struct Rational
{
private:
    int numerator_;
    int denominator_;

public:
    // GIVEN FROM TASK - but with bodies done by me = = =

    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}

    // methods (add, sub, mul, div, neg, inv) have to be non-const as they are declared so in the task //
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
    void inv() // inversion of our Rational
    {
        int tmp = numerator_;
        numerator_ = denominator_;
        denominator_ = tmp;
    }
    double to_double() const; // only this method was declared const in the task initially //

    // Rational operator+() const { return *this; } // this also can be compiled //
    Rational operator+() const { return Rational(numerator_, denominator_); }
    Rational operator-() const { return Rational(-1 * numerator_, denominator_); }

    // these four operators were given in task - so i have to leave them as they were //
    Rational &operator+=(Rational r)
    {
        numerator_ = numerator_ * r.denominator_ + r.numerator_ * denominator_;
        denominator_ = denominator_ * r.denominator_;
        return *this;
    }
    Rational &operator-=(Rational r)
    {
        numerator_ = numerator_ * r.denominator_ - r.numerator_ * denominator_;
        denominator_ = denominator_ * r.denominator_;
        return *this;
    }
    Rational &operator*=(Rational r)
    {
        numerator_ *= r.numerator_;
        denominator_ *= r.denominator_;
        return *this;
    }
    Rational &operator/=(Rational r)
    {
        numerator_ *= r.denominator_;
        denominator_ *= r.numerator_;
        return *this;
    }

    // COMPLETELY MY ADDITIONS = = =

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

    // all variants of overloading operators as methods = = =

    // Rational operator+(Rational const r); // replaced with outer operator +(Rational, Rational)
    Rational operator+(int i)
    {
        numerator_ += i * denominator_;
        return *this;
    }
    Rational operator+=(int n) { return *this + n; }
    // Rational operator-(Rational const r); // replaced with outer operator -(Rational, Rational)
    Rational operator-(int n) { return *this + (-n); }
    Rational operator-=(int n) { return *this - n; }
    // Rational operator*(Rational const r); // replaced with outer operator *(Rational, Rational)
    Rational operator*(int n)
    {
        numerator_ *= n;
        return *this;
    }
    Rational operator*=(int n) { return *this * n; }
    // Rational operator/(Rational const r); // replaced with outer operator /(Rational, Rational)
    Rational operator/(int n)
    {
        denominator_ *= n;
        return *this;
    }
    Rational operator/=(int n) { return *this / n; }
};

Rational operator+(Rational const &l, Rational const &r)
{
    int num = l.numerator() * r.denominator() + r.numerator() * l.denominator();
    int denom = l.denominator() * r.denominator();
    return Rational(num, denom);
}
Rational operator-(Rational const &l, Rational const &r)
{
    int num = l.numerator() * r.denominator() - r.numerator() * l.denominator();
    int denom = l.denominator() * r.denominator();
    return Rational(num, denom);
}
Rational operator*(Rational const &l, Rational const &r)
{
    int num = l.numerator() * r.numerator();
    int denom = l.denominator() * r.denominator();
    return Rational(num, denom);
}
Rational operator/(Rational const &l, Rational const &r)
{
    int num = l.numerator() * r.denominator();
    int denom = l.denominator() * r.numerator();
    return Rational(num, denom);
}

Rational operator+(int i, Rational const &r) { return Rational(r.numerator(), r.denominator()) + i; }
Rational operator-(int i, Rational const &r) { return -Rational(r.numerator(), r.denominator()) + i; }
Rational operator*(int i, Rational const &r) { return Rational(r.numerator(), r.denominator()) * i; }
Rational operator/(int i, Rational const &r)
{
    Rational nr(r.numerator(), r.denominator());
    nr.inv();
    return nr * i;
}
// there is no way of overloading all these operators with only one primitive argument //
// also there is no sense in keeping operator(Rational, int) here - outside the struct //

Rational r;

void prepareValueR()
{
    // r.println("before R");
    // cout << &r << endl;
    r = {1, 2}; // compelled action to restore initial value of this object //
    // r = Rational(1, 2); // compelled action to restore initial value of this object //
    // cout << &r << endl;
    // r.println("after R");
}

bool verify(const Rational &r, int num, int denom, string comment = "") // last parameter here has default value //
{
    r.print();
    bool result = r.numerator() == num && r.denominator() == denom;
    cout << ':' << (result ? "_OK" : "_FAILED") << '_' << comment << endl;
    prepareValueR();
}

void testOverloadedOperators()
{
    prepareValueR();
    verify(r, 1, 2, "r");

    Rational r1 = +r;
    verify(r1, 1, 2, "r1");

    Rational r2 = -r;
    verify(r2, -1, 2, "r2");

    Rational r3 = r + r;
    verify(r3, 4, 4, "r3");

    Rational r4 = r + 1;
    verify(r4, 3, 2, "r4");

    Rational r5 = 1 + r;
    verify(r5, 3, 2, "r5");

    Rational r6 = r * 2;
    verify(r6, 2, 2, "r6");

    Rational r7 = 2 * r;
    verify(r7, 2, 2, "r7");

    Rational r8 = 1 / r;
    verify(r8, 2, 1, "r8");

    Rational r9 = r / 2;
    verify(r9, 1, 4, "r9");

    Rational r10 = r;
    r10 += r;
    verify(r10, 4, 4, "r10");
    Rational r11 = r;
    r11 += 1;
    verify(r11, 3, 2, "r11");
    Rational r12 = r;
    r12 -= (2 * r);
    verify(r12, -2, 4, "r12");
    Rational r13 = r;
    r13 -= 1;
    verify(r13, -1, 2, "r13");
    Rational r14 = r;
    r14 *= r;
    verify(r14, 1, 4, "r14");
    Rational r15 = r;
    r15 *= 2;
    verify(r15, 2, 2, "r15");
    Rational r16 = r;
    r16 /= (r / 2);
    verify(r16, 4, 2, "r16");
    Rational r17 = r;
    r17 /= 2;
    verify(r17, 1, 4, "r17");
}

int main()
{
    testOverloadedOperators();
    return 0;
}