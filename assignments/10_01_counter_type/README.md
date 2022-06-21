# Counter Type

- Accept [10_01_counter_type](https://classroom.github.com/a/26nhNR2i)
- Get [basic_test.cpp](basic_test.cpp)

Please read the [Guidelines for classes](https://docs.google.com/document/d/1dkqJa-h6e-GmlNwc-zgX7IPTrU8YJNMLrbrLS8idU3k/edit?usp=sharing) before you begin. 

Design the class using the specifications in the textbook.

CounterType will have the following declarations:

```c++
class Counter_Type
{
public:
    Counter_Type();
    Counter_Type(int n);            //set initial value of the counter
    bool inc();                     //increment by one
    bool dec();                     //decrement by one
    bool is_error() const;          //true: the object is in error (underflow)
    bool reset();                   //reset _count to zero and _error to false
    int count() const;              //retrieve the _count
private:
    int _count;
    bool _error;
};
```

The `dec()` function will set the _error to true if the count is zero upon being called.


## Extra Test in main().cpp

In main() function create the `test_CounterType()` function, which presents the user with the following menu:

```
[+]  [-]  [R]eset  e[X]it  :
```

as the user presses + and -, you will call the appropriate functions from the CounterType object and call the `display_counter()` function and pass it to the CounterType object. The `display_counter()` function will display the count if the object is not in error. Otherwise, it will display ERROR.


## Sample Output:
```
-------
| 0000|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
| 0001|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
| 0002|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
| 0003|
-------
[+]  [-]  [R]eset:  e[X]it  : -
-------
| 0002|
-------
[+]  [-]  [R]eset:  e[X]it  : -
-------
| 0001|
-------
[+]  [-]  [R]eset:  e[X]it  : -
-------
| 0000|
-------
[+]  [-]  [R]eset:  e[X]it  : -
-------
|ERROR|
-------
[+]  [-]  [R]eset:  e[X]it  : -
-------
|ERROR|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
|ERROR|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
|ERROR|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
|ERROR|
-------
[+]  [-]  [R]eset:  e[X]it  : r
-------
| 0000|
-------
[+]  [-]  [R]eset:  e[X]it  : +
-------
| 0001|
-------
[+]  [-]  [R]eset:  e[X]it  : -
-------
| 0000|
-------
[+]  [-]  [R]eset:  e[X]it  : x
-------------------
Press <RETURN> to close this window...
```