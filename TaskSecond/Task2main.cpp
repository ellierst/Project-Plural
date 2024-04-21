#include <iostream>
#include <string>

int digits(int n) {
    std::string numStr = std::to_string(n); 
    int uniqueDigits = 0;
    bool seen[10] = { false }; 
    for (char c : numStr) {
        int digit = c - '0'; 
        if (!seen[digit]) {
            seen[digit] = true; 
            ++uniqueDigits; 
        }
    }

    return uniqueDigits;
}

int main() {
    int num = 2024;
    std::cout << "Number of unique digits in " << num << ": " << digits(num) << std::endl;

    num = 5;
    std::cout << "Number of unique digits in " << num << ": " << digits(num) << std::endl;

    num = 10110111;
    std::cout << "Number of unique digits in " << num << ": " << digits(num) << std::endl;

    return 0;
}
