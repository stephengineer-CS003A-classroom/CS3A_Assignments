# Reverse Polish Notation (RPN) and Shunting Yard Algorithm

- Accept [15_07_rpn_shunting_yard](https://classroom.github.com/a/EftvmLVX)
- Get [basic_test.cpp](basic_test.cpp)


## Implement [Reverse Polish Notation (RPN)](https://docs.google.com/document/d/1orxcAaCVnN6MvZJwNDrMLkUtBxyXppl5y6dVaAzYjmA/edit?usp=sharing)

```c++
#ifndef RPN_H
#define RPN_H

#include <iostream>

#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/function.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"

using namespace std;

class RPN
{
public:
  // CTOR
  RPN();
  RPN(const Queue<Token*>& input_q);
  
  // save input_q to member variable queue
  void set_input(const Queue<Token *> &input_q);

  // return result from member variable queue
  double operator()(double value = 0);
  // called by operator ()
  double rpn(double value = 0);

private:
  Queue<Token*> queue;
};

#endif //RPN_H
```


## Implement [Shunting Yard Algorithm](https://docs.google.com/document/d/1MAbJERpctca8mEh46BHBaSEpDREnuvHrVfwohcwrCck/edit?usp=sharing)

```c++
#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <iostream>
#include <cassert>

#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/function.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"

using namespace std;

class ShuntingYard
{
public:
  // CTOR
  ShuntingYard();
  ShuntingYard(const Queue<Token*>& input_q);

  // save input_q to member variable queue
  void infix(const Queue<Token*>& input_q);
  
  // generate postfix queue from infix queue
  Queue<Token*> postfix();
  Queue<Token*> postfix(const Queue<Token*>& input_q);
  // called by postfix() 
  Queue<Token*> shunting_yard();
private:
  Queue<Token*> queue;
};

#endif //SHUNTING_YARD_H
```


## "includes/token/constants.h" file:

```c++
#ifndef CONSTANTS_H
#define CONSTANTS_H

enum TOKEN_TYPES
{
  FUNCTION,
  INTEGER,
  OPERATOR,
  LPAREN,
  RPAREN,
  TOKEN
};

#endif //CONSTANTS_H
```

## Part of token.cpp for printing out tokens

```c++
#include "token.h"

Token::Token() {}

void Token::Print(ostream &outs) const
{
  outs << "TOKEN Print: DON't ^%#$# call me again!" << endl;
}

ostream& operator <<(ostream& outs, const Token* token)
{
  token->Print(outs);
  return outs;
}

ostream &operator<<(ostream &outs, const Token &token)
{
  token.Print(outs);
  return outs;
}
```