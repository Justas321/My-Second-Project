#ifndef STRUC_H_INCLUDED
#define STRUC_H_INCLUDED
#include "mylib.h"

/*struct duom {
  string vardas;
  string pavarde;
  int paz_sk;
  vector <int> pazymiai;
  int egzaminas;
  double galutinis;
};*/

class Zmogus{
protected:
    string zmVardas;
    string zmPavarde;
public:
    virtual void setVardas(string vardas) {zmVardas = vardas;}
    virtual void setPavarde(string pavarde) {zmPavarde = pavarde;}
    inline string getVardas() const {return zmVardas;}
    inline string getPavarde() const {return zmPavarde;}
    Zmogus(){
        zmVardas = " ";
        zmPavarde = " ";
    }
};

class duom : public Zmogus{
private:
    string vardas;
    string pavarde;
    int paz_sk;
    vector <int> pazymiai;
    int egzaminas;
    double galutinis;
public:
    ~duom(){pazymiai.clear();}
    duom(string vardas = " ", string pavarde = " ", int paz_skaicius = 0, int egz = 0, double gal = 0, vector <int> paz = {0});
    duom& operator=(const duom& naujas){
        if(this == &naujas){return *this;}
        vardas = naujas.vardas;
        pavarde = naujas.pavarde;
        paz_sk = naujas.paz_sk;
        egzaminas = naujas.egzaminas;
        galutinis = naujas.galutinis;
        copy(naujas.pazymiai.begin(),naujas.pazymiai.end(),pazymiai.begin());
        return *this;
    }
    double getBalas() const {return galutinis;}
    void setPazymiai(vector <int> nd) {pazymiai = nd;}
    inline int getEgzas() const {egzaminas;}
    void setEgzas(int egzas) {egzaminas = egzas;}
    void pazKiek(int pazK) {paz_sk = pazK;}
    void setBalas(int gal) {galutinis = gal;}
};

double vid_med (char tikrinimas, vector <int> &laik, int paz_sk, int egzaminas);
void Nuskaitymas(vector <duom> &func, int &kiek, string pavadinimas, char tikrinimas);
void Generavimas(int dydis, string pavadinimas);
bool Palyginimas(const duom &stud1, const duom &stud2);
#endif // STRUC_H_INCLUDED
