#include <iostream>

using namespace std; 
 
int main() { 
    short p; 
    cin >> p;
    short * ptr = &p; 
 
    unsigned char* x = reinterpret_cast<unsigned char*>(ptr); 
    
    cout << static_cast<short>(*x) << endl;
    cout << static_cast<short>(*(x+1)) << endl;
}
 