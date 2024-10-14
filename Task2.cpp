#include <iostream>

using namespace std;

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

            int first_digit1 = number1; 
            int first_digit2 = number2;

            int max_digit1 = number1;
            int max_digit2 = number2;

            int digit1 = 0;
            int digit2 = 0;

            while (max_digit1) {
                if (max_digit1 % 10 > digit1) 
                    digit1 = max_digit1 % 10;

                max_digit1 /= 10;
            }
            max_digit1 = digit1;

            while (max_digit2) {
                if (max_digit2 % 10 > digit2) 
                    digit2 = max_digit2 % 10;

                max_digit2 /= 10;
            }
            max_digit2 = digit2;


            int temp;

            while (first_digit1 >= 10) 
                first_digit1 /= 10;
            
            while (first_digit2 >= 10) 
                first_digit2 /= 10;
            
    

            if (first_digit1 > first_digit2) 
            {
                temp = arr[j]; 
                arr[j] = arr[i]; 
                arr[i] = temp; 
            } else if (first_digit1 == first_digit2) {
                if (max_digit1 > max_digit2) 
                {
                    temp = arr[j]; 
                    arr[j] = arr[i]; 
                    arr[i] = temp; 
                } else if (max_digit1 < max_digit2) {
                    temp = arr[i]; 
                    arr[i] = arr[j]; 
                    arr[j] = temp;
                } else {
                    if (number1 >= number2)
                    {
                        temp = arr[j]; 
                        arr[j] = arr[i]; 
                        arr[i] = temp;
                    } else {
                        temp = arr[i]; 
                        arr[i] = arr[j]; 
                        arr[j] = temp;
                    }
                }
            } else {
                temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp; 
            }
        }
    } 
    
    for (int i = 0; i < n; ++i) 
            cout << arr[i] << " ";

    return 0;
}