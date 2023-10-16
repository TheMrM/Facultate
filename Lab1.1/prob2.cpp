#include <iostream>

using namespace std;

class FkPunct{
    int i,j;
public:
    void init(float, float);
    void display();
};

void FkPunct::init(float o, float p)
{
    i=o;
    this->j=p;
}

void FkPunct::display()
{
    cout<<"\n "<<i<<" +i "<<j<<" este o alocare din memoria "<<this<<endl;
};

int main()
{
    FkPunct A;
    A.init(1,2);
    cout<<" Adresa obiectului A este "<<&A;
    A.display();
    FkPunct B;
    B.init(3,4);
    cout<<" Adresa obiectului B este "<<&B;
    B.display();
}