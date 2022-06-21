# Linked List Functions

- Accept [13_00_linked_list_functions](https://classroom.github.com/a/CU7Tt80F)
- Get [basic_test.cpp](basic_test.cpp)

```c++
#ifndef NODE_H 
#define NODE_H 

#include <iostream> 

using namespace std;
 
template <typename T>
struct node
{
public:
    node(const T& item = T(), node* next = nullptr);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const node<U> &printMe);

    T _item;
    node* _next;
};

// Definition 

// TODO 

#endif // NODE_H 
```

Please note that the operators of a templated class require a different template argument than the template argument of the class they are friends with (U, and not T). This is only true when the definition of the friend function is outside the class declaration.

 
## Linked List functions

These are "free-floating" functions that do the heavy lifting for the List class we will be writing later. Do not make a class until you have these functions in place. The reason for this is that this method gives us the flexibility to design many similar classes effortlessly and quickly.

I suggest you study the algorithms you are going to use on paper very carefully before you start to write code. (Never write pointer or linked list-related code without first drawing boxes and arrows.) Linked list bugs (pointer-related bugs in general) tend to be elusive and hard to find and debug. The best strategy is avoidance.

```c++
#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <cassert>

#include "../node/node.h"

using namespace std;

// Declaration
//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T>* head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key);

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this);

//insert after ptr
template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this);

//insert before ptr
template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this);

//duplicate the list
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate list and return the last node of the copy
template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src);

//delete all the nodes
template <typename T>
void _clear_list(node<T>* &head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//insert
template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending=true);

//insert or add if a dup
template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending=true);

//node after which this item goes order: 0 ascending
template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending=true);

//Last node in the list, never use this function.
template <typename T>
node<T>* _last_node(node<T>* head);

// Definition

// TODO

#endif // LINKED_LIST_FUNCTIONS_H
```


## Testing

Test each group of functions using test functions defined in the main.

If you have any bugs in these functions, it will be very difficult to debug the higher-level classes built on these functions. So, be very cautious!