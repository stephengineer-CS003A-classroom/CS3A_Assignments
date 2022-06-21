# Pointer Array Functions

- Accept [09_01_pointer_array_functions](https://classroom.github.com/a/45WayU5_)
- Get [basic_test.cpp](basic_test.cpp)

---

- The following functions will be used in several projects in this term.
- Write these functions and test them well.
- Please read the [Guidelines for pointers](https://docs.google.com/document/d/1WDgzNbWrGjDA7739GjZ8Xna_RrUX95w6XqKL4mOmDpc/edit?usp=sharing) before you begin. 
- Do not use array notation. You will only use brackets when you declare an array
 
```c++
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;

const int MINIMUM_CAPACITY = 3;

// Declaration

// allocate 'capacity' elements return array
template<typename T>
T* allocate(int capacity=MINIMUM_CAPACITY);

// take array, resize it return new array delete old array
template<typename T>
T* reallocate(T* a, int size, int capacity);

// init array with value
template<typename T>
void init_array(T* a, int size, T init_item=T());

// print (size/capacity) for debugging
template<typename T>
void print_array(T* a, int size, int capacity=0, ostream& outs=cout);

// print array
template <typename T>
void print(T* a, int how_many, ostream& outs=cout);

// search for the first 'find_me' and return pointer of it
template<typename T>
T* search_entry(T* a, int size, const T& find_me);

// search for the first 'find_me' and return index of it
template <typename T>
int search(T* a, int size, const T& find_me);

//shift left @ pos: erases @ pos
template <typename T>
void shift_left(T* a, int& size, T* shift_here);

//shift left @ pos: erases @ pos
template <typename T>
void shift_left(T* a, int& size, int shift_here);

// shift right: make a hole
template <typename T>
void shift_right(T* a, int& size, T* shift_here);

// shift right: make a hole
template<typename T>
void shift_right(T* a, int& size, int shift_here);

// copy from src to dest
template<typename T>
void copy_array(T* dest, const T* src, int many_to_copy);

// return a copy of src
template <typename T>
T* copy_array(const T* src, int size);

// return array as a string
template <typename T>
string array_string(const T* a, int size);

// Definition

// TODO

#endif // ARRAY_FUNCTIONS_H
```