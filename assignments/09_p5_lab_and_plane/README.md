# Lab and Plane: using dynamic two-dimensional arrays 

- Accept [09_p5_lab_and_plane](https://classroom.github.com/a/j4M04cBJ)
- Get [basic_test.cpp](basic_test.cpp)

Dynamic Two Dimensional Array (with variable column count per row)

- Please read the [Guidelines for pointers](https://docs.google.com/document/d/1WDgzNbWrGjDA7739GjZ8Xna_RrUX95w6XqKL4mOmDpc/edit?usp=sharing) before you begin. 
- Build lower-level functions such as Allocate, Initialize, Get, Read and write...
- Build two applications for Plane reservation/cancel and Lab login/logout based on these low-level functions.
    - For Lab, need login and a logout function.
    - For Plane, need reserve and a cancel function.
        - These functions return true if the operation was successful and false otherwise.
    - For Plane, store 0 or 1 to indicate availability. const bool RESERVED = true;
    - For Lab, store student id to indicate the student is logged into a particular station.

## Dynamic Two Dimensional Array Functions:

```c++
#ifndef TWO_D_FUNCTIONS_H
#define TWO_D_FUNCTIONS_H

#include "../array_functions/array_functions.h"

// Declaration

// Get how many elements in the array until the last -1
int array_size(int* sizes);
// check if the given row and column are a valid index on a two D array defined by sizes.
bool index_is_valid(int* sizes, int row, int col);

// allocate a 2D array return pointer to pointer
template <typename T>
T** allocate_twod(int* sizes);
// deallocate 2D array
template <typename T>
T** deallocate_twod(T** twod, int size);
// read and write an item in 2D array
template <typename T>
T& get_twod(T** twod, int row, int col);
// read an item in 2D array
template <typename T>
T read_twod(T** twod, int row, int col);
// write an item from 2D array
template <typename T>
void write_twod(T** twod, int row, int col, const T& item);
// initialize 2D array
template<typename T>
void init_twod(T** twod, int* sizes, T init_item = T());
// search an item in 2D array
template<typename T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);
// return a pointer to the item if found, nullptr if not found:
template<typename T>
T* search_twod(T** twod, int* sizes, const T& key);
// print 2D array
template <typename T>
void print_twod(T** twod, int* sizes, ostream& outs = cout);

// Definition

// TODO

#endif  // TWO_D_FUNCTIONS_H
```

## Lab Functions:

based on the dynamic two-dimensional array functions

```c++
#ifndef LAB_H
#define LAB_H

#include "../two_d_functions/two_d_functions.h"

// Declaration
// initialize lab
int** init_lab(int* stations);
// log user in lab and station with id
bool login(int** labs, int lab, int station, int id);
// log user out from lab and station with id
bool logout(int** labs, int* sizes, int id);

#endif  // LAB_H
```

## Plane Functions:

```c++
#ifndef PLANE_H
#define PLANE_H

#include "../two_d_functions/two_d_functions.h"

// Declaration
bool** init_plane();
bool reserve(bool** plane, int row, int seat);
bool cancel(bool** plane, int row, int seat);
void print_plane(bool** plane);

#endif  // PLANE_H
```

## Extra Test in main().cpp

```c++
#include <iostream>
#include <iomanip>

#include "includes/lab/lab.h"
#include "includes/two_d_functions/two_d_functions.h"

using namespace std;

void test_lab();

int main(int argv, char** argc)
{
  cout << "\n" << endl;

  test_lab();

  cout << "\n\n=====================" << endl;
  return 0;
}

void test_lab(){
    char command;
    int id, lab, station;
    int lab_sizes[] = {4,3,2,-1};
    int** labs = init_lab(lab_sizes);
    cout << "after init" << endl;
    print_twod(labs, lab_sizes);
    cout<<"log[i]n    log[o]ut      e[x]it"<<endl;
    cout<<":"; 
    cin>>command;
    while(toupper(command) != 'X'){
        switch(toupper(command)){
        case 'I':
            cout<<"---- LOG IN: ------"<<endl;
            cout<<"labs: ";
            print(lab_sizes, array_size(lab_sizes));
            cout<<endl;

            cout<<"id: ";
            cin>>id;
            cout<<"lab: ";
            cin>>lab;
            cout<<"station: ";
            cin>>station;
            if (index_is_valid(lab_sizes, lab, station)){
                if (login(labs, lab, station,id)){
                    cout<<"you are logged in in lab "<<lab<<", station: "<<station<<endl;
                } else{
                    cout<<"lab "<<lab<<", station "<<station<<" is occupied"<<endl;
                }
            } //valid index
            else{
                cout<<"["<<lab<<"]["<<station<<"] is invalid. "<<endl;
            }
            break;
        case 'O':
            cout<<"---- LOG OUT: ------"<<endl;
            cout<<"id: ";
            cin>>id;
            if (logout(labs, lab_sizes, id)) {
                cout << "you have successfully logged out" << endl;
            } else {
                cout << "you are not logged in. id: " << id << endl;
            }
        } //switch
        print_twod(labs, lab_sizes);

        cout<<"log[i]n    log[o]ut      e[x]it"<<endl;
        cout<<":";
        cin>>command;
    }//while
}
```

## Labs Sample Output:
```
after init
     0     0     0     0
     0     0     0
     0     0
log[i]n    log[o]ut      e[x]it
:i
---- LOG IN: ------
labs:      4     3     2
id: 388
lab: 0
station: 2
you are logged in in lab 0, station: 2
     0     0   388     0
     0     0     0
     0     0
log[i]n    log[o]ut      e[x]it
:i
---- LOG IN: ------
labs:      4     3     2
id: 465
lab: 1
station: 2
you are logged in in lab 1, station: 2
     0     0   388     0
     0     0   465
     0     0
log[i]n    log[o]ut      e[x]it
:i  
---- LOG IN: ------
labs:      4     3     2
id: 666
lab: 2
station: 3
[2][3] is invalid. 
     0     0   388     0
     0     0   465
     0     0
log[i]n    log[o]ut      e[x]it
:i
---- LOG IN: ------
labs:      4     3     2
id: 233
lab: 2
station: 0
you are logged in in lab 2, station: 0
     0     0   388     0
     0     0   465
   233     0
log[i]n    log[o]ut      e[x]it
:i
---- LOG IN: ------
labs:      4     3     2
id: 233
lab: 0
station: 0
you are logged in in lab 0, station: 0
   233     0   388     0
     0     0   465
   233     0
log[i]n    log[o]ut      e[x]it
:o
---- LOG OUT: ------
id: 555
you are not logged in. id: 555
   233     0   388     0
     0     0   465
   233     0
log[i]n    log[o]ut      e[x]it
:o
---- LOG OUT: ------
id: 388
you have successfully logged out
   233     0     0     0
     0     0   465
   233     0
log[i]n    log[o]ut      e[x]it
:o
---- LOG OUT: ------
id: 233
you have successfully logged out
     0     0     0     0
     0     0   465
     0     0
log[i]n    log[o]ut      e[x]it
:x


=====================
```