#include <iostream>
#include "vector.h"

int main () {
    vector<int> v;

    std::cout << "The current size of the vector is: " << v.size() << std::endl;

    std::cout << "The maximum capacity of the vector is: " << v.capacity() << std::endl;

    v.at(0);
    
    v.push(5);
    v.push(4);
    v.push(3);
    
    std::cout << "The current size of the vector is: " << v.size() << std::endl;

    std::cout << "The maximum capacity of the vector is: " << v.capacity() << std::endl;
    
    std::cout << "Item at index 1 is: " << v.at(1) << std::endl;

    std::cout << "Number 4 is at index: " << v.find(4) << std::endl;

    std::cout << "Popping item: " << v.pop() << std::endl;
    
    std::cout << "The current size of the vector is: " << v.size() << std::endl;
    
    v.push(5);
    v.push(4);
    v.push(3);

    std::cout << "Item at index 0 is: " << v.at(0) << std::endl;
    std::cout << "Item at index 1 is: " << v.at(1) << std::endl;
    std::cout << "The current size of the vector is: " << v.size() << std::endl;

    v.prepend(7);

    std::cout << "Item at index 0 is: " << v.at(0) << std::endl;
    std::cout << "Item at index 1 is: " << v.at(1) << std::endl;
    std::cout << "The current size of the vector is: " << v.size() << std::endl;
    
    v.viewItems();

    v.insert(4, 6);

    v.viewItems();

    v.deleteIndex(0);

    v.viewItems();

    v.remove(4);

    v.viewItems(); 

    v.pop();
    v.pop();
    v.pop();
    v.pop();
    v.pop();
    return 0;
}
