# Mom's Counter

- Accept [10_p6_moms_counter](https://classroom.github.com/a/rkyf-f_J)
- Get [basic_test.cpp](basic_test.cpp)

Please read the [Guidelines for classes](https://docs.google.com/document/d/1dkqJa-h6e-GmlNwc-zgX7IPTrU8YJNMLrbrLS8idU3k/edit?usp=sharing) before you begin. 

MCounter will have the following declarations:

```c++
class MCounter
{
public:
    MCounter();
    int add_1();                //increment functions
    int add_10();
    int add_100();
    int add_1000();
    int reset();                //reset error  state, _count
    int count() const;          //returns _count
    bool error() const;         //returns _error
    bool is_error() const;      //true  if an error has occurred
private:
    int add(int n);             //add n to _count
    int _count;
    bool _error;
};
```

## Extra Test in main().cpp

In main() function create `test_MCounter()` function, which presents the user with the following menu:

```
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it  :
```

As the user presses A, S, D, and F, you will call the appropriate functions from the MCounter object and call the `display_counter()` function and pass it to the CounterType object. The `display_counter()` function will display the count if the object is not in error. Otherwise, it will display ERROR.

Once the object goes into the error state, no valid count exists until the user calls `reset()`


## Sample Output:

```
-------
| 0000|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : f
-------
| 0001|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : f
-------
| 0002|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : f
-------
| 0003|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : d
-------
| 0013|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : d
-------
| 0023|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : s
-------
| 0123|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : s
-------
| 0223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : a
-------
| 1223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : a
-------
| 2223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : a
-------
| 3223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : a
-------
| 4223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : a
-------
| 5223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1  [R]eset  e[X]it : a
-------
| 6223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : a
-------
| 7223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : a
-------
| 8223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : a
-------
| 9223|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : a
-------
|ERROR|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : f
-------
|ERROR|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : d
-------
|ERROR|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : a
-------
|ERROR|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : r
-------
| 0000|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : s
-------
| 0100|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : s
-------
| 0200|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : f
-------
| 0201|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : f
-------
| 0202|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : f
-------
| 0203|
-------
[A] 1000  [S] 100  [D] 10  [F] 1   [R]eset  e[X]it : x


======================
Press <RETURN> to close this window...
```