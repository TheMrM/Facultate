#include <iostream>

using namespace std;

class Persoane {
    private:
        std::string Nume;
        int cnp;
    
    public:
        Persoane(const std::string& fNume, int persoanaCNP) : Nume(fNume), cnp(persoanaCNP) {}

        // Getter methods for accessing the attributes
        std::string getName() const {
            return Nume;
        }

        int getcnp() const {
            return cnp;
        }
};

void setName(Persoane& persoana, const std::string& fNume){
    persoana.Nume = fNume;
}

void setcnp(Persoane& persoana, int persoanaCNP){
    persoana.cnp = persoanaCNP
}

int main(){
void Persoane::getName(){
    cout<<"Introduceti numele: "<<endl;
    cin>>Nume;
}

void Persoane::getcnp(){
    cout<<"Introduceti CNP"<<endl;
    cin>>cnp;
}


}