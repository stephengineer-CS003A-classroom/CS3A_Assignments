# Vector Class

- Accept [11_p1_vector](https://classroom.github.com/a/OkCDKcOM)
- Get [basic_test.cpp](basic_test.cpp)

Please read the [Guidelines for classes](https://docs.google.com/document/d/1dkqJa-h6e-GmlNwc-zgX7IPTrU8YJNMLrbrLS8idU3k/edit?usp=sharing) before you begin. 

Include and call functions in `add_entry.h`

Have default constructors, operators, big three, etc.

```c++
template <typename T>
class Vector{
public:
  //constructor: CTOR
  Vector(int capacity = 100);
  Vector(T* arr, int size);

  //BIG 3
  ...

  //member access functions:
  T& operator [](int index);
  const T& operator [](int index) const;

  T& at(int index);                   //return reference to item at position index
  const T& at(int index) const;       //return a const item at position index
  
  T& front();                         //return item at position 0.
  T& back();                          //return item at the last position
  
  //Push and Pop functions:
  Vector& operator +=(const T& item); //push_back
  void push_back(const T& item);      //append to the end
  T pop_back();                       //remove last item and return it
  
  //Insert and Erase:
  void insert(int insert_here, const T& insert_this); //insert at pos
  void erase(int erase_this_index);   //erase item at position
  int index_of(const T& item);        //search for item. return index.

  //size and capacity:
  void set_size(int size);
  void set_capacity(int capacity);
  int size() const {return _size;}    //return _size
  int capacity() const {return _capacity;} //return _capacity
  bool empty() const;                 //return true if vector is empty
  
  //OUTPUT:
  template <typename U>
  friend ostream& operator <<(ostream& outs, const Vector<U>& _a);
private:
  int _capacity; //the space allocated
  int _size;     //the space used
  T* _buffer;    //point to vector
};
```