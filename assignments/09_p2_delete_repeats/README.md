# Delete Repeats

- Accept [09_p2_delete_repeats](https://classroom.github.com/a/FtIOrYhs)
- Get [basic_test.cpp](basic_test.cpp)

Notes:

- Please read the Guidelines for pointers before you begin. 
- Use `template<typename T>` as the array type.
- Use just one for loop in `delete_repeats` function.
- Do not use the Null Character to detect the end of the array. (this, after all, could be an array of ints)
- Use a search_entry function that returns a pointer to the location of the first occurrence of a key. (or a nullptr if not found)
If you are instructed to remove the duplicates from the existing array, use a shift_left function that shifts the elements of the array left at a given position.
#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H

#include <iostream>

#include "../array_functions/array_functions.h"

using namespace std;

// Declaration

template<typename T>
void delete_repeats(T* a, int& size);

// Definition

// TODO

#endif // DELETE_REPEATS_H