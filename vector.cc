#include <iostream>

template <typename T>

class vector {
    public: 
        int size () {
            return numItems;
        }
        
        int capacity () {
            return maxCapacity;
        }

        bool isEmpty () {
            return numItems == 0;
        }

        T at (int index) 
        {
            if (numItems == 0) 
            {
                std::cout << "Vector is empty. Index out of range." << std::endl;
                return -1;
            } else if (index >= numItems)
            {
                std::cout << "Index out of range." << std::endl;
                return -1;
            }

            return arr[index];
        }

        void push (T item) 
        {
            if (numItems == maxCapacity) {
                resize(maxCapacity*2);
            }
            arr[numItems++] = item;
        }

        void insert (int index, T item) {

        }   

        void prepend (T item) {

        } 

        T pop () {
            
        } 

        void deleteIndex (int index) {

        }

        void remove (T item) {

        }

        int find (T item) {

        }
        
    private:
        int numItems = 0;
        int maxCapacity = 16;
        T arr[16];
        void resize (int newSize) { }
};

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

    return 0;
}