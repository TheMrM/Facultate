#include <iostream>

using namespace std;

class Animal {
    protected:
    string nume;

    public:
    Animal(const string& n) : nume(n) {}
    virtual void faSunet() {
        cout << "Sunet de animal" << endl;
    }
};

class Rata : public Animal {
    public:
    Rata(const string& n) : Animal(n) {}
    void faSunet() override {
        cout << "Mac mac mac" << endl;
    }

    void prinNume() {
        cout << nume << endl;
    }
};

int main() {
    Rata myRata("Daffy");
    myRata.prinNume();
    myRata.faSunet();

    return 0;
}
