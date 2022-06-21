# Add Entry

- Accept [09_p6_add_entry](https://classroom.github.com/a/lbZU9bOM)
- Get [basic_test.cpp](basic_test.cpp)

I do not want to see any loops in functions.

Please read the [Guidelines for pointers](https://docs.google.com/document/d/1WDgzNbWrGjDA7739GjZ8Xna_RrUX95w6XqKL4mOmDpc/edit?usp=sharing) before you begin. 

IMPORTANT
- Rather than adding one to the capacity of the list, double the capacity when you run out of room. This is a much more realistic method. On `remove_entry`, `remove_last_entry`, `erase_entry`, reallocate half the space when the size reaches 1/4 of the capacity.
- Use `const int MINIMUM_CAPACITY = 3;` to minimum space of the array. Having a debug boolean flag allows the printing of a clear message that more space is being allocated whenever you are about to exceed the capacity. A message should also display when you allocate a smaller space for your list. Your output MUST allow me to see when memory management is taking place.
 
```c++
#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H

#include "../array_functions/array_functions.h"

// Declaration

// insert an item to an index
// double the capacity when you run out of room
template <typename T>
T* insert_entry(T* list, const T& insert_this, int insert_here, int& size, int& capacity);

// append entry to the end
template<typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);

// remove the entry by index
// reallocate half the space when the size reaches 1/4 of the capacity
template <typename T>
T* erase_entry(T* list, int index, int& size, int& capacity); 

// remove the first ocurred entry from list
template<typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);

// remove the last entry from list
template<typename T>
T* remove_last_entry(T* list, T& popped, int& size, int& capacity);

// Definition

// TODO

#endif // ADD_ENTRY_H
```

## Extra Test in main().cpp

```c++
#include <iostream>
#include <iomanip>

#include "includes/add_entry/add_entry.h"
#include "includes/array_functions/array_functions.h"

using namespace std;

template<typename T>
void test_string();

int main(int argv, char** argc)
{
    cout << "\n" << endl;

    test_string<string>();

    cout << "\n\n=====================" << endl;
    return 0;
}


template<typename T>
void test_string() {
    int capacity = 3;
    int size = 0;
    T* list = allocate<string>(capacity);
    list = add_entry(list, string("Erika"), size, capacity);
    print_array(list, size, capacity);
    list = add_entry(list, string("Red"), size, capacity);
    print_array(list, size, capacity);
    list = add_entry(list, string("Bo"), size, capacity);
    print_array(list, size, capacity);
    list = add_entry(list, string("Pierson"), size, capacity);
    print_array(list, size, capacity);
    list = add_entry(list, string("Mike"), size, capacity);
    print_array(list, size, capacity);
    list = add_entry(list, string("Mac"), size, capacity);
    print_array(list, size, capacity);
    list = add_entry(list, string("Paula"), size, capacity);
    print_array(list, size, capacity);
    cout << "Deleting Erika" << endl;
    list = remove_entry(list, string("Erika"), size, capacity);
    print_array(list, size, capacity);
    cout << "Deleting Bo" << endl;
    list = remove_entry(list, string("Bo"), size, capacity);
    print_array(list, size, capacity);
    cout << "Deleting Mike" << endl;
    list = remove_entry(list, string("Mike"), size, capacity);
    print_array(list, size, capacity);
    cout << "Deleting Pierson" << endl;
    list = remove_entry(list, string("Pierson"), size, capacity);
    print_array(list, size, capacity);
    cout << "Deleting Red" << endl;
    list = remove_entry(list, string("Red"), size, capacity);
    print_array(list, size, capacity);
}


// ( 1/ 3)   [  Erika ]
// ( 2/ 3)   [  Erika  Red ]
// ( 3/ 3)   [  Erika  Red  Bo ]
// ( 4/ 6)   [  Erika  Red  Bo  Pierson ]
// ( 5/ 6)   [  Erika  Red  Bo  Pierson  Mike ]
// ( 6/ 6)   [  Erika  Red  Bo  Pierson  Mike  Mac ]
// ( 7/12)   [  Erika  Red  Bo  Pierson  Mike  Mac  Paula ]
// Deleting Erika
// ( 6/12)   [  Red  Bo  Pierson  Mike  Mac  Paula ]
// Deleting Bo
// ( 5/12)   [  Red  Pierson  Mike  Mac  Paula ]
// Deleting Mike
// ( 4/12)   [  Red  Pierson  Mac  Paula ]
// Deleting Pierson
// ( 3/ 6)   [  Red  Mac  Paula ]
// Deleting Red
// ( 2/ 6)   [  Mac  Paula ]
```