#include <iostream>
#include <string>

int main() {
    std::string expression = "((2+3)*4)-(5/2)";
    int digitCount = 0;
    for (char c : expression) {
        if (isdigit(c)) {
            ++digitCount;
        }
    }
    std::cout << "Number of digits: " << digitCount << std::endl;

    int operatorCount = 0;
    for (char c : expression) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            ++operatorCount;
        }
    }
    std::cout << "Number of operators: " << operatorCount << std::endl;

    int openParenthesesCount = 0;
    int closeParenthesesCount = 0;
    for (char c : expression) {
        if (c == '(') {
            ++openParenthesesCount;
        }
        else if (c == ')') {
            ++closeParenthesesCount;
        }
    }
    std::cout << "Number of open parentheses: " << openParenthesesCount << std::endl;
    std::cout << "Number of close parentheses: " << closeParenthesesCount << std::endl;

    bool balancedParentheses = (openParenthesesCount == closeParenthesesCount);
    std::cout << "Balanced parentheses: " << (balancedParentheses ? "Yes" : "No") << std::endl;

    return 0;
}
