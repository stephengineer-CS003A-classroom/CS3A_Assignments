# Rational Number Class

- Accept [11_p2_rational](https://classroom.github.com/a/ixAXqqJR)
- Get [basic_test.cpp](basic_test.cpp)

Please read the [Guidelines for classes](https://docs.google.com/document/d/1dkqJa-h6e-GmlNwc-zgX7IPTrU8YJNMLrbrLS8idU3k/edit?usp=sharing) before you begin. 

Rational will have the following declarations:

```c++
class Rational
{
public:
  Rational();
  Rational(int num, int denom);
  Rational(int w);        //whole number

  //mutator / setters
  void set(int num, int denom);
  void set_num(int n);
  void set_denom(int d);

  //accessors / getters
  int get_num() const;
  int get_denom() const;

  //error handling routines
  int error() const;      //return error state
  int is_error() const;   //checks for error condition and returns error code
  string error_description() const;
                          //return a descriptive error message
  
  void reset();           //resets number to 0/1 and clears error state
  //will return object whose error state is set
  //   if one of the operands is in error.
  friend Rational operator +(const Rational &num1, const Rational &num2);
  friend Rational operator -(const Rational &num1, const Rational &num2);
  friend Rational operator *(const Rational &num1, const Rational &num2);
  friend Rational operator /(const Rational &num1, const Rational &num2);
  
  //will print UNDEFINED if num is in error.
  friend ostream& operator <<(ostream &outs, const Rational &num);
  friend istream& operator >>(istream &ins, Rational &num);
private:
  int _n;                 //numerator
  int _d;                 //denominator
  int _error;             //error code
};
```

## Handling Errors
- private function `is_error()` will check for error conditions (in this case _d==0) It simply returns the error state, it does not set _error. The _error can be set like this: `_error=is_error()`;
- Any function that alters the denominator of the rational number will have to call is_error() to see if _error code must be set.
- All operators will have to call the CTOR to return their results. Therefore, if one of the operands is in _error, the operator must ensure the result will be as well.
- Do NOT output error messages from inside any of the class functions. Except the insertion operator will output "UNDEFINED" if the rational number is in _error.
- The calling function may call `rational::error_description()` to get a string containing the error message.
- Operators are friends of the class, not members of the class.
- Do not forget the const and pass by reference on arguments (when needed.)
- Do not forget the const keyword on the operator parameters and class functions


## Extra Test in main().cpp

In main() function create `test_rational()` function, which presents the user with the following menu:

```
[A]  [B]  e[X]it 
```

as the user presses A and B, ask for a rational and input the new values of a or b. You will call the `display_results()` function and pass it to two Rational objects. The `display_results()` function will display the result of all the arithmetic operations (+ - * /) on the two rationals.


## Sample output:

```
A: 4/1    B: 1/5
4/1 + 1/5 = 21/5
4/1 * 1/5 = 4/5
4/1 - 1/5 = 19/5
4/1 / 1/5 = 20/1
============================================

[A]  [B]  e[X]it 
: a
A: 3/4
A: 3/4    B: 1/5
3/4 + 1/5 = 19/20
3/4 * 1/5 = 3/20
3/4 - 1/5 = 11/20
3/4 / 1/5 = 15/4
============================================

[A]  [B]  e[X]it 
: b
B: 6/13
A: 3/4    B: 6/13
3/4 + 6/13 = 63/52
3/4 * 6/13 = 18/52
3/4 - 6/13 = 15/52
3/4 / 6/13 = 39/24
============================================

[A]  [B]  e[X]it 
: a
A: 1/0
A: UNDEFINED    B: 6/13
UNDEFINED + 6/13 = UNDEFINED
UNDEFINED * 6/13 = UNDEFINED
UNDEFINED - 6/13 = UNDEFINED
UNDEFINED / 6/13 = UNDEFINED
============================================

[A]  [B]  e[X]it 
: a
A: 2/5
A: 2/5    B: 6/13
2/5 + 6/13 = 56/65
2/5 * 6/13 = 12/65
2/5 - 6/13 = -4/65
2/5 / 6/13 = 26/30
============================================

[A]  [B]  e[X]it 
: x

=====================

Press <RETURN> to close this window...
```