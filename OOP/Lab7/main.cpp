#include <iostream>
#include <string>

using namespace std;

class Caracter {
    private:
        string name;
        int HP, AP;
    public:
        Caracter(string name,int HP,int AP){
            this->name = name;
            this->HP = HP;
            this->AP = AP;
        }
    void printHero() {
        cout << "Eroul nostru " << name << " isi incepe aventura, plin de viata LIFE:" << HP << " cu o putere nemaivazuta pana acuma AttackPower:" << AP << endl;
    }

    string getName() const {
        return name;
    }
};

class Item {
    private:
        string itemName;
        int itemAP;
    public:
        Item(string itemName, int itemAP){
            this->itemName = itemName;
            this->itemAP = itemAP;
        }
    void printItem() {
        cout << "Arma: " << itemName << ", daune: " << itemAP << endl;
    }

    string getItemName() const {
        return itemName;
    }
};

void printAdventureStart(const Caracter& hero, const Item& item1, const Item& item2) {
    cout << "Aventurierul nostru " << hero.getName() << " porneste in aventura echipat cu " << item1.getItemName() << " si " << item2.getItemName() << " capabile sa il ajute sa rapuna orice provocare a fortelor malefice va intalni" << endl;
}

int main() {
    Caracter hero("Harap Alb", 100, 5);
    Item item1("Sabia Luminii", 4);
    Item item2("Arcul suierator", 2);

    hero.printHero();
    item1.printItem();
    item2.printItem();
    printAdventureStart(hero, item1, item2);

    return 0;
}