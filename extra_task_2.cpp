#include <iostream>

using namespace std;


int sumOfDigits(int number) {
    int result = 0;

    while (number > 0) {
        result += number % 10;
        number /= 10;
    }

    return result;
}


int main() {
    int frequency[28] = {0};

    for (int num = 0; num <= 999; num++) 
    {
        int digitSum = sumOfDigits(num);
        frequency[digitSum]++;
    }

    int total = 0;

    for (int index = 0; index < 28; index++) 
    {
        total += frequency[index] * frequency[index];
    }

    cout << total;

    return 0;
}
