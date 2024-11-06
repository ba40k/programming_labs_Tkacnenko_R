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
    int64_t intPart;
    signed char sign;
public:
    
    bool isNan() const;
    int64_t getNumerator();
    int64_t getDenominator();
    int64_t getIntPart();
    signed char getSign();
    void separateIntPart();
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

