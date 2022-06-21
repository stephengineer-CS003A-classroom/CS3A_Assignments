# Sorted List

- Accept [13_09_sorted_list](https://classroom.github.com/a/DFYTSZHc)
- Get [basic_test.cpp](basic_test.cpp)


## Overview
This is yet anot
her class that gives a special type of access to the underlying linked list structure. This time, we make sure the list is sorted and remains sorted. This means, no more inserting before or after a marker, and no more inserting at the head of the list. There will be one insert function that will insert the items in a sorted manner into the list.


## How to start

The insert functions need to be re-written, but thankfully, we already have everything we need in the lower-level functions.

1. Make a copy of your list_terated.h and rename it to list_sorted.h
1. Remove insert_head, insert_after, insert_before.
1. Create one insert function: `Iterator insert(const T& i); //Insert i`
1. Add two list private member variables (modify CTOR)
     - bool _order;  // default in ascending/true
     - bool _unique; // if not a unique list, duplicates are allowed. if this is a unique test, we will ADD the new item to the existing one.
1. Implement three functions in linked_list_functions.h: `_insert_sorted`, `_insert_sorted_and_add`, `_where_this_goes`


## Note

A few extras: this class has an _order and a _unique member variable which are initialized via the class constructor. These will have grave effects on the Insert function.

### Insert

There are three things to consider:

1. `_order`: will the list be sorted in ascending (default) or the descending order?
1. Is the list _unique? If not a unique list, duplicates are allowed. If this is a unique test, we will ADD the new item to the existing one. Obviously, this does not make sense for integer lists. Adding 4 to the existing 4 in the list (and getting an 8) is not reasonable, but with lists of some other entities, this makes life easier. We'll explore some more flexible ways of dealing with duplicates at a later time
1. Use InsertSorted, or InsertSorted_and_add linked list functions.

### _where_this_goes linkedlist function, a review

_where_this_goes gives you the node BEFORE an item should be inserted in a sorted list depending on whether the list is sorted in ascending or descending order. This function will return a NULL if the item will be inserted at the head of the list.

### _insert_sorted linkedlist function, a review

_insert_sorted will call _where_this_goes and inserts the item either at the head of the list or after the marker is returned by the _where_this_goes function.

### _insert_sorted_and_add linkedlist function, a review

This function does the same task as _insert_sorted, except if the marker from _where_this_goes points to a node with the same _item as the item being inserted, the item will be added to the existing _item