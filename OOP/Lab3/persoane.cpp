#include <iostream>
#include <string>
using namespace std;

class Persoane {
private:
    std::string Nume;
    int cnp;

public:
    Persoane() : Nume(""), cnp(0) {} // Default constructor

    Persoane(const std::string& fNume, int persoanaCNP) : Nume(fNume), cnp(persoanaCNP) {}

    // Getter methods for accessing the attributes
    std::string getName() const {
        return Nume;
    }

    int getcnp() const {
        return cnp;
    }

    // Setter methods for modifying the attributes
    void setName(const std::string& fNume) {
        Nume = fNume;
    }

    void setcnp(int persoanaCNP) {
        cnp = persoanaCNP;
    }
};

int main() {
    Persoane person;

    cout << "Enter the name: ";
    string name;
    getline(cin, name); // Allowing for spaces in the name
    person.setName(name);

    cout << "Enter the CNP: ";
    int cnp;
    cin >> cnp;
    person.setcnp(cnp);

    cout << "Name: " << person.getName() << endl;
    cout << "CNP: " << person.getcnp() << endl;

    return 0;
}