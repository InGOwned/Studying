#include <iostream>
#include <climits> 
#include <iomanip>
#include "func.hpp"

using namespace std;

int n;


int main()
{
    cout << "Enter the dimension of matrix, n: ";
    cin >> n;

    int A[100][100];

  
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

	if (ns::allDiagonals(A, n, n)) 
	{
		
		for (int j = 0; j < n; j++)
		{
			int min = INT_MAX;
			int index;
			int sum_squares = 0;

			for (int i = 0; i < n; i++)
			{
				if (A[i][j] < min)
				{
					min = A[i][j];
					index = i;
				}
				sum_squares += A[i][j] * A[i][j];
			}

			A[index][j] = sum_squares;
		}

		cout << "Modifed matrix: " << endl;
	
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << setw(6) << A[i][j];
			}
			cout << endl;
		}

	} else {
		cout << "Matrix hasn't changed: " << endl;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << setw(6) << A[i][j];
			}
			cout << endl;
		}
	}

	

	return 0;
}
