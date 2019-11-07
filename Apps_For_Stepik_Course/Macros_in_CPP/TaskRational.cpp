#include <iostream>
using namespace std;

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}

    void add(Rational rational)
    {
        this->numerator_ += rational.numerator_;
        this->denominator_ += rational.denominator_;
    }
    void sub(Rational rational)
    {
        this->numerator_ -= rational.numerator_;
        this->denominator_ -= rational.denominator_;
    }
    void mul(Rational rational)
    {
        this->numerator_ *= rational.numerator_;
        this->denominator_ *= rational.denominator_;
    }
    void div(Rational rational)
    {
        this->numerator_ /= rational.numerator_;
        this->denominator_ /= rational.denominator_;
    }

    void neg()
    {
        this->numerator_ = -this->numerator_; // denominator remains the same because '-' affects numerator at first
    }
    // following two methods are not mentioned in task's description but were present in given presample of code //
    void inv();
    double to_double() const;

    void print()
    {
        cout << numerator_ << '/' << denominator_;
    }
    void println()
    {
        print();
        cout << endl;
    }
    void println(char const *c)
    {
        cout << c << ':';
        println();
    }

    // all variants of overloading addition operator //
    Rational operator+() {} // PREFIX form - it has to leave all values as they are - so obviously do nothing here //
    Rational operator+(Rational const &r)
    {
        this->numerator_ = this->numerator_ * r.denominator_ + r.numerator_ * this->denominator_;
        this->denominator_ = this->denominator_ * r.denominator_;
        return Rational(numerator_, denominator_);
    }
    Rational operator+(int i)
    {
        this->numerator_ += i * this->denominator_;
        return Rational(this->numerator_, this->denominator_);
    }
    Rational operator+=(Rational const &r) { return *this + r; }

    Rational operator-()
    {
        this->neg();
        return *this;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+=(int i, Rational r) { return r + i; }
Rational operator-=(int i, Rational r) { return -r + i; }
Rational operator*=(int i, Rational r) {}
Rational operator/=(int i, Rational r) {}

void testOverloadedOperators()
{
    Rational r1(1, 2);
    r1.println();
    Rational r2 = -r1;
    r2.println();
    Rational r3 = r1 + r1;
    r3.println("r3");
    Rational r4 = r1 + 1;
    r4.println("r4");
}

int main()
{
    testOverloadedOperators();
    return 0;
}