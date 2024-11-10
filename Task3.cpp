#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;


int main()
{   
    cout << "TASK 3" << endl;

    int n, m;
    cout << "Enter the dimensions of matrix, n and m: ";
    cin >> n >> m;

    int A[100][100];

  
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int minElement = INT_MAX;
    int minColumn = -1;

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (A[i][j] < minElement) {
                minElement = A[i][j];
                minColumn = j;
            }
        }
    }

 
    for (int i = 0; i < n; ++i) {
        if (A[i][minColumn] < 0) {
            A[i][minColumn] = 0;
        }
    }

    cout << "Modified matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << A[i][j];
        }
        cout << endl;
    }

    return 0;
}

