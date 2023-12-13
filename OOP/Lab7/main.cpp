#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std;

void printWithDelay(const string& message, int dealyMilliseconds);

class Caracter {
    private:
        string name;
        int HP, AP, DEF;
    public:
        Caracter(string name,int HP,int AP, int DEF){
            this->name = name;
            this->HP = HP;
            this->AP = AP;
            this->DEF = DEF;
        }
    void printHero() {
        ostringstream message;
        message << "Eroul nostru " << name << " isi incepe aventura, plin de viata LIFE:" << HP << " cu o putere nemaivazuta pana acuma AttackPower:" << AP;
        printWithDelay(message.str(), 40);
    }

    string getName() const {
        return name;
    }

    void setHp(int newHP) {
        HP = newHP;
    }

    int getHP() const {
        return HP;
    }

    int getAP() const {
        return AP;
    }

    int getDEF() const {
        return DEF;
    }

    void printStats() {
        ostringstream stats;
        stats << name << " - Health: " << HP << ", Attack Power: " << AP << ", Defense: " << DEF;
        printWithDelay(stats.str(), 40);
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
        ostringstream message;
        message << "Arma: " << itemName << ", daune: " << itemAP;
        printWithDelay(message.str(), 40);
    }

    string getItemName() const {
        return itemName;
    }

    int getItemAP() const {
        return itemAP;
    }
};

class Game {
    private:
        string enemyType;
        int enemyHP;
        int enemyAP;
        int enemyDEF;
    public:
        Game(string enemyType, int enemyHP, int enemyAP, int enemyDEF) {
            this->enemyType = enemyType;
            this->enemyHP = enemyHP;
            this->enemyAP = enemyAP;
            this->enemyDEF = enemyDEF;
        }

        string getEnemyType() const {
            return enemyType;
        }

        int getEnemyHP() {
            return enemyHP;
        }

        int getEnemyAP() {
            return enemyAP;
        }

        int getEnemyDef() {
            return enemyDEF;
        }

        void setEnemyHP(int newHP) {
            enemyHP = newHP;
        }
        void printStats() {
            ostringstream stats;
            stats << enemyType << " - Health: " << enemyHP << ", Attack Power: " << enemyAP << ", Defense: " << enemyDEF;
            printWithDelay(stats.str(), 40);
        }
};


void printWithDelay(const string& message, int dealyMilliseconds) {
    for (char ch : message) {
        cout << ch << flush;
        this_thread::sleep_for(chrono::milliseconds(dealyMilliseconds));
    }
    cout << endl;
}

void printAdventureStart(const Caracter& hero, const Item& item1, const Item& item2) {
    ostringstream messageStream;
    messageStream << "Aventurierul nostru " << hero.getName() << " porneste in aventura echipat cu " << item1.getItemName() << " si " << item2.getItemName() << " capabile sa il ajute sa rapuna orice provocare a fortelor malefice va intalni";
    printWithDelay(messageStream.str(), 40);
}

void printPrimaLupta(const Caracter& hero, const Game& orc) {
    ostringstream messageStream;
    messageStream << hero.getName() << " a pornit la drum dar nu a mers prea departe pe drumuri laturalnice primejdia il paste\n" << "In calea lui un " << orc.getEnemyType() << " se arata, iar batalia incepe";
    printWithDelay(messageStream.str(), 40);
}

void luptaCuOrc(Caracter& hero, const Item& item1, Game& orc) {
    while (hero.getHP() > 0 && orc.getEnemyHP() > 0) {
        
        int heroRandomFactor = rand() % 5;
        int totalAttackPower = hero.getAP() + item1.getItemAP() + heroRandomFactor;

        int damageToOrc = max(0, totalAttackPower - orc.getEnemyDef());
        orc.setEnemyHP(orc.getEnemyHP() - damageToOrc);
        cout << hero.getName() << " ataca cu " << item1.getItemName() << ", a dat dauna " << damageToOrc << " puncte la orc!" << endl;
        orc.printStats();

        if (orc.getEnemyHP() <= 0) {
            cout << "Orcul a fost invins!" << endl;
            break;
        }

        int orcRandomFactor = rand() % 5;
        int totalOrcAttackPower = orc.getEnemyAP() + orcRandomFactor;
        int damageToHero = max(0, totalOrcAttackPower - hero.getDEF());
        hero.setHp(hero.getHP() - damageToHero);
        cout << "Orcul ataca miseleste, a dat " << damageToHero << " daune eroului " << hero.getName() << "!" << endl;
        hero.printStats();

        if (hero.getHP() <= 0) {
            cout << hero.getName() << " a fost invins de catre orc!" << endl;
            break;
        }
    }
}

void luptaCuStrigoi(Caracter& hero, const Item& item2, Game& strigoi) {
    while (hero.getHP() > 0 && strigoi.getEnemyHP() > 0) {
        
        int heroRandomFactor = rand() % 5;
        int totalAttackPower = hero.getAP() + item2.getItemAP() + heroRandomFactor;

        int damageToStrigoi = max(0, totalAttackPower - strigoi.getEnemyDef());
        strigoi.setEnemyHP(strigoi.getEnemyHP() - damageToStrigoi);
        cout << hero.getName() << " ataca cu " << item2.getItemName() << ", a dat dauna " << damageToStrigoi << " puncte la strigoi!" << endl;
        strigoi.printStats();

        if (strigoi.getEnemyHP() <= 0) {
            cout << "Strigoiul a fost invins!" << endl;
            break;
        }

        int strigoiRandomFactor = rand() % 5;
        int totalStrigoiAttackPower = strigoi.getEnemyAP() + strigoiRandomFactor;
        int damageToHero = max(0, totalStrigoiAttackPower - hero.getDEF());
        hero.setHp(hero.getHP() - damageToHero);
        cout << "Strigoiul ataca cu putere, a dat " << damageToHero << " daune eroului " << hero.getName() << "!" << endl;
        hero.printStats();

        if (hero.getHP() <= 0) {
            cout << hero.getName() << " a fost invins de catre strigoi!" << endl;
            break;
        }
    }
}


int main() {
    srand(static_cast<unsigned int>(time(0)));

    Caracter hero("Harap Alb", 100, 5, 10);
    Item item1("Sabia Luminii", 4);
    Item item2("Arcul suierator", 2);

    Game orc("Orc", 20, 30, 1);
    Game strigoi("Strigoi", 5, 5, 5);

    hero.printHero();
    item1.printItem();
    item2.printItem();
    printAdventureStart(hero, item1, item2);
    printPrimaLupta(hero, orc);
    luptaCuOrc(hero, item1, orc);
    printPrimaLupta(hero, strigoi);
    luptaCuStrigoi(hero, item2, strigoi);

    return 0;
}