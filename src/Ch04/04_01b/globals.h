#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>

// Global discount amount defined here (will later be redefined in main.cpp)
double globalDiscount = 10.0;

void externalPromotion()
{
    std::cout<<"Join our Reward Program for further discounts!"<<std::endl;
};

#endif // GLOBALS_H
