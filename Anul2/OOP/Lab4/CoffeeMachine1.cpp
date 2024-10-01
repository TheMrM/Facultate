#include <iostream>
using namespace std;

class CoffeeItem {
    string name;
    string size;
    double price;

public:
    CoffeeItem(string n, string s, double p) : name(n), size(s), price(p) {}

    void displayProdus() {
        cout << "Nume cafea: " << name << endl;
        cout << "Dimensiune cafea: " << size << endl;
        cout << "Pret: " << price << " lei" << endl;
    }

    double getPrice() {
        return price;
    }

    string getCoffeeSize() {
        return size;
    }
};

class Customer {
    string name;
    int loyaltyPoints;
    double totalAmountSpent;
    CoffeeItem coffeeItem;

public:
    Customer(string n, int lp, double tas, CoffeeItem ci) : name(n), loyaltyPoints(lp), totalAmountSpent(tas), coffeeItem(ci) {}

    void displayCustomer() {
        cout << "Nume client: " << name << endl;
        cout << "Puncte loialitate: " << loyaltyPoints << endl;
        cout << "Suma totala cheltuita: " << totalAmountSpent << " lei" << endl;
        cout << "Detalii despre comanda clientului..." << endl;
        coffeeItem.displayProdus();
    }

    void recordOrder() {
        totalAmountSpent += coffeeItem.getPrice();
    }

    string getName() {
        return name;
    }

    void placeOrder(int coffeeChoice) {
        displayCustomer();
        cout << name << " plaseaza o comanda..." << endl;

        double coffeePrice = 0.0;
        string coffeeSize;

        if (coffeeChoice == 1) {
            coffeePrice = coffeeItem.getPrice();
            coffeeSize = coffeeItem.getCoffeeSize();
        } else if (coffeeChoice == 2) {
            coffeePrice = coffeeItem.getPrice() * 2;
            coffeeSize = coffeeItem.getCoffeeSize() + " dublu";
        } else if (coffeeChoice == 3) {
            coffeePrice = coffeeItem.getPrice() * 3;
            coffeeSize = coffeeItem.getCoffeeSize() + " triplu";
        }

        if (coffeePrice > totalAmountSpent) {
            cout << "Nu aveti suficienti bani pentru aceasta comanda." << endl;
        }

        totalAmountSpent += coffeePrice;
        loyaltyPoints += static_cast<int>(totalAmountSpent / 10);

        cout << "Ati ales cafeaua cu numarul " << coffeeChoice << ". " << coffeeSize << ". Costul este de " << coffeePrice << " lei." << endl;
        cout << "Puncte de loialitate adaugate: " << static_cast<int>(coffeePrice / 10) << endl;
    }
};

int main () {
    CoffeeItem coffee1("Iacobs", "Mica", 1.5);
    CoffeeItem coffee2("Iacobs", "Medie", 2.25);
    CoffeeItem coffee3("Iacobs", "Mare", 3.2);

    Customer customer1("Mihai", 5, 4.5, coffee1);
    Customer customer2("Dan", 7, 9.2, coffee2);

    int coffeeChoice;

    cout << "\nInregistreaza comanda pentru clientul 1...\n";
    customer1.displayCustomer();
    customer1.recordOrder();
    cout << customer1.getName() << " plaseaza o comanda...\n";
    while (true) {
        cout << "Ce tip de cafea doriti "<< "\n1 - " << coffee1.getCoffeeSize() << "\n2 - " <<  coffee2.getCoffeeSize() << "\n3 - " << coffee3.getCoffeeSize() << "\n0 - Iesire" << endl;
        cin >> coffeeChoice;
            if (coffeeChoice == 0) {
                break;
            }
        customer1.placeOrder(coffeeChoice);
        customer1.displayCustomer();
    }
    
    cout << "\nInregistreaza comanda pentru clientul 2...\n";
    customer2.displayCustomer();
    customer2.recordOrder();
    cout << customer2.getName() << " plaseaza o comanda...\n"; 
    while (true) {
        cout << "Ce tip de cafea doriti "<< "\n1 - " << coffee1.getCoffeeSize() << "\n2 - " <<  coffee2.getCoffeeSize() << "\n3 - " << coffee3.getCoffeeSize() << "\n0 - Iesire" << endl;
        cin >> coffeeChoice;
            if (coffeeChoice == 0) {
                break;
            }
        customer2.placeOrder(coffeeChoice);
        customer2.displayCustomer();
    }

    return 0;
}
