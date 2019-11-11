#include <iostream>
using namespace std;

struct Rational
{
public:
    // GIVEN FROM TASK - but with bodies done by me = = =

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
    void inv() // inversion of our Rational
    {
        int tmp = numerator_;
        numerator_ = denominator_;
        denominator_ = tmp;
    }
    double to_double() const; // only this method was declared const in the task initially //

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

    Rational operator+() const { return Rational(numerator_, denominator_); }
    Rational operator-() const { return Rational(-1 * numerator_, denominator_); }

    // operator double()
    // {
    //     return (double)numerator_ / (double)denominator_;
    // }

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

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational l, Rational r) { return l += r; }
Rational operator-(Rational l, Rational r) { return l -= r; }
Rational operator*(Rational l, Rational r) { return l *= r; }
Rational operator/(Rational l, Rational r) { return l /= r; }

// SOLUTION FOR TASK 3 = = =

bool operator<(Rational const &l, Rational const &r)
{
    return l.numerator() * r.denominator() < r.numerator() * l.denominator();
}
bool operator>(Rational const &l, Rational const &r) { return r < l; }
bool operator<=(Rational const &l, Rational const &r) { return !(r < l); }
bool operator>=(Rational const &l, Rational const &r) { return !(l < r); }
bool operator==(Rational const &l, Rational const &r) { return !(l < r) && !(r < l); } // compact logical form
bool operator!=(Rational const &l, Rational const &r) { return !(l == r); }
// bool operator==(Rational const &l, Rational const &r) // faster alternative version
// {
//     return l.numerator() * r.denominator() == r.numerator() * l.denominator();
// }

// MY ADDITIONS = = =

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

bool verify(const Rational &r, const int num, const int denom, const string comment = "") // last parameter here has default value //
{
    r.print();
    bool result = r.numerator() == num && r.denominator() == denom;
    cout << ':' << (result ? "_OK" : "_FAILED") << '_' << comment << endl;
    prepareValueR();
}

void verify(const bool b, const string comment)
{
    cout << comment << ':' << (b ? "OK" : "FAILED") << endl;
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

    Rational r20 = r, r21 = {1, 2}, r22 = {2, 3};
    verify(r20 == r21, "r20 == r21");
    verify(r20 != r22, "r20 != r22");
    verify(r21 < r22, "r21 < r22");
    verify(r22 > r21, "r22 > r21");
    verify(r21 <= r22, "r21 <= r22");
    verify(r21 <= r20, "r21 <= r22");
    verify(r22 >= r21, "r22 >= r21");
    verify(r21 >= r20, "r21 >= r20");
}

int main()
{
    testOverloadedOperators();
    return 0;
}