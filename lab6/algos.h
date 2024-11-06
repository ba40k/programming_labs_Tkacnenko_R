#pragma once

template<typename intType>
intType max(intType a, intType b)
{
    return a < b ? b : a;
}


template<typename intType>
void swap(intType& a, intType& b)
{
    intType temp = a;
    a = b;
    b = temp;
}

template<typename intType>
intType abs(intType a)
{
    return max(a, a - 2 * a);
}

template<typename intType>
intType gcd(intType a, intType b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

