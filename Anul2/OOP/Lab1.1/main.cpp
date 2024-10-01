#include <iostream>
#include <cmath>

class Complex {
    double re, im;

public:
    Complex(double re = 0, double im = 0) : re(re), im(im) {}

    void setRe(double re) {
        this->re = re;
    }

    void setIm(double im) {
        this->im = im;
    }

    void InitializareComplex(double re, double im) {
        setRe(re);
        setIm(im);
    }

    void AfisareComplex() {
        std::cout << re << " + " << im << "i" << std::endl;
    }

    double ModulComplex() {
        return std::sqrt(re*re + im*im);
    }
};

int main() {
    Complex c1;
    c1.InitializareComplex(3, 4);
    c1.AfisareComplex();
    std::cout << c1.ModulComplex() << std::endl;

    Complex c2;
    c2.InitializareComplex(5, 12);
    c2.AfisareComplex();
    std::cout << c2.ModulComplex() << std::endl;

    return 0;
}
