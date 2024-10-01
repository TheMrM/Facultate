#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class CoffeeItem {
public:
    CoffeeItem(string name, string size, double price) : name(name), size(size), price(price) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    string getSize() const { return size; }
    void setPrice(double newPrice) { price = newPrice; } 

private:
    string name, size;
    double price;
};

class Customer {
public:
    Customer(string name, int loyaltyPoints) : name(name), loyaltyPoints(loyaltyPoints), totalAmountSpent(0.0), coffeeItem("Unknown", "Unknown", 0.0) {}

    string getName() const { return name; }
    int getLoyaltyPoints() const { return loyaltyPoints; }
    double getTotalAmountSpent() const { return totalAmountSpent; }
    string getCoffeeItemName() const { return coffeeItem.getName(); }

    void addLoyaltyPoints(int points) { loyaltyPoints += points; }
    void addToTotalAmountSpent(double amount) { totalAmountSpent += amount; }
    friend void placeOrder(Customer& customer, CoffeeItem& coffee);
    friend void LoyaltyPointsChecker(Customer& customer, CoffeeItem& coffee); 
private:
    string name;
    int loyaltyPoints;
    double totalAmountSpent;
    CoffeeItem coffeeItem;
};

void placeOrder(Customer& customer, CoffeeItem& coffee) {
    customer.coffeeItem = coffee;
    customer.addToTotalAmountSpent(coffee.getPrice());

    int loyaltyPointsToAdd = 0;
    if (coffee.getSize() == "S") {
        loyaltyPointsToAdd = 1;
    } else if (coffee.getSize() == "M") {
        loyaltyPointsToAdd = 2;
    } else if (coffee.getSize() == "L") {
        loyaltyPointsToAdd = 3;
    }
    customer.addLoyaltyPoints(loyaltyPointsToAdd);
}

void LoyaltyPointsChecker(Customer& customer, CoffeeItem& coffee) {
    int loyaltyPoints = customer.getLoyaltyPoints();
    double price = coffee.getPrice();

    if (loyaltyPoints <= 5) {
        price *= 0.975;
    } else if (loyaltyPoints <= 8) {
        price *= 0.95;
    } else if (loyaltyPoints <= 10) {
        price *= 0.925;
    }
    coffee.setPrice(price);
}

void printReceipt(const Customer& customer) {
    static int receiptCount = 0;
    receiptCount++;

    const int width = 35;

    string name = customer.getName();
    if (!name.empty()) {
        name[0] = toupper(name[0]);
    }

    stringstream receiptNumberStream;
    receiptNumberStream << " Chitanta numar : #" << setw(2) << setfill('0') << receiptCount;

    cout << "|-----------------------------------|" << endl;
    cout << "|" << setw(width) << left << receiptNumberStream.str() << "|" << endl;
    cout << "|" << setw(width) << left << " Numele clientului: " + customer.getName() << "|" << endl;
    cout << "|" << setw(width) << left << " Puncte de loialitate totale: " + to_string(customer.getLoyaltyPoints()) << "|" << endl;

    stringstream stream;
    stream << fixed << setprecision(2) << customer.getTotalAmountSpent() << " RON";
    cout << "|" << setw(width) << left << " Suma totala cheltuita: " + stream.str() << "|" << endl;

    cout << "|" << setw(width) << left << " Comanda de cafea: " + customer.getCoffeeItemName() << "|" << endl;
    cout << "|-----------------------------------|" << endl;
}

int main() {
    string name;
    bool validName = false;

    while (!validName) {
        cout << "Introdu nume: ";
        cin >> name;

        validName = true;
        for (char c : name) {
            if (!isalpha(c)) {
                validName = false;
                cout << "Numele introdus nu poate fi validat" << endl;
                break;
            }
        }
    }

    if (!name.empty()) {
        name[0] = toupper(name[0]);
    }

    Customer customer(name, 0);

    int coffeeChoice, anotherOne;
    bool wantAnotherCoffee = true;

    while (wantAnotherCoffee) {
        cout << "Selecteaza cafeaua:\n";
        cout << "1. Cappuccino (S) - 1.99 RON\n";
        cout << "2. Cappuccino (M) - 2.99 RON\n";
        cout << "3. Cappuccino (L) - 3.99 RON\n";
        cout << "4. Espresso (S) - 1.99 RON\n";
        cout << "5. Espresso (M) - 2.99 RON\n";
        cout << "6. Espresso (L) - 3.99 RON\n";
        cout << "0. Exit\n";
        cout << "Introdu optiune: ";
        cin >> coffeeChoice;

        if (coffeeChoice == 0) {
            break;
        }

        if (coffeeChoice >= 1 && coffeeChoice <= 6) {
            CoffeeItem coffeeOptions[] = {
                CoffeeItem("Cappuccino (S)", "S", 1.99),
                CoffeeItem("Cappuccino (M)", "M", 2.99),
                CoffeeItem("Cappuccino (L)", "L", 3.99),
                CoffeeItem("Espresso (S)", "S", 1.99),
                CoffeeItem("Espresso (M)", "M", 2.99),
                CoffeeItem("Espresso (L)", "L", 3.99)
            };
        placeOrder(customer, coffeeOptions[coffeeChoice - 1]);

        printReceipt(customer);
        
        cout <<"Mai vrei o cafea? (1 - Da | 2 - Nu)";
        cin >> anotherOne;
        if (anotherOne == 2) {
            cout << "Va multumim ca ati ales sa consumati o cafea de la noi! Va uram, o zi buna!";
            wantAnotherCoffee = false;
        }
    } else if (coffeeChoice != 0) {
        cout << "Optiunea de cafea aleasa nu este valida." << endl;
    }
 }

 return 0;
}