#include <iostream>
using namespace std;

class Complex {
    float re, im;

public:
    void setRe(float);
    float getRe();
    void setIm(float);
    float getIm();
    void print();

    Complex();
    Complex(float c1, float c2);
    ~Complex() {}
};

int main() {
    Complex c1, c2, result; // Create Complex objects
    int choice;

    while (true) {
        cout << "Complex Number Calculator Menu:" << endl;
        cout << "1. Enter two complex numbers" << endl;
        cout << "2. Add two complex numbers" << endl;
        cout << "3. Subtract two complex numbers" << endl;
        cout << "4. Multiply two complex numbers" << endl;
        cout << "5. Print a complex number" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the real and imaginary parts of the first complex number: ";
                float re1, im1;
                cin >> re1 >> im1;
                c1.setRe(re1);
                c1.setIm(im1);

                cout << "Enter the real and imaginary parts of the second complex number: ";
                float re2, im2;
                cin >> re2 >> im2;
                c2.setRe(re2);
                c2.setIm(im2);
                break;

            case 2:
                // Perform addition and store the result in 'result'
                result.setRe(c1.getRe() + c2.getRe());
                result.setIm(c1.setIm() + c2.setIm());
                result.print();
                break;

            // Implement other cases for subtraction, multiplication, and printing

            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
