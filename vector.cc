#include <iostream>

template <typename T>

class vector {
    public: 
        vector () {
            numItems = 0;
            maxCapacity = 16;
            arr = new T[maxCapacity];
        }

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
            return arr[--numItems];
        } 

        void viewItems () {
            std:: cout << "Vector contents:";

            for (int i = 0; i < numItems; i++) {
                std::cout << " " << arr[i];
            }

            std::cout << std::endl;
        }

        void deleteIndex (int index) {
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

    private:
        int numItems;
        int maxCapacity;
        T * arr;
        void resize (int newSize) { 
            T * tmp = arr;
            arr = new int[newSize];
            for (int i = 0; i < maxCapacity; i++) {
                arr[i] = tmp[i];
            }
            delete tmp;
            maxCapacity = newSize;
        }
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
    
    return 0;
}