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
properFrac properFrac::getImproperForm()
{
    return *this;
}
void properFrac::makeProper() // it cuts frac if it bigger or equal to 1, something like when you write to big number in int
{
    fractionalise();
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
    makeProper();
}
properFrac::properFrac(const properFrac& other)
{
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->sign = other.sign;
    this->nan = other.nan;
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
    res.numerator = getSign()* getNumerator() * denLcm / getDenominator();
    res.numerator += other.getSign() * other.getNumerator() * denLcm / other.getDenominator();

    res.fractionalise();
    res.makeProper();
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
    res.sign *= other.getSign();
    res.denominator *= other.getImproperForm().getDenominator();
    res.numerator *= other.getImproperForm().getNumerator();
    res.fractionalise();
    res.makeProper();
    return res;

}
properFrac properFrac::operator/ (properFrac& other)
{
    if (other.isNan())
    {
        return other;
    }
    if (this->isNan())
    {
        return *this;
    }
    if (other.numerator == 0)
    {
        properFrac res(0, 0);
        return res;
    }
    properFrac res(*this);
    res.sign *= other.getSign();
    res.denominator *= other.getImproperForm().getNumerator();
    res.numerator *= other.getImproperForm().getDenominator();
    res.fractionalise();
    res.makeProper();
    return res;
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
    makeProper();
    if (getSign() < 0)
    {
        std::cout << '-';
    }
    std::cout << getNumerator()%getDenominator() << '\\' << getDenominator();
}
