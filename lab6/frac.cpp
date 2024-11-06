#include "frac.h"
int64_t properFrac::getNumerator()
{
    fractionalise();
    return numerator;
}
int64_t properFrac::getDenominator()
{
    fractionalise();
    return denominator;
}
signed char properFrac::getSign()
{
    fractionalise();
    return sign;
}
int64_t properFrac::getIntPart()
{
    return intPart;
}
void properFrac::separateIntPart()
{
    fractionalise();
    intPart += numerator / denominator;
    numerator %= denominator;
}
void properFrac::fractionalise()
{
    if (numerator + denominator < abs(numerator) + abs(denominator))
    {
        sign *= -1;
    }
    else
    {
        sign *= 1;
    }

    if (numerator == 0)
    {
        sign = 1;
    }

    numerator = abs(numerator);
    denominator = abs(denominator);

    int64_t cur_gcd = gcd(numerator, denominator);

    numerator /= cur_gcd;
    denominator /= cur_gcd;

   

}

properFrac::properFrac(int _numerator, int _denominator)
{
    intPart = 0;
    if (_denominator == 0)
    {
        nan = 1;
        return;
    }
    sign = 1;
    nan = 0;
    numerator = _numerator;
    denominator = _denominator;
    fractionalise();
    separateIntPart();
}
properFrac::properFrac(const properFrac& other)
{
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->sign = other.sign;
    this->nan = other.nan;
    this->intPart = other.intPart;
}
properFrac properFrac::operator+ (properFrac& other)
{
    if (other.isNan())
    {
        return other;
    }
    if (this->isNan())
    {
        return *this;
    }

    other.fractionalise();
    fractionalise();

    

    properFrac res(0, 1);
    

    int64_t denLcm = getDenominator() / gcd(getDenominator(), other.getDenominator()) * other.getDenominator();
    res.denominator = denLcm;
    res.numerator = getSign()* (getNumerator() + getDenominator()*getIntPart())* denLcm / getDenominator();
    res.numerator += other.getSign() * (other.getNumerator() + other.getDenominator() * other.getIntPart())* denLcm / other.getDenominator();

    res.fractionalise();
    res.separateIntPart();
    return res;
}
properFrac properFrac::operator- (properFrac& other)
{
    if (other.isNan())
    {
        return other;
    }
    if (this->isNan())
    {
        return *this;
    }

    other.fractionalise();
    properFrac newOther(other);
    newOther.sign *= -1;
    return operator+(newOther);
}
properFrac properFrac::operator* (properFrac& other)
{
    if (other.isNan())
    {
        return other;
    }
    if (this->isNan())
    {
        return *this;
    }

    properFrac res(*this);
    res.numerator = res.getIntPart() * res.getDenominator() + res.getNumerator();
    res.intPart = 0;
    res.sign *= other.getSign();
    res.denominator *= other.getDenominator();
    res.numerator *= (other.getNumerator() + other.getDenominator() * other.getIntPart());
    res.fractionalise();
    res.separateIntPart();
    return res;

}
properFrac properFrac::operator/ (properFrac& other)
{
    properFrac res(other);
    res.numerator = res.getIntPart() * res.getDenominator() + res.getNumerator();
    res.intPart = 0;
    int64_t temp = res.numerator;
    res.numerator = res.denominator;
    res.denominator = temp;
    res.separateIntPart();
    return (*this)*res;
}
bool properFrac::isNan() const
{
    return nan;
}

void properFrac::show()
{
    if (isNan())
    {
        std::cout << "nan";
        return;
    }
    fractionalise();
    separateIntPart();
    if (getSign() < 0)
    {
        std::cout << '-';
    }
    if (intPart > 0)
    {
        std::cout << intPart << '_';
    }
    std::cout << getNumerator()%getDenominator() << '\\' << getDenominator();
}