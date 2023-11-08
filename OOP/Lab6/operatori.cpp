#include <iostream>

using namespace std;

class Complex {
private:
    float Re;
    float Im;

public:
    Complex(float real = 0.0, float imaginary = 0.0) : Re(real), Im(imaginary) {}

    // Addition operator overloading
    Complex operator + (const Complex& other) {
        Complex result;
        result.Re = Re + other.Re;
        result.Im = Im + other.Im;
        return result;
    }

    // Subtraction operator overloading
    Complex operator - (const Complex& other) {
        Complex result;
        result.Re = Re - other.Re;
        result.Im = Im - other.Im;
        return result;
    }

    // Multiplication operator overloading
    Complex operator * (const Complex& other) {
        Complex result;
        result.Re = Re * other.Re - Im * other.Im;
        result.Im = Re * other.Im + Im * other.Re;
        return result;
    }

    // Division operator overloading
    Complex operator / (const Complex& other) {
        Complex result;
        float denominator = other.Re * other.Re + other.Im * other.Im;
        result.Re = (Re * other.Re + Im * other.Im) / denominator;
        result.Im = (Im * other.Re - Re * other.Im) / denominator;
        return result;
    }

    void display() {
        cout << Re << " + " << Im << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3, c4, c5, c6;

    cout << "c1: ";
    c1.display();

    cout << "c2: ";
    c2.display();

    c3 = c1 + c2;
    cout << "Addition Result: ";
    c3.display();

    c4 = c1 - c2;
    cout << "Subtraction Result: ";
    c4.display();

    c5 = c1 * c2;
    cout << "Multiplication Result: ";
    c5.display();

    c6 = c1 / c2;
    cout << "Division Result: ";
    c6.display();

    return 0;
}
