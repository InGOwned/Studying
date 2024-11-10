#include <iostream>

using namespace std;

int main()
{
	int n, m;
    cout << "Enter the dimension of matrix, n: ";
    cin >> n;

    int A[100][100];

  
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
	return 0;
}
