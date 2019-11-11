#include <iostream>
using namespace std;

struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational &operator+=(Rational rational);
    Rational &operator-=(Rational rational);
    Rational &operator*=(Rational rational);
    Rational &operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

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

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

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