#include "func.hpp"

namespace ns
{
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
 
    bool allDiagonals(int A[100][100], int& n, int& m)
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
}
