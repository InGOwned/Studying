#include <iostream>

using namespace std;

int main() {
    int x = 0b101001010111;
    int bit_value = 0;
    int position;

	cout << "Enter position: ";
	cin >> position;

    cout << "\nx = " << x << endl;

    if ((x & (1u << position)) != 0) {
        bit_value = 1;
    } else {
        bit_value = 0;
    }

    cout << "\nValue of the " << position << "-th bit is: " << bit_value << endl;

    return 0;
}
