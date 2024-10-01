#include <iostream>

using namespace std;

class FormaGeometrica{
    public:
        FormaGeometrica() { id_ = total_++;}
        virtual void deseneaza() = 0;
    protected:
        int id_;
        static int total_;
};

int FormaGeometrica::total_ = 0;

class Cerc : public FormaGeometrica {
    public:
        void deseneaza() {
            cout << "Cerc " << id_ << " : deseneaza" << endl;
        }
};

class Patrat : public FormaGeometrica {
    public:
        void deseneaza() {
            cout << "Patrat " << id_ << " : deseneaza" << endl;
        }
};

class Elipsa : public FormaGeometrica {
    public:
        void deseneaza() {
            cout << "Elipsa " << id_ << " : deseneaza" << endl;
        }
};

class Dreptunghi : public FormaGeometrica {
    public:
        void deseneaza() {
            cout << "Dreptunghi" << id_ << " : deseneaza" << endl;
        }
};

class FabricaForme {
    public:
        virtual FormaGeometrica* CreareFormaCurba() = 0;
        virtual FormaGeometrica* CreareFormaDreapta() = 0;
};

class FabricaFormeSimple : public FabricaForme {
    FormaGeometrica* CreareFormaCurba() {
        return new Cerc;
    };

    FormaGeometrica* CreareFormaDreapta() {
        return new Patrat;
    };
};

class FabricaFormeGenerale : public FabricaForme {
    public:
        FormaGeometrica* CreareFormaCurba() {
            return new Elipsa;
        };
        FormaGeometrica* CreareFormaDreapta() {
            return new Dreptunghi;
        };
};
int main() {
    FabricaForme* ff = new FabricaFormeGenerale;
    FormaGeometrica* FG[3];

    FG[0] = ff -> CreareFormaCurba();
    FG[1] = ff -> CreareFormaDreapta();
    FG[2] = ff -> CreareFormaCurba();

    for (int i = 0; i < 3; i++) {
        FG[i] -> deseneaza();
    }
}