// Debugging in C++ with Visual Studio Code
// Challenge 03_08
// Find and Fix the Bug, by Eduardo Corpeño

#include <iostream>
#include <limits>
#include <vector>

using std::vector;

int findLargest(const vector<int>& numbers){
    int largest = std::numeric_limits<int>::min();
    for (auto it = std::begin(numbers); it < std::end(numbers); it ++){
        if (*it > largest)
            largest = *it;
    }
    return largest;
}

int main(){
    vector<int> numbers = {7, 27, 0, -19, 5, 20};
    int learnerResult = findLargest(numbers);
    
    std::cout << "Your code returned: " << learnerResult << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
