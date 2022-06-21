# Iterated List

- Accept [13_07_iterated_list](https://classroom.github.com/a/PhOp9RKU)
- Get [basic_test.cpp](basic_test.cpp)

One major problem with our simple list class is the fact that functions in the list class give up pointers to nodes within the list. This is an abomination. It goes against every principle of abstraction and encapsulation. We are going to right this travesty in this project.


## Iterators

Iterators are classes that encapsulate pointers. We wrap a pointer we want to be protected in an Iterator and in doing so, we control how the pointer will be used and in what context and we decide what to allow and disallow in the use of this pointer. 

Once the Iterator is in place, we will not be thinking of pointers, only Iterators. Iterators allow you to traverse data structures (such as linked lists) safely and without worrying about the calling function altering the nodes because they only get an iterator and not a pointer.


## Nested Classes
Please see [A Simple Iterator (Nested Classes)](https://docs.google.com/document/d/1hZQyeSlvRJq8xhVYjJklljzhKJxa5q0ByKfnydfKKKc/edit?usp=sharing) for an explanation of nested classes


## The Iterator Class
The Iterator class is a nested class within our List class. It provides a constructor, an increment, insertion, dereference, and member access operators.


## The List Class

Just like the simple list class, a node pointer called head (head_ptr would be better) points to the first node in the list.

The list class provides all the functions that the simple list provided, but it will wrap all node pointers (passed as arguments, or returned from the functions) in an Iterator object:

**NOTE**: Define all your Iterator functions INLINE (Inside the Iterator class itself).

```c++
#ifndef LIST_ITERATED_H
#define LIST_ITERATED_H

#include <iostream>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class List
{
public:
  class Iterator
  {
  public:
    //give access to list to access _ptr
    friend class List;

    //default ctor
    Iterator(){ }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p){ }

    //Casting operator: true if _ptr not NULL
    //This turned out to be a pain!
    operator bool(){ }

    //dereference operator
    T& operator *(){ }
    //member access operator
    T* operator ->(){ }
    //true if _ptr is NULL
    bool is_null(){ }
    
    //true if left != right
    friend bool operator !=(const Iterator &left, const Iterator &right){ }
    //true if left == right
    friend bool operator ==(const Iterator &left, const Iterator &right){ }
    
    //member operator:  ++it; or ++it = new_value
    Iterator& operator ++(){ }
    //friend operator: it++
    friend Iterator operator ++(Iterator &it, int unused){ }
  private:
    node<T>* _ptr; //pointer being encapsulated
  };

  //constructor: CTOR
  List();

  //BIG 3:
  List(const List<T> &copyThis);
  ~List();
  List& operator =(const List& RHS);

  //Operations:
  Iterator insert_head(T i);                    //insert at the head of list
  Iterator insert_after(T i, Iterator iMarker); //insert after iMarker
  Iterator insert_before(T i, Iterator iMarker);//insert before iMarker
  T Delete(List<T>::Iterator iMarker);  //delete node at iMarker
  Iterator search(const T &key) const;  //return Iterator to node [key], nullptr if not there

  //Accessors:
  const T& operator[](int index) const; //const version of the operator []
  T& operator[](int index);             //return item at index
  Iterator prev(Iterator iMarker);      //previous node: iMarker
  Iterator begin() const;               //Iterator to head node
  Iterator end() const;                 //Iterator to nullptr
  Iterator last_node() const;           //Iterator to last node

  //Checkers:
  int size() const { return _size; }
  bool empty() const { return _head == nullptr; }

  
  void Print() const;                   //print the list
  void PrintBackwards() const;          //print the list backwards

  template <typename U>                 //insertion operator, Note template arg U   
  friend ostream& operator <<(ostream& outs, const List<U>& l);
  
private:
  node<T>* _head;
  int _size;
};


//Definition of List Class

//TODO

#endif // LIST_ITERATED_H
```