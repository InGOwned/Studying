#include <iostream>

using namespace std;

int main()
{   
    setlocale(LC_ALL, "rus"); 

    cout << "TASK 2" << endl;

    const int n = 5; 
    int arr[n] {}; 
 
    for (int i = 0; i < n; i++) { 
        cout << "¬ведите число: ";
        cin >> arr[i];
    } 

     for (int i = 0; i < n - 1; ++i) 
    { 
        for (int j = i + 1; j < n; ++j) 
        { 
            int number1 = arr[i];
            int number2 = arr[j];
            int temp;

            while (number1 >= 10) 
                number1 /= 10;
            
            while (number2 >= 10) 
                number2 /= 10;
    

            if (number1 > number2) 
            { 
                temp = arr[j]; 
                arr[j] = arr[i]; 
                arr[i] = temp; 
            } 
        } 
    } 
    
    for (int i = 0; i < n; ++i) 
            cout << arr[i] << " ";

    return 0;
}