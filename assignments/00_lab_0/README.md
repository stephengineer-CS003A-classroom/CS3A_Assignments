# Lab 0 git clone, status, add, commit and push 

- [ ] Accept [00_lab_0](https://classroom.github.com/a/kk1kb4Ne)
- [ ] Get [basic_test.cpp](basic_test.cpp)

Before working on assignment, [setup system environment](https://github.com/stephengineer-CS003A-classroom/CS3A_Setup).


The following code is the prototype of functions in `array_functions.h`, and you need to implement functions in `array_functions.cpp`


```c++
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

//initialize the first size elements of the array
void _array_init(int a[], int size, int x=0);
//add append_me to the end of the array and size++
void _append(int a[], int& size, int append_me);
//return index of find_me -1 if not found
int _find(const int a[], int size, int find_me);
//return item at index pos
int& _at(int a[], int size, int pos);
//print the array
void _print_array(const int a[], int size);

#endif // ARRAY_FUNCTIONS_H
```