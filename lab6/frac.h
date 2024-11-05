#pragma once
#include <iostream>
#include <cstdint>
#include "algos.h"

class frac
{
private:
    bool nan;
    int64_t numerator;
    int64_t denominator;
    signed char sign;
public:
    void make_correct();
    bool isNan() const;
    int64_t getNumerator();
    int64_t getDenominator();
    frac getImproperForm();
    signed char getSign();
    void fractionalise();
    frac() = delete;
    frac(int _numerator, int _denominator);
    frac(const frac& other);
    frac operator+ (frac& other);
    frac operator* (frac& other);
    frac operator/ (frac& other);
    frac operator- (frac& other);
    void show();
};

