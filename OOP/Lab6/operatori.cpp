#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    void display() const {
        cout << "(" << real << " + " << imag << "i)" << endl;
    }
};

int main() {

    Complex c1(2.0, 3.0);
    Complex c2(1.0, 4.0);

    Complex sum = c1 + c2;
    cout << "+: ";
    sum.display();

    Complex difference = c1 - c2;
    cout << "-: ";
    difference.display();

    Complex assigned;
    assigned = c1;
    cout << "=: ";
    assigned.display();

    return 0;
}
