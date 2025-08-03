// Debugging in C++ with Visual Studio Code
// Exercise 07_02
// Erroring-Out, by Eduardo Corpeño

#include <iostream>
#include <sstream>

#define SUCCESS 0
#define FAILURE 1

int main(){
    char op;
    int num1, num2;

    while(true){
        std::cout << "Enter an expression (like 5 + 3) or 'q' to quit: " << std::flush;
        std::string input;
        std::getline(std::cin, input);

        if(input == "q") 
            exit(SUCCESS);

        std::istringstream iss(input);
        if(!(iss >> num1 >> op >> num2))
        {
            std::cerr<<"Error invalid input format!"<<std::endl<<std::endl;
            exit(FAILURE);
        }; 

        if(op == '/' && num2 == 0)
        {
            std::cerr<<"Divison by zero."<<std::endl<<std::endl;
            exit(FAILURE);
        }

        switch(op){
            case '+': std::cout << "Result: " << num1 + num2 << std::endl; break;
            case '-': std::cout << "Result: " << num1 - num2 << std::endl; break;
            case '*': std::cout << "Result: " << num1 * num2 << std::endl; break;
            case '/': std::cout << "Result: " << num1 / num2 << std::endl; break;
        }
    }
    std::cout << std::endl << std::endl;
    return 0;
}
