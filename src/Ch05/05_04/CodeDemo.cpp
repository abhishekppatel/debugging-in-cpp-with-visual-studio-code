// Debugging in C++ with Visual Studio Code
// Challenge 05_04
// Don't Let it Crash and Burn, by Eduardo Corpeño

#include <iostream>

double power(double base, int exponent){
    double result;
    if(exponent == 0) 
        result = 1;
    else
        result = base * power(base, exponent - 1);
    return result;
}

int main(){
    double base = 2;
    int exponent = 8;
    
    double learnerResult = power(base, exponent);
    
    std::cout << "Your code returned: " << learnerResult << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
