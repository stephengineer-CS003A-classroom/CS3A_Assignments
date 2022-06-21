# [Review 01 - Functions - Roman Numerals](https://docs.google.com/document/d/1NdTn8WXkQ9bPvEdMof5ufBVgy_sNvAJH2diButvb2yA/edit?usp=sharing)

- Accept [00_review_01_roman_numerals](https://classroom.github.com/a/_Tt02KfV)
- Get [main.cpp](main.cpp)

Implement functions in `includes/roman_numeral/roman_numeral.h`

```c++
#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#include <iostream>

using namespace std;

//Declaration
//translates one digit, using the strings specified for the one, five, and ten values
string roman_digit(int n, string one, string five, string ten);
//convert integer numbers to roman numbers
string get_roman_numeral(int n);
//covert one roman to number
int get_value(char a);
//convert roman numerals to integer numbers
int roman_to_decimal(string roman_numeral);

//Definition

//TODO

#endif // ROMAN_NUMERAL_H
```