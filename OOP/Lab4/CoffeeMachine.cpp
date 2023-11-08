#include <iostream>
#include <string>

using namespace std;

class CoffeeItem {
public:
    CoffeeItem(string name, string size, double price) : name(name), size(size), price(price) {}

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    string getSize() {
        return size;
    }

private:
    string name;
    string size;
    double price;
};

class Customer {
private:
    string name;
    int loyaltyPoints;
    double totalAmountSpent;
    CoffeeItem coffeeItem;

public:
    Customer(string name, int loyaltyPoints) : name(name), loyaltyPoints(loyaltyPoints), totalAmountSpent(0.0), coffeeItem("Unkown", "Unknown", 0.0) {}

    string getName() {
        return name;
    }

    int getLoyaltyPoints() {
        return loyaltyPoints;
    }

    double getTotalAmountSpent() {
        return totalAmountSpent;
    }

    string getCoffeeItemName() {
        return coffeeItem.getName();
    }

    friend void placeOrder(Customer& customer, CoffeeItem& coffee);
};

void placeOrder(Customer& customer, CoffeeItem& coffee) {
    customer.coffeeItem = coffee;
    customer.totalAmountSpent += coffee.getPrice();

    if (coffee.getSize() == "S") {
        customer.loyaltyPoints += 1;
    } else if (coffee.getSize() == "M") {
        customer.loyaltyPoints += 2;
    } else if (coffee.getSize() == "L") {
        customer.loyaltyPoints +=3;
    }
}

void LoyalityPointsChecker(Customer& customer, CoffeeItem& coffee) {
    int loyalityPoints = customer.getLoyaltyPoints();
    double price = coffee.getPrice();

    if (loyalityPoints <= 5) {
        price -= price * 2.5;
    } else if (loyalityPoints <= 8) {
        price -= price * 5;
    } else if (loyalityPoints <= 10) {
        price -= price * 7.5;
    }

    coffee.setPrice(price);
}

int main() {
    string name;
    
    cout << "Introdu nume: ";
    cin >> name;
    cin.ignore();

    Customer customer(name, 0);

    int coffeeChoice, anotherOne;
    bool wantAnotherCoffee = true;

    while (wantAnotherCoffee) {
        cout << "Selecteaza cafeaua:\n";
        cout << "1. Cappuccino (S) - 4.99 RON\n";
        cout << "2. Cappuccino (M) - 2.99 RON\n";
        cout << "3. Cappuccino (L) - 2.99 RON\n";
        cout << "4. Espresso (S) - 2.99 RON\n";
        cout << "5. Espresso (M) - 2.99 RON\n";
        cout << "6. Espresso (L) - 2.99 RON\n";
        cout << "0. Exit\n";
        cout << "Introdu optiune: ";
        cin >> coffeeChoice;

        if (coffeeChoice == 0) {
            break;
        }

        if (coffeeChoice >= 1 && coffeeChoice <= 6) {
            CoffeeItem coffeeOptions[] = {
                CoffeeItem("Cappuccino (S)", "S", 4.99),
                CoffeeItem("Cappuccino (M)", "M", 2.99),
                CoffeeItem("Cappuccino (L)", "L", 2.99),
                CoffeeItem("Espresso (S)", "S", 2.99),
                CoffeeItem("Espresso (M)", "M", 2.99),
                CoffeeItem("Espresso (L)", "L", 2.99)
            };
        placeOrder(customer, coffeeOptions[coffeeChoice - 1]);

        cout << "Numele clientului: " << customer.getName() << endl;
        cout << "Puncte de loialitate totale: " << customer.getLoyaltyPoints() << endl;
        cout << "Suma totala cheltuita: " << customer.getTotalAmountSpent() << " RON" << endl;
        cout << "Comanda de cafea: " << customer.getCoffeeItemName() << endl;

        cout <<"Mai vrei o cafea? (1 - Da | 2 - Nu)";
        cin >> anotherOne;
        if (anotherOne == 2) {
            wantAnotherCoffee = false;
        }
    } else if (coffeeChoice != 0) {
        cout << "Optiunea de cafea aleasa nu este valida." << endl;
    }
 }

 return 0;
}