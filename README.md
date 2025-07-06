# COMPILER-DESIGN-BASICS

COMPANY NAME - CODTECH IT SOLUTIONS

NAME - Manthan Gupta

INTERN ID - CT06DN1592

DOMAIN NAME - C++ Programming 

DURATION - 6 WEEKS(May 21st to July 6th 2025)

MENTOR - NEELA SANTHOSH KUMAR

Description:

📌 Overview
This C++ program is a recursive descent parser that evaluates simple arithmetic expressions entered by the user. It supports:
Basic arithmetic operations: +, -, *, /
Integer values (no decimals or negatives)
Parentheses for controlling operator precedence
Whitespace handling
Interactive input with support for "exit" command

🔧 Header Files Used
#include <iostream>: For input/output operations.
#include <string>: To handle input as a string.
#include <cctype>: Provides functions like isspace() and isdigit().

📦 Global Variables
string input: Stores the current input expression.
int pos: Keeps track of the current character position while parsing the string.

🧠 Main Idea: Recursive Descent Parsing
The program follows recursive descent parsing to evaluate the expression in compliance with the correct order of operations.
It breaks the grammar down into three rules:
expression: Handles addition and subtraction.
term: Handles multiplication and division.
factor: Handles parentheses and numbers.
This ensures operator precedence:
() > *// > +/-

🔁 Function Descriptions
1. void skipWhitespace()
Skips over any whitespace characters.
Ensures spaces in the input do not affect parsing.

2. int expression()
Grammar Rule: E → T (+|-) E
Evaluates a complete expression by first parsing a term().
Then it checks for + or - operators and recursively processes more terms.
Correctly implements left-to-right evaluation for addition/subtraction.

3. int term()
Grammar Rule: T → F (*|/) T
Called by expression() to evaluate multiplication or division.
Evaluates a factor(), then checks for * or / and recursively processes the next factor().
Maintains operator precedence over addition and subtraction.

4. int factor()
Grammar Rule: F → (E) | number
If the current character is '(', it recursively calls expression() to evaluate the subexpression inside the parentheses.
Otherwise, it reads a numeric value from the string:
value = value * 10 + (input[pos++] - '0') builds multi-digit numbers.

🧪 Main Function Behavior
Displays a welcome message and feature list.
Enters an infinite loop to repeatedly take user input:
Uses getline(cin, input) to support full-line input.
Exits loop if input is "exit".
Calls expression() to evaluate the expression.
Resets pos = 0 each time to start from the beginning of the new input.
If parsing is successful, prints the result.
If any error occurs (e.g., invalid format), it catches the exception using try-catch and shows an error message.

✅ Strengths
Simple, clean recursive design.
Proper handling of operator precedence.
Accepts input with or without spaces.
Easy to extend for more complex arithmetic or variables.

💡 Possible Improvements
Add support for negative numbers and decimal points.
Implement error messages for specific problems (e.g., mismatched parentheses).
Extend to support unary operations like -5 or +3.
Add variable assignment and memory for previous results.

📚 Conclusion
This is a great example of building a mini calculator using recursive descent parsing in C++. It's ideal for beginners learning parsing, expression trees, or interpreter basics. The design is extensible and demonstrates clean separation between grammar rules and evaluation logic.

Output:
<img width="1481" height="357" alt="Image" src="https://github.com/user-attachments/assets/cd15b31f-b39c-4be2-8269-f9b8f6e27f9f" />
