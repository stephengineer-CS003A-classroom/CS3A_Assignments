# Simple List Class

- Accept [13_03_simple_list_class](https://classroom.github.com/a/_JZN1NPZ)
- Get [basic_test.cpp](basic_test.cpp)

Having implemented our [linked List functions](../13_00_linked_list_functions/), we are now ready to design and implement a simple Linked List class:

## List Class

```c++
#ifndef LIST_SIMPLE_H
#define LIST_SIMPLE_H

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class List
{
public:
  //constructor: CTOR
  List();

  //BIG 3
  List(const List<T> &copyThis);
  ~List();
  List& operator =(const List& RHS);

  //Operations:
  node<T>* insert_head(T i);                     //insert at the head of list
  node<T>* insert_after(T i, node<T>* iMarker);  //insert after iMarker
  node<T>* insert_before(T i, node<T>* iMarker); //insert before iMarker
  T Delete(node<T>* iMarker);                    //delete node at iMarker
  node<T>* search(const T &key);                 //return pointer to node key, nullptr if not there

  //Accessors:
  const T& operator[](int index) const;          //const version of the operator []
  T& operator[](int index);                      //return item at index
  node<T>* prev(node<T>* iMarker);               //previous node: iMarker
  node<T>* begin() const;                        //return the head node
  node<T>* end() const;                          //return the tail (nullptr)
  node<T>* last_node() const;                    //return the last node

  //Checkers:
  int size() const;
  bool empty() const;
  
  //Helpers:
  
  void Print() const;                            //print the list
  void PrintBackwards() const;                   //print the list backwards

  template <typename U>                          //insertion operator, Note template arg U  
  friend ostream& operator <<(ostream& outs, const List<U>& l);
private:
  node<T>* _head;
  int _size;
};

//Definations

//TODO

#endif // LIST_SIMPLE_H
```

### Extra Test in main().cpp

In main() function create the `test_list_simple()` function, which presents the user with the following menu:

```
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : 
```

as the user presses R, A, B, D, S, P, N, H, E, X, you will call the appropriate functions from the list_simple object and call the `display_list()` function and pass it to the list_simple object and cursor_position integer. The `display_list()` function will display the list with '{ }' as the cursor.

The options will be able to add a random number after the current position (marked by braces), insert a number before or after the current position, delete the node at the current position, search for an item that may be in the list, or navigate the current position to the next or previous node, or to go to the home position, or the end of the list.

## Note

- The cursor position is maintained in the test function and NOT in the List class. The position of the cursor is shown by a pair of braces '{ }' and it will be adjusted appropriately as operations are executed. Deleting a node will cause the cursor position to be set to the beginning of the list. (Why is that?)
- Can you see the problem with this class? How vulnerable is this class to outside intrusion? How serious is this problem?

## Sample Output:

The following comments are for explanations of activities in the sample run

```
/*
 * [C]omments like this: (these are added after the program was run)
 */
```

```
/*
 * Initial list and menu. Cursor is at the head:
 */

{6}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

/*
 * [N]ext: once you get to the end of the list, the cursor will stay there.
 * 		It will not fall off
 */
 
[6]->{54}->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->{6}->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->[6]->{35}->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n
 
[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n
 
[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

[6]->[54]->[6]->[35]->{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

/*
 * [P]revious: once you get to the begining of the list, 
 * 		the cursor will stay there.
 *      It will not fall off
 */
 
[6]->[54]->[6]->{35}->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

[6]->[54]->{6}->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

[6]->{54}->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

{6}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

{6}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

{6}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : p

/*
 * [R]andom: inserts a random item after the current position.
 */
 
{6}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

[6]->{90}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

[6]->[90]->{80}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

/*
 * [A]fter: inserts an item after the current position
 */

[6]->[90]->[80]->{71}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : a

: 77
[6]->[90]->[80]->[71]->{77}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : n

/*
 * [B]efore: inserts an item before the current position
 */
 
[6]->[90]->[80]->[71]->[77]->{54}->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : b 
: 55
[6]->[90]->[80]->[71]->[77]->{55}->[54]->[6]->[35]->[17]->|||

[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

/*
 * [D]elete: deletes the item at the current position and resets position of cursor
 *      NOTE: deleting on an empty list does not cause a crash.
 */
 
{6}->[90]->[80]->[71]->[77]->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{90}->[80]->[71]->[77]->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{80}->[71]->[77]->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{71}->[77]->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{77}->[54]->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{54}->[6]->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{6}->[35]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{35}->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

/*
 * [D]elete: on an empty list does not cause a crash
 */

|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

/*
 * [R]andom: on an empty list will add a random number at the head of the list
 */

|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

{99}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

/*
 * [A]fter: on an empty list will add a number at the head of the list
 */
 
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : a
: 44
{44}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : d

/*
 * [B]efore: on an empty list will add a number at the head of the list
 */

|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : b
: 33
{33}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r  

[33]->{99}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

[33]->[99]->{13}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

[33]->[99]->[13]->{16}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : r

/*
 * [H]ome and [E]nd take the current position to the begining 
 *		and the end of the list
 */

[33]->[99]->[13]->[16]->{40}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : h

{33}->[99]->[13]->[16]->[40]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : s
: 99

/*
 * [S]earch will move the cursor to the position of the key if it is found. No change 
 *         in cursor position if key is not found in the list.
 */

[33]->{99}->[13]->[16]->[40]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : s
: 16

[33]->[99]->[13]->{16}->[40]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : s
: -42

[33]->[99]->[13]->{16}->[40]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd e[X]it : x

/*
 * e[x]it: will exit the proogram
 */

 
---------------------- END ----------------------
```