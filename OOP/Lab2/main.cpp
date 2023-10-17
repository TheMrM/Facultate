#include <iostream>
#include <string>

using namespace std;

class Masina {
public:
    int seriaSasiu;
    string brand;
    string model; // Change the data type to string.
};

int main() {
    Masina masinaMea;

    cout << "Introdu brand-ul masinii: ";
    cin >> masinaMea.brand;

    cout << "Introdu seria sasiu: ";
    cin >> masinaMea.seriaSasiu;

    cout << "Introdu modelul masinii: ";
    cin.ignore(); // Add this line to clear the newline character from the input buffer.
    getline(cin, masinaMea.model); // Use getline to read the full line for the model.

    cout << "Brand-ul masinii este: " << masinaMea.brand << endl;
    cout << "Seria sasiu este: " << masinaMea.seriaSasiu << endl;
    cout << "Modelul masinii este: " << masinaMea.model << endl;

    return 0;
}
