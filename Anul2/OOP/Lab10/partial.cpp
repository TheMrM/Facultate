#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class lukeyCard {
private:
    int A;
    string lukey;
    float lkN;
    const int constIntValue;
    static int staticIntValue;

public:
    lukeyCard() : constIntValue(0) {}
    lukeyCard(int K, string king, float lkKing, const int c) : A(K), lukey(king), lkN(lkKing), constIntValue(c) {}

    static float getCardNumber() {
        return staticIntValue;
    }

    friend ostream &operator<<(ostream &, const lukeyCard&);

    void setobiect(int a, string l, float abc) {
        this -> A = a;
        this -> lukey = l;
        this -> lkN = abc;
    }
};



ostream &operator<<(ostream &out, const lukeyCard&K){
    out << K.A << " " << K.lukey << " " << K.lkN << " " << K.constIntValue << endl;
    return out;
}

int lukeyCard::staticIntValue = 0;

int main() {
    lukeyCard kingCard;
    lukeyCard queenCard(13, "Queen", 3, 13);
    lukeyCard aceCard(11, "Ace", 1, 11);

    cout << "Valoarea statica a cartilor " << lukeyCard::getCardNumber() << endl;
    ifstream fin("../file.in");

    if (!fin) {
        cerr << "Error opening the file." << endl;
        return 1;  // Exit with an error code
    }

    int a;
    float b;
    string c;
    fin >> a >> c >> b;
    kingCard.setobiect(a, c, b);
    cout << kingCard;
    fin.close();
    return 0;
}