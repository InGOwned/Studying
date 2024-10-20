#include <iostream>

using namespace std;

int getFirstDigit(int n);
int getMaxDigit(int n);
void swap(int &a, int &b);


int main()
{   
    // setlocale(LC_ALL, "rus"); 

    cout << "TASK 2" << endl;

    const int n = 5; 
    int arr[n] {}; 
 
    for (int i = 0; i < n; i++) { 
        cout << "Enter a number: ";
        cin >> arr[i];
    } 

     for (int i = 0; i < n - 1; ++i) 
    { 
        for (int j = i + 1; j < n; ++j) 
        { 
            int number1 = arr[i];
            int number2 = arr[j];

            int first_digit1 = getFirstDigit(arr[i]);
            int first_digit2 = getFirstDigit(arr[j]);

            int max_digit1 = getMaxDigit(arr[i]);
            int max_digit2 = getMaxDigit(arr[j]);
            
            if (first_digit1 > first_digit2) 
            {
                swap(arr[i], arr[j]);
            } else if (first_digit1 == first_digit2) {
                if (max_digit1 > max_digit2) 
                {
                swap(arr[i], arr[j]);
                } else if (max_digit1 == max_digit2) {
                    if (number1 > number2) {
                        swap(arr[i], arr[j]);
                    }
                }
            }
        }
    } 
    
    for (int i = 0; i < n; i++) 
            cout << arr[i] << " ";

    return 0;
}


int getMaxDigit(int n) 
{   
    int max_digit = 0;
    while (n) 
    {
        if (n % 10 > max_digit) 
            max_digit = n % 10;

        n /= 10;
    }
    return max_digit;
}


int getFirstDigit(int n) 
{
    while (n >= 10) 
        n /= 10;
    
    return n;  
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}