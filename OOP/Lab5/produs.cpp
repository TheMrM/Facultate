#include <iostream>

class Produs {
    static int serialNumber; 

public:
    static int getSerialNumber() { 
        return ++serialNumber;
    }
};

int Produs::serialNumber = 0;

int main() {
    int ij;
    Produs Serial;
    ij = Serial.getSerialNumber();
    
    for (int i = 0; i < 5; i++){
        ij = Serial.getSerialNumber();
        std::cout << "Product series " << ij << std::endl;
    }

   return 0;
}