#include <iostream>

using namespace std;

class stringB;

class stringA {
    string a = "ThisIsJustAString";

    public:

    string getString() const {
        return a;
    }

    void display() {
        cout << a << endl;
    }

    friend class stringB;
};

class stringB {
    string b;

    public:

    void operator = (const stringA& myStringA) {
        b = myStringA.getString();
    }

    void display() {
        cout << b << endl;
    }
};

int main() {
    stringA a;
    stringB b;

    b = a;

    a.display();

    b.display();

    return 0;
}