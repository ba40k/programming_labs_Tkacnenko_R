#include "algos.h"

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int gcd(int a, int b)
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





int max(int a, int b)
{
    return a < b ? b : a;
}

int abs(int a)
{
    return max(a, a - 2 * a);
}
