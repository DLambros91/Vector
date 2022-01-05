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
        
    private:
        int numItems = 0;
        int maxCapacity = 16;
        void resize (int newSize) { }
};