# Final Project

- Accept [99_00_final_project](https://classroom.github.com/a/rUUpsXPd)

Remember, the project is to be submitted by the date and time. Late submissions will lose 10%

Code must be FULLY COMMENTED.


## [SFML](https://www.sfml-dev.org/)

Before working on final project, you should familiar with SFML.
- [Install SFML (Windows)](https://drive.google.com/file/d/1fHHAV7YIhNbrM-Zl0X-EJ879DS94JxZC/view?usp=sharing)
- [Install SFML (Mac)](https://docs.google.com/document/d/1x1n6g70OMr4AjLbf73KOd5mDQu-2EU29XKltka4jQ5g/edit?usp=sharing)
- [Start SFML](https://drive.google.com/file/d/1FnIoJjAWXD18M3OcH03tVyXo4tkNmdSr/view)


## Graphing calculator

- The calculator will take an expression made up of numbers, instances of a single variable, and Trig functions, in addition to functions taking more than one argument such as Max(a, b)
- The calculator will draw a graph of the function for a given interval and given increments:
    - queue < Point > PlotExpression (string expression, double low, double high, double increments);
- This function takes an expression as a string, the high and low values for the function variable, and the increments and produces a queue of points that represent the graph.
- Make sure you handle:
    - Functions (especially, the Trig functions)
    - The unary operator


## Hints
- Shunting Yard Algorithm
- Handing Variables
- variables are just like numbers. So, When you see a variable, push it into the output queue.


### Handling Functions:

Functions are like operators with highest precedence:

5*(Max(x,4) + 6)  ->  5 x 4 Max 6 + * 

 

# Notes

Follow all the design guidelines discussed in class for the Shunting Yard algorithm, Evaluation algorithm, etc.

No Test = No Score: This project is meaningless without complete and accurate testing.