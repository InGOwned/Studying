#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cout << "Side A: ";
    cin >> A;
    if (A <= 0) {
        cout << "Side 'A' shold be greater than 0" << endl;
        return -1;
    }

    cout << "Side B: ";
    cin >> B;

    if (B >= 20) {
        cout << "Side 'B' shold be lesser than 20" << endl;
        return -1;
    }
    
    cout << A * B << endl;
    return 0;
}