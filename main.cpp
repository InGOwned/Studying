#include <iostream> 

using namespace std; 
  
int main() 
{ 
	cout << "Task 1" << endl;
	int j; 
    int num; 
	int size;
    cout << "\nEnter the length of sequence: "; 
    cin >> size;
    int product = 1; 
    int num_min = 0; 
    int size_min = INT_MAX; 
  
    for (j = 1; j <= size; j++) 
    { 
        cout << "\nEnter a number \n"; 
        cin >> num; 
  
        if ((num >= -2) && (num <= 20)) 
        { 
            product *= num; 
  
            if (num < size_min) 
            { 
                size_min = num; 
                num_min = j; 
            } 
        } 
    } 
    cout << "Product: " << product << ", Min number: " << size_min << ", Position: " << num_min << endl; 
    cout << "\nTask 2" << endl;
    int N; 
    int SUM = 0; 
  
    cout << "Enter n = "; 
    cin >> N; 
  
    while (N != 0) 
    { 
        int digit = N % 10; 
        if (digit % 2 == 0) 
        { 
            SUM += digit; 
        }
        N /= 10; 
    } 
    cout << "Sum of even digits = " << SUM << endl; 
     
    return 0; 
}