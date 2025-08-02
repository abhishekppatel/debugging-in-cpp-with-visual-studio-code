// Debugging in C++ with Visual Studio Code
// Exercise 05_01
// Segmentation Faults, by Eduardo Corpeño

#include <iostream>
#include <sstream>
#include <string>

#define MAX_ENTRIES 1000

struct Node{
    std::string name;
    int age;
    char gender;
    float weight;
    Node * next;
};

void appendNode(Node ** head, Node ** tail, const std::string & newName){
    Node * newNode = new Node;
    newNode->name = newName;
    newNode->next = nullptr;

    if(*head == nullptr){
        *head = newNode;
        *tail = newNode;
    }
    else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void printNames(Node * head){
    Node * current = head;
    while(current != nullptr){
        std::cout << current->name << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(Node * head){
    while(head != nullptr){
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    std::cout << "Enter names separated by spaces: ";
    std::string line;
    std::getline(std::cin, line);
    
    std::istringstream iss(line);
    std::string token;
    
    Node * head = nullptr;
    Node * tail = nullptr;
    while(iss >> token){
        appendNode(&head, &tail, token);
        // iss.seekg(0);
    }
    
    std::cout << "The names in the linked list are: ";
    printNames(head);
    
    deleteList(head);
    std::cout << std::endl << std::endl;
    return 0;
}
