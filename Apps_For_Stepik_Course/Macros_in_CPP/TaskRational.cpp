struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational operator-() { return -; }
    Rational operator+(Rational const &r) {}
    Rational operator+(int i) {}

private:
    int numerator_;
    int denominator_;
};

Rational operator+=(int i, Rational r) { return r + i; }
Rational operator-=(int i, Rational r) { return -r + i; }
Rational operator*=(int i, Rational r) { return r * i; }
Rational operator/=(int i, Rational r) {}

void testOverloadedOperators()
{
}

int main()
{
    testOverloadedOperators();
    return 0;
}