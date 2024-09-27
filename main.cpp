#include <iostream>

using namespace std;

int main()
{
	cout << "Task 1" << endl;

	int A;
	int B;
	int C;

	cout << "Enter A, B, C: " << endl;
	cin >> A >> B >> C;

	if (A > B && B > C) {
		cout << (A - B - C) << endl;
	} else if (B > A && B % C == 0) {
		cout << (B / C + B - A) << endl;
	} else {
		cout << (A + B + C) << endl;
	}

	cout << "\nTask 2" << endl;

	int N;

	cout << "Enter N: ";

	if (!(cin >> N)) {
		cout << "Wrong input!" << endl;
		return 1;
	}
    

	switch (N)
	{
	case 0:
		cout << "Zero" << endl;
		break;
	case 1:
		cout << "One" << endl;
		break;
	case 2:
		cout << "Two" << endl;
		break;
	case 3:
		cout << "Three" << endl;
		break;
	case 4:
		cout << "Four" << endl;
		break;
	case 5:
		cout << "Five" << endl;
		break;
	case 6:
		cout << "Six" << endl;
		break;
	case 7:
		cout << "Seven" << endl;
		break;
	case 8:
		cout << "Eight" << endl;
		break;
	case 9:
		cout << "Nine" << endl;
		break;
	
	default:
		cout << "Not a Digit" << endl;
		break;
	}

	cout << "\nTask 3" << endl;

	int x = -1; 
    
	cout << "X == " << x << endl;

    if (x == -1) {
        cout << "X - Negative number" << endl;
    } else {
        cout << "X  Positive number" << endl;
    }

	return 0;
}