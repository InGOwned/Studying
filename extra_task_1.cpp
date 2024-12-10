#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float q1, p1, q2, p2;
    int a, cost = 0;

    cin >> q1 >> p1;
    cin >> q2 >> p2;
    cin >> a;

    bool useFirst = (q1 / p1) > (q2 / p2);

    if (useFirst)
    {
        while (a > q1)
        {
            a -= q1;
            cost += p1;
        }
        cost += (p1 < (ceil(a / q2) * p2)) ? p1 : ceil(a / q2) * p2;
    }
    else
    {
        while (a > q2)
        {
            a -= q2;
            cost += p2;
        }
        cost += (p2 < (ceil(a / q1) * p1)) ? p2 : ceil(a / q1) * p1;
    }

    cout << cost;
}
