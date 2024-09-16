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
int a {109};
int b {17};
cout << a % b << endl;  // 7

unsigned int v {109};
unsigned int n {17};
cout << v + n << endl;  // 126

short c {-23};
short d {8};
cout << c * d << endl;  // -184

long e {21474};
long f {33333};
cout << e - f << endl;  // -11859

float g {3.121};
float j {1.66};
cout << g - j << endl;  // 1.461

char x {'M'};
char y {'F'};
cout << x + y << endl;  // 147

bool l {true};
bool k {false};

cout << l - k << endl;  // 147
}


