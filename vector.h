#ifndef VECTOR
#define VECTOR
#include <iostream>

/*
 * Copyright (c) 2022 Rutgers University
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Demetrios Lambropoulos <demetrios.lambropoulos@rutgers.edu>
 * Wireless Information Network Laboratory (WINLAB), Rutgers University
 *
 */

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

        // Maximum number of items the vector can currently hold
        int capacity () {
            return maxCapacity;
        }

        // Returns a boolean value stating whether there is currently any items in the vector
        bool isEmpty () {
            return numItems == 0;
        }

        // Returns items at the given index, -1 if out of bounds
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

        // Inserts items after last item in vector
        void push (T item) { 
            if (numItems == maxCapacity) {
                resize(maxCapacity*2);
            }
            arr[numItems++] = item;
        }

        // Inserts item at specified index, shifts that index's value and trailing
        // elements to the right. Return -1 if out of bounds
        void insert (int index, T item) {
            if (numItems == maxCapacity) {
                resize(maxCapacity*2);
            }

            for (int i = numItems++; i > index; i--) {
                arr[i] = arr[i-1];
            }

            arr[index] = item;
        }

        // Insert item at index 0.
        void prepend (T item) {
            insert(0, item);
        }

        // Remove item from the end of the vector and return the value
        T pop () {
            if (isEmpty()) {
                std::cout << "Vector is empty. Index out of range." << std::endl;
                return -1; 
            }
            else {
                return arr[--numItems];
            }
        }

        // Display the items currently stored in the vector
        void viewItems () {
            std:: cout << "Vector contents:";

            for (int i = 0; i < numItems; i++) {
                std::cout << " " << arr[i];
            }

            std::cout << std::endl;
        }

        // Delete item at index, shifting all trailing elements left
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

        // Looks for value and removes index holding it (even if in multiple places)
        void remove (T item) {
            int i = find(item);

            while (i != -1) {
                deleteIndex(i);

                i = find(item);
            }
        }

        // Looks for value and returns first index with that value, -1 if not found
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
