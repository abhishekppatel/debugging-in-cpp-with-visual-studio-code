// Debugging in C++ with Visual Studio Code
// Exercise 04_01
// Syntax Errors, by Eduardo Corpeño

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "globals.h"

// Computes the total bill by adding tip and subtracting a discount.
double computeTotal(double bill, int people, double tipPercentage){
    double tipAmount = bill * (tipPercentage / 100);
    double discount = globalDiscount; // Flat discount applied to the bill.
    return std::round((bill + tipAmount - discount) * 100.0) / 100.0;
}

std::string getBonusOffer(){
    return "20% off on your next visit."; }

// Print a message when the split is not even
void printUnevenSplit(double totalBill, double perPerson, int numPeople){
    int diff = std::round(((perPerson * numPeople) - totalBill) * 100);
    if(diff > 0)
        std::cout << "FYI: We are " << diff << "¢ over." << std::endl;
    if(diff < 0)
        std::cout << "FYI: We are " << -diff << "¢ short." << std::endl;
    std::cout << std::endl;
}

int main(){
    double billAmount, tipPercentage;
    int numPeople;            
    int tip;

    std::cout << "===== Bill Split Calculator =====" << std::endl << std::endl;
    
    std::cout << "Enter bill amount: $";
    std::cin >> billAmount;
    std::cout << "Enter number of people: ";
    std::cin >> numPeople;
    std::cout << "Enter tip percentage: ";
    std::cin >> tip;
    
    if(numPeople > 2)
        std::cout << std::endl << "Group discounts may apply!" << std::endl;
    
    auto totalBill = computeTotal(billAmount, numPeople, tip);
    double perPerson = std::round((totalBill / numPeople) * 100.0) / 100.0;

    std::cout << std::endl << "Grand Total: $" << totalBill << std::endl;
    
    std::cout << "Each person should pay: $" << std::fixed 
              << std::setprecision(2) << perPerson << std::endl;
    
    printUnevenSplit(totalBill, perPerson,numPeople);
        
    auto bonus = getBonusOffer();
    std::cout << "Bonus offer: " << bonus << std::endl;
    
    externalPromotion();
    
    std::cout << std::endl << std::endl;
    
    return 0;
}
