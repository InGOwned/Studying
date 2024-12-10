#include <iostream>

using namespace std;

bool isSumOfDigitsMultipleOfSix(int num);
bool containsDigitOne(int num);


int main()
{ 
    const int N_Max  = 20000;
    int mas[N_Max];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> mas[i];
    

    for (int i = 0; i < n; i++) 
    {
        if (isSumOfDigitsMultipleOfSix(mas[i]))
        {
            for(int j = i; j < n - 1; j++)
                mas[j] = mas[j+1];
            i--;
            n--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (containsDigitOne(mas[i])) 
        {
            for (int j = n; j > i; j--)
                mas[j] = mas[j - 1];
            i++;
            n++;
        }
    }

    cout << "\nResult: ";
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;

}


bool isSumOfDigitsMultipleOfSix(int num) 
{
    int sumOfDigits = 0;

    while (num) 
    {
        sumOfDigits += num % 10;
        num /= 10;
    }

    if (sumOfDigits % 6 == 0) 
    {
        return true; 
    }

    return false;
}

bool containsDigitOne(int num) 
{
    while (num) {
        if (num % 10 == 1) {
            return true; 
        }
        num /= 10;
    }
    return false;
}