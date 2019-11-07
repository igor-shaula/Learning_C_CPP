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
    void inv();               // this method is not mentioned in task's description but was present in given presample of code //
    double to_double() const; // the same story occures with this methods as well //

    Rational operator-() {}
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