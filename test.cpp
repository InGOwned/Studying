// Лабораторная работа №3
#include <cmath>  
#include <iostream>  
#include <iomanip>  
 
using namespace std; 
  
int main(void) 
{ 
    int m, n, mxl;
  long max_number;
  cout << "Введите размеры матрицы (m, n): ";
  cin >> m >> n;

  int* A = new int[m];
  int* B = new int[m];
  int* C = new int[n];
  mxl = 1;

  for (int i = 0; i < m; i++)
  {
    B[i] = 1;
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> A[j][i];
      B[i] *= A[j][i];
    }
    if (i > 0 && B[i] > B[i-1])
    {
      mxl = i;
      max_number = B[i];
    }
  }
  for (int i = 0; i < m; i++)
  {
    A[i][mxl] = max_number;
  }
  for (int i = 0; i < m; i++)
  {
    cout <<"\n";
    for (int j = 0; j < n; i++)
    {
      cout << A[j][i] << "  ";
    }
  }
}
