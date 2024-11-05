#pragma once
#include <iostream>
#include <cstdint>
#include "algos.h"

class properFrac
{
private:
    bool nan;
    int64_t numerator;
    int64_t denominator;
    signed char sign;
public:
    void makeProper();
    bool isNan() const;
    int64_t getNumerator();
    int64_t getDenominator();
    properFrac getImproperForm();
    signed char getSign();
    void fractionalise();
    properFrac() = delete;
    properFrac(int _numerator, int _denominator);
    properFrac(const properFrac& other);
    properFrac operator+ (properFrac& other);
    properFrac operator* (properFrac& other);
    properFrac operator/ (properFrac& other);
    properFrac operator- (properFrac& other);
    void show();
};

