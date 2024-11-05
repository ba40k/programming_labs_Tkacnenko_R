#include "frac.h"
int64_t frac::getNumerator()
{
    fractionalise();
    return numerator;
}
int64_t frac::getDenominator()
{
    fractionalise();
    return denominator;
}
signed char frac::getSign()
{
    fractionalise();
    return sign;
}
frac frac::getImproperForm()
{
    return *this;
}
void frac::make_correct()
{
    fractionalise();
    numerator %= denominator;
}
void frac::fractionalise()
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

frac::frac(int _numerator, int _denominator)
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
    make_correct();
}
frac::frac(const frac& other)
{
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->sign = other.sign;
    this->nan = other.nan;
}
frac frac::operator+ (frac& other)
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


    frac res(0, 1);
    

    int64_t denLcm = getDenominator() / gcd(getDenominator(), other.getDenominator()) * other.getDenominator();
    res.denominator = denLcm;
    res.numerator = getSign()* getNumerator() * denLcm / getDenominator();
    res.numerator += other.getSign() * other.getNumerator() * denLcm / other.getDenominator();

    res.fractionalise();
    res.make_correct();
    return res;
}
frac frac::operator- (frac& other)
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
    frac newOther(other);
    newOther.sign *= -1;
    return operator+(newOther);
}
frac frac::operator* ( frac& other)
{
    if (other.isNan())
    {
        return other;
    }
    if (this->isNan())
    {
        return *this;
    }

    frac res(*this);
    res.sign *= other.getSign();
    res.denominator *= other.getImproperForm().getDenominator();
    res.numerator *= other.getImproperForm().getNumerator();
    res.fractionalise();
    res.make_correct();
    return res;

}
frac frac::operator/ (frac& other)
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
        frac res(0, 0);
        return res;
    }
    frac res(*this);
    res.sign *= other.getSign();
    res.denominator *= other.getImproperForm().getNumerator();
    res.numerator *= other.getImproperForm().getDenominator();
    res.fractionalise();
    res.make_correct();
    return res;
}
bool frac::isNan() const
{
    return nan;
}

void frac::show()
{
    if (isNan())
    {
        std::cout << "nan";
        return;
    }
    fractionalise();
    make_correct();
    int len = 0;
    if (getSign() < 0)
    {
        len++;
        std::cout << '-';
    }
    if (numerator / denominator!= 0)
    {
        std::cout << numerator / denominator << "_";
    }
    std::cout << getNumerator()%getDenominator() << '\\' << getDenominator();
}