// Debugging in C++ with Visual Studio Code
// Challenge 04_05
// Get it to Compile, by Eduardo Corpeño

#include <iostream>
#include <vector>

using std::vector;

bool isPrime(int num){
    if (num < 2) 
        return false;

    if(num == 2)
        return true;  // 2 is prime

    if((num % 2) == 0) 
        return false;  // Even numbers > 2 are NOT prime

    for(int i = 3; i * i <= num; i += 2)
        if((num % i) == 0) return false;

    return true;
}

int sumOfPrimes(const vector<int>& numbers){
    auto sum {0};
    for(auto num:numbers)
        if(isPrime(num))
            sum += num;
    return sum;
}

int main(){
    vector<int> numbers = {70, 17, 12, 81, 5};
    int learnerResult = sumOfPrimes(numbers);
    
    std::cout << "Your code returned: " << learnerResult << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
