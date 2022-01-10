# Vector
Implementation of vector data structure from arrays

## Space 
Contiguous in memory, so proximity helps performance.

Space needed = (array capacity which is >= N) * item size resulting in which is O(N). 

## API

| Method      | Run Time        | Description|
| ----------- | --------------- | --------- |
| size ()                           | O(1) | Returns the number of items contained | 
| capacity ()                       | O(1) | Maximum number of items the vector can currently hold | 
| isEmpty ()                        | O(1) | Determines if the vector is empty |
| at (index: int)                   | O(1) | Returns item at provided index, returns error if out of bounds |
| push (item: object)               | O(1) | Push item at end of vector |
| insert (index: int, item: object) | O(N) | Inserts item at given index in vector, shifts the index's value and trailing values to the right |
| prepend (item: object)            | O(N) | Inserts item at the beginning of the list, equivalent to insert (item, 0) |
| pop ()                            | O(1) | Remove item from the end of vector and returns the item's value |
| delete (index: int)               | O(N) | Delete item at index and shift trailing elements to the left |
| remove (item: object)             | O(N) | Looks for value and removes index holding it, including all duplicates of the value |
| find (item: object)               | O(N) | Looks for value and returns first index containing the value of item, returns -1 if not found |
| resize (new_capacity: int)        | O(N) | Called when capacity is reached, resizes to double capacity | 
| viewItems ()                      | O(N) | Displays the contents of the vector | 
