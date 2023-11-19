#include <iostream>

using namespace std;

class Complex {
    float Re, Im;
public:
    Complex(float Vr = 0, float Vi = 0) : Re(Vr), Im(Vi) {}

    Complex operator+(const Complex& z) const {
        return Complex(Re + z.Re, Im + z.Im);
    }

    Complex operator-(const Complex& z) const {
        return Complex(Re - z.Re, Im - z.Im);
    }

    Complex& operator=(const Complex& z) {
        if (this == &z) {
            return *this;
        }
        Re = z.Re;
        Im = z.Im;
        return *this;
    }

    void display() const {
        cout << "(" << Re << " + " << Im << "i)" << endl;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(3, 4);
    Complex c3;

    c3 = c1 + c2;
    c3.display();

    c3 = c1 - c2;
    c3.display();

    Complex c4 = c3;
    c4.display();

    return 0;
}