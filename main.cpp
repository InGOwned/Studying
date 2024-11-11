#include <iostream>
#include <climits> 
#include <iomanip>
#include <func.hpp>

using namespace std;

bool positiveAndContainsNumbersThree(int x);
bool allDiagonals(int A[100][100], int n, int m);

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

	if (allDiagonals(A, n, n)) 
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


bool positiveAndContainsNumbersThree(int x) 
{
	if (x > 0)
	{
		int tmp = x;

		while (tmp) 
		{
			if ((tmp % 10 == 3) || (tmp % 10 == 5)) 
			{
				return true;
			} else {
				tmp /= 10;
			}
		}
	}

	return false;
}


bool allDiagonals(int A[100][100], int n, int m) 
{
	int i = 0;
	int j = 0;

	while (i < n && j < n)
	{
		if (!positiveAndContainsNumbersThree(A[i][j])) 
		{
			return false;
		}
		i++;
		j++;
	}

	i = n - 1;

	while (i >= 0) 
	{
		for (j = 0; j < n; j++) 
		{
			if (!positiveAndContainsNumbersThree(A[i][j])) 
			{
				return false;
			}
			i--;
		}
		
	}

	return true;
}