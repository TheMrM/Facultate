#include <iostream>
using namespace std;

// Define a struct to store car information
struct Masina {
    string brand;
    string culoare;
    string seriaSasiu;
    string model;
    int roti;
    int viteza;

    void setViteza(int km);
    int getViteza();
};

void Masina::setViteza(int km) {
    viteza = km;
}

int Masina::getViteza() {
    return viteza;
}

int main() {
    Masina masinaMea;

    cout << "Introdu brand-ul masinii: ";
    cin >> masinaMea.brand;

    cout << "Introdu culoarea masinii: ";
    cin >> masinaMea.culoare;

    cout << "Introdu seria sasiu: ";
    cin >> masinaMea.seriaSasiu;

    cout << "Introdu modelul masinii: ";
    cin.ignore(); // Add this line to clear the newline character from the input buffer.
    getline(cin, masinaMea.model); // Use getline to read the full line for the model.

    cout << "Introdu nr. roti: ";
    cin >> masinaMea.roti;

    cout << "Introdu viteza (km/h): ";
    int speed;
    cin >> speed;
    masinaMea.setViteza(speed);

    // Output the car information
    cout << "Modelul masinii este: " << masinaMea.model << endl;
    cout << "Brand-ul masinii este: " << masinaMea.brand << endl;
    cout << "Seria sasiu este: " << masinaMea.seriaSasiu << endl;
    cout << "Culoarea masinii este: " << masinaMea.culoare << endl;
    cout << "Masina are " << masinaMea.roti << " roti" << endl;
    cout << "Viteza curenta " << masinaMea.getViteza() << " km/h" << endl;

    return 0;
}
