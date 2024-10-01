#ifndef TRIUNGHI_H
#define TRIUNGHI_H

class Triunghi {
public:

    Triunghi();
    Triunghi(double lung, double lat);

    void setDimensiune(double lung, double lat);
    double getLungime() const;
    double getLatime() const;
    double arie() const;
    double perimetru() const;
    void print() const;

private:
    double lungime;
    double latime;
};

#endif
