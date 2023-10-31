#include <iostream>
#include <string>

class CoffeeItem {
public:
    CoffeeItem(std::string name, std::string size, double price) : name(name), size(size), price(price) {}

    std::string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    std::string getSize() {
        return size;
    }

private:
    std::string name;
    std::string size;
    double price;
};

class Customer {
private:
    std::string name;
    int loyaltyPoints;
    double totalAmountSpent;
    CoffeeItem coffeeItem;

public:
    Customer(std::string name, int loyaltyPoints) : name(name), loyaltyPoints(loyaltyPoints), totalAmountSpent(0.0), coffeeItem("Unkown", "Unknown", 0.0) {}

    std::string getName() {
        return name;
    }

    int getLoyaltyPoints() {
        return loyaltyPoints;
    }

    double getTotalAmountSpent() {
        return totalAmountSpent;
    }

    std::string getCoffeeItemName() {
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

int main() {
    std::string name;
    
    std::cout << "Introdu nume: ";
    std::cin >> name;

    Customer customer(name);

    int coffeeChoice;
    bool wantAnotherCoffee = true;

    while (wantAnotherCoffee) {
        std::cout << "Selecteaza cafeaua:\n";
        std::cout << "1. Cappuccino (S) - 4.99 RON\n";
        std::cout << "2. Cappuccino (M) - 2.99 RON\n";
        std::cout << "3. Cappuccino (L) - 2.99 RON\n";
        std::cout << "4. Espresso (S) - 2.99 RON\n";
        std::cout << "5. Espresso (M) - 2.99 RON\n";
        std::cout << "6. Espresso (L) - 2.99 RON\n";
        std::cout << "0. Exit\n";
        std::cout << "Introdu optiune: ";
        std::cin >> coffeeChoice;


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

        std::cout << "Numele clientului: " << customer.getName() << std::endl;
        std::cout << "Puncte de loialitate totale: " << customer.getLoyaltyPoints() << std::endl;
        std::cout << "Suma totala cheltuita: " << customer.getTotalAmountSpent() << " RON" << std::endl;
        std::cout << "Comanda de cafea: " << customer.getCoffeeItemName() << std::endl;

        std::cout <<"Mai vrei o cafea? (1 - Da | 2 - Nu)";
        std::cin >> wantAnotherCoffee;
    } else if (coffeeChoice != 0) {
        std::cout << "Optiunea de cafea aleasa nu este valida." << std::endl;
    }
 }

 return 0;
}