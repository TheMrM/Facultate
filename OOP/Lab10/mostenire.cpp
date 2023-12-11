#include <iostream>

using namespace std;

class Zburatoare {
    public:
    string zboara() {
        return "Zboara!";
    }
};

class Inotatoare {
    public:
    string inoata() {
        return "Innoata!";
    }
};

class Rata : public Zburatoare, public Inotatoare {

};


int main() {

    Rata ratuscaMea;
    cout << ratuscaMea.inoata() << endl;
    cout << ratuscaMea.zboara() << endl;
}