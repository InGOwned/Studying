#include <iostream>

using namespace std;

int main() {
cout << "Data Type  : int\n"
    << "Size       : 4 bytes\n"
    << "Range      : -2147483648 ; 2147483647\n"
	<< "----------------------------\n";

cout << "Data Type  : short\n"
    << "Size       : 2 bytes\n"
    << "Range      : -32768 ; 32767\n"
	<< "----------------------------\n";

cout << "Data Type  : long\n"
    << "Size       : 4/8 bytes\n"
    << "Range      : -2147483648 ; 2147483647\n"
	<< "----------------------------\n";

cout << "Data Type  : long long\n"
    << "Size       : 8 bytes\n"
    << "Range      : -9223372036854775808 ; 9223372036854775807\n"
	<< "----------------------------\n";

cout << "Data Type  : float\n"
    << "Size       : 4 bytes\n"
    << "Range      : 1.17549e-38 ; 3.40282e+38\n"
	<< "----------------------------\n";

cout << "OPERATIONS" << endl;
#include <iostream>

using namespace std;

int a {120}; 
int b {23};
cout << "a = " << a << ", b = " << b << ", a % b = " << a % b << endl;  // 12

unsigned int v {150};
unsigned int n {75};
cout << "v = " << v << ", n = " << n << ", v + n = " << v + n << endl;  // 225

short c {7};
short d {-5};
cout << "c = " << c << ", d = " << d << ", c * d = " << c * d << endl;  // -35

long e {80000};
long f {35000};
cout << "e = " << e << ", f = " << f << ", e - f = " << e - f << endl;  // 45000

float g {9.85};
float j {4.67};
cout << "g = " << g << ", j = " << j << ", g / j = " << g / j << endl;  // 2.109

char x {'Z'};
char y {'X'};
cout << "x = "<< x << ", y = " << y << ", x - y = " << x - y << endl;  // 2

bool l {true};
bool k {false};
cout << "l = " << l << ", k = " << k << ", l && k = " << (l && k) << endl;  // 0

double m {5.432};
double q {2.876};
cout << "m = " << m << ", q = " << q << ", m * q = " << m * q << endl;  // 15.679

unsigned long r {200000};
unsigned long s {80000};
cout << "r = " << r << ", s = " << s << ", r / s = " << r / s << endl;  // 2
}
