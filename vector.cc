#include <iostream>

class vector {
    public: 
        int size () {
            return numItems;
        }
        

    private:
        int numItems = 0;
        int capacity = 16;
        void resize (int newSize) { }
};