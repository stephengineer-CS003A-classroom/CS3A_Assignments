# Stack and Queue

- Accept [13_04_stack_queue](https://classroom.github.com/a/zPjvrm7d)
- Get [basic_test.cpp](basic_test.cpp)


Build a Stack and a Queue class based on the linked list functions you have built.

**NO** "linked list code" should be visible inside these classes. If you need something done, call a function.


## Stack

```c++
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Stack
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Stack;

    //Default CTOR
    Iterator(){ }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p){ }

    //Casting operator: true if _ptr not NULL
    //This turned out to be a pain!
    operator bool() { }
    
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
  Stack();

  //BIG 3:
  Stack(const Stack<T>& copyMe);
  ~Stack();
  Stack<T>& operator =(const Stack<T>& RHS);

  //Operations:
  void push(T item);
  T pop();

  //Accessors:
  Iterator begin() const;            //Iterator to the head node
  Iterator end() const;              //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T top();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Stack<U>& printMe);

private:
  node<T>* _top;
  int _size;
};

//Definition

//TODO

#endif // MYSTACK_H
```


## Queue

```c++
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Queue
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Queue;

    //Default CTOR
    Iterator(){ }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p){ }

    //Casting operator: true if _ptr not NULL
    //This turned out to be a pain!
    operator bool() { }

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
  Queue();

  //BIG 3:
  Queue(const Queue<T>& copyMe);
  ~Queue();
  Queue<T>& operator =(const Queue<T>& RHS);

  //Operations:
  void push(T item);                  //Enqueue
  T pop();                            //Dequeue

  //Accessors:
  Iterator begin() const;             //Iterator to the head node
  Iterator end() const;               //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T front();
  T back();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Queue<U>& printMe);
  
private:
  node<T>* _front;
  node<T>* _rear;
  int _size;
};


//Definition

//TODO

#endif //MYQUEUE_H
```