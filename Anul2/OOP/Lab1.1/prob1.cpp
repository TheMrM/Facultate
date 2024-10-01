#include <iostream>
#include <cmath>
using namespace std;

class TPunct{
    int x,y;
public:
    void init(int,int);
    void mutaSus();
    void mutaJos();
    void mutaSt();
    void mutaDr();
    void afis();
};

void TPunct::init(int a,int b)
{
    this->x=a;
    y=b;
};
void TPunct::mutaSt()
{x--;
};

void TPunct::mutaDr()
{x++;
};

void TPunct::mutaSus()
{y++;
};

void TPunct::mutaJos()
{y--;
};

void TPunct::afis()
{
     cout<<"("<<x<<","<<y<<")"<<endl;
     };

int main()
{
    TPunct p1;
    p1.init(1,1);
    p1.mutaJos();
    p1.mutaDr();
    p1.afis();
}