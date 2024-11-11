#include <iostream> 
  
using namespace std; 
  
int main() 
{ 
    setlocale(LC_ALL, "rus"); 
    
    cout << "TASK 1" << endl;

    const int n = 5; 
    int arr[n] {}; 
 
    for (int i = 0; i < n; i++) { 
        cout << "Enter a number: ";
        cin >> arr[i];
    } 

    bool flag = false; 

    for (int i = 0; i < n; ++i) 
    { 
        int sum = 0;
        int num = arr[i];
        int last_digit;
        while (num) 
        {
            last_digit = num % 10;
            sum += last_digit;
            num /= 10;
        }
        if (sum == 14) 
        {
            flag = true;
            break;
        } else {
            sum = 0;
        }
    }

    cout << "\n"; 

    int temp;

    if (flag) { 
        for (int i = 0; i < n - 1; ++i) 
    { 
        for (int j = i + 1; j < n; ++j) 
        { 
            if (arr[i] > arr[j]) 
            { 
                temp = arr[j]; 
                arr[j] = arr[i]; 
                arr[i] = temp; 
            } 
        } 
    } 
    } 
         
    else 
    { 
        cout << "We does not have the number with sum of digits equal 14" << endl;     
    } 
    for (int i = 0; i < n; ++i) 
            cout << arr[i] << " ";
    return 0;
}
