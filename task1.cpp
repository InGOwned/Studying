#include <iostream>

void reverseNumber(int n);

int main() {
    int N;
    std::cout << "Enter N > 0: ";
    std::cin >> N;

    std::cout << "Reversed number: ";
    reverseNumber(N);
    std::cout << std::endl;

    return 0;
}

void reverseNumber(int n) {
    if (n < 10) {
        std::cout << n;
        return;
    } else {
        std::cout << n % 10;
        reverseNumber(n / 10);
    }
}

