#include <iostream>

using namespace std; 
 
int main() { 
    short p; 
    cin >> p;

    short* ptr = &p; 
 
    unsigned char* x = reinterpret_cast<unsigned char*>(ptr); //  Первый байт переменной p
    
    cout << static_cast<short>(*x) << endl; // Разыменовываем

    cout << static_cast<short>(*(x+1)) << endl; // Смещаем на байт и разыменовываем второй байт

	// cout << static_cast<short>(*(ptr + 2)) << endl;
}
