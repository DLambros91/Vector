#ifndef VECTOR
#define VECTOR
#include <iostream>
template <typename T>

class vector {
    private:
        int numItems;
        int maxCapacity;
        T * arr;
        // When you reach capacity, resize to double the size
        void resize (int newSize){
            T * tmp = arr;
            arr = new int[newSize];
    
            for (int i = 0; i < maxCapacity; i++) {
                arr[i] = tmp[i];
            }
    
            delete [] tmp;
            maxCapacity = newSize;
        }
    public:
        // Default constructor. Set with default values of size 0 and capacity 16.
        vector () {
            numItems = 0;
            maxCapacity = 16;
            arr = new T[maxCapacity];
        }

        // Get the number of items in the vector.
        int size () {
            return numItems;
        }

        int capacity () {
            return maxCapacity;
        }

        bool isEmpty () {
            return numItems == 0;
        }

        T at (int index) {
            if (isEmpty()) {
                std::cout << "Vector is empty. Index out of range." << std::endl;
                return -1;
            } else if (index >= numItems) {
                std::cout << "Index out of range." << std::endl;
                return -1;
            }

            return arr[index];
        }

        void push (T item) { 
            if (numItems == maxCapacity) {
                resize(maxCapacity*2);
            }
            arr[numItems++] = item;
        }

        void insert (int index, T item) {
            if (numItems == maxCapacity) {
                resize(maxCapacity*2);
            }

            for (int i = numItems++; i > index; i--) {
                arr[i] = arr[i-1];
            }

            arr[index] = item;
        }

        void prepend (T item) {
            insert(0, item);
        }

        T pop () {
            if (isEmpty()) {
                std::cout << "Vector is empty. Index out of range." << std::endl;
                return -1; 
            }
            else {
                return arr[--numItems];
            }
        }

        void viewItems () {
            std:: cout << "Vector contents:";

            for (int i = 0; i < numItems; i++) {
                std::cout << " " << arr[i];
            }

            std::cout << std::endl;
        }

        void deleteIndex (int index) {
            if (isEmpty()) {
                std::cout << "Vector is empty. Index out of range." << std::endl;
                return;
            } else if (index < 0 || index >= numItems) {
                std::cout << "Invalid index provided. Index out of range." << std::endl;
                return;
            }

            for (int i = index; i < numItems; i++) {
                arr[i] = arr[i+1];
            }

            numItems--;
        }

        void remove (T item) {
            int i = find(item);

            while (i != -1) {
                deleteIndex(i);

                i = find(item);
            }
        }

        int find (T item) {
            for (int i = 0; i < numItems; i++){
                if (arr[i] == item){
                    return i;
                }
            }
            return -1;
        }
};

#endif
