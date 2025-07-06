#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Global variables
string input;
int pos = 0;

// --- Function declarations ---
int expression();
int term();
int factor();

void skipWhitespace() {
    while (isspace(input[pos])) pos++;
}

// --- Parsing Expressions (E → T (+|-) E) ---
int expression() {
    int result = term();
    skipWhitespace();

    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos++];
        skipWhitespace();
        int next = term();
        if (op == '+') result += next;
        else result -= next;
        skipWhitespace();
    }

    return result;
}

// --- Parsing Terms (T → F (*|/) T) ---
int term() {
    int result = factor();
    skipWhitespace();

    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos++];
        skipWhitespace();
        int next = factor();
        if (op == '*') result *= next;
        else result /= next;
        skipWhitespace();
    }

    return result;
}

// --- Parsing Factors (F → (E) | number) ---
int factor() {
    skipWhitespace();

    if (input[pos] == '(') {
        pos++; // skip '('
        int result = expression();
        if (input[pos] == ')') pos++; // skip ')'
        return result;
    }

    int value = 0;
    while (isdigit(input[pos])) {
        value = value * 10 + (input[pos++] - '0');
    }
    return value;
}

// --- Main ---
int main() {
    cout << "=== Simple Arithmetic Expression Evaluator ===\n";
    cout << "Supports + - * / and parentheses\n\n";

    while (true) {
        cout << "Enter expression (or 'exit'): ";
        getline(cin, input);
        if (input == "exit") break;

        try {
            pos = 0;
            int result = expression();
            cout << "Result: " << result << "\n\n";
        } catch (...) {
            cout << "❌ Error: Invalid Expression\n\n";
        }
    }

    return 0;
}
