#include <iostream>
#include <cmath>

using namespace std;

class Cube {
private:
    int side;

public:
    Cube(int s) : side(s) {}

    int surfaceArea() const {
        return 6 * side * side;
    }

    int volume() const {
        return side * side * side;
    }

    double diagonal() const {
        return side *  sqrt(3);
    }

    void setSide(int s) {
        side = s;
    }

    int getSide() const {
        return side;
    }
};

int main() {
    int sideLength;

    cout << "Enter the side length of the cube: ";
    cin >> sideLength;

    Cube myCube(sideLength);

    cout << "Surface Area: " << myCube.surfaceArea() <<  endl;
    cout << "Volume: " << myCube.volume() <<  endl;
    cout << "Diagonal: " << myCube.diagonal() <<  endl;

    int newSideLength;
    cout << "Enter the new side length of the cube: ";
    cin >> newSideLength;
    myCube.setSide(newSideLength);

    cout << "Updated Surface Area: " << myCube.surfaceArea() <<  endl;
    cout << "Updated Volume: " << myCube.volume() <<  endl;
    cout << "Updated Diagonal: " << myCube.diagonal() <<  endl;

    return 0;
}
