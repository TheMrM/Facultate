#include <iostream>

using namespace std;

class Complex {
    float re, im; // Real and imaginary parts of the complex number

public:
    void setRe(float); // Set the real part
    float getRe();    // Get the real part
    void setIm(float); // Set the imaginary part
    float setIm();     // Get the imaginary part
    void tiparire();   // Print the complex number

    Complex();                     // Default constructor
    Complex(float a, float b);     // Parameterized constructor
    Complex(const Complex& source); // Copy constructor
    ~Complex() {
        cout << "\nS-a apelat destructorul si a sters obiectul de la adresa " << this;
    }
};

void Complex::tiparire() {
    cout << "\n" << re << "," << im; // Print the complex number
}

void Complex::setRe(float a) {
    this->re = a; // Set the real part to the provided value
}

float Complex::getRe() {
    return this->re; // Get the real part
}

void Complex::setIm(float b) {
    this->im = b; // Set the imaginary part to the provided value
}

float Complex::setIm() {
    return this->im; // Get the imaginary part
}

Complex::Complex() {
    cout << "\nSa initializat constructorul fara parametrii si sa creat obiectul la adresa " << this << endl;
    // Default constructor initializes and prints a message
}

Complex::Complex(float a, float b) {
    re = a;
    im = b;
    cout << "\nSa apelat constructorul folosinduse parametrii a si b, creat obectul la adresa " << this << endl;
    // Parameterized constructor with values 'a' and 'b' and prints a message
}

Complex::Complex(const Complex& source) {
    re = source.re;
    im = source.im;
    cout << "\nSa apelat constructorul de Copiere si s-a creat o clona a sursei la adresa " << this << endl;
    // Copy constructor creates a clone of the source object and prints a message
}

int main() {
    Complex z; // Create a Complex object using the default constructor
    Complex z1(5, 8); // Create a Complex object using the parameterized constructor
    Complex ob_dest(z1); // Create a copy of 'z1' using the copy constructor
    Complex ob_dest_2 = z1; // Create another copy of 'z1' using the copy constructor
}
