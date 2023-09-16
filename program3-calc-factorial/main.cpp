#include <iostream>

int main() {
    int n;
    long long factorial = 1;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Factorial is not defined for negative numbers.";
    } else {
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        std::cout << "Factorial of " << n << " = " << factorial;
    }

    return 0;
}
