#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <stdbool.h>


enum Metal
{
	OR, ARGENT, BRONZE
};

class Nation
{
public:
    Nation();
    //Nation(const char* s);
    //Nation(const char* s, int o, int a, int b);
    
    Nation(const string& s);
    Nation(const string& s, int o, int a, int b);
    
    void setMedailles(int nbOr, int nbArgent, int nbBronze);
    void ajouterMedailles(Metal metal, int nb);
    
    string getNom() const;
    int getMedailles(Metal metal) const;
    
    friend ostream& operator<<(ostream& flux, const Nation& N);
    friend istream& operator>>(istream& flux, Nation& N);
    
    friend bool operator>(const Nation& N1, const Nation& N2);
    
    //Pour la partie 4
    int getNbMedailles() const;
    friend bool operator<(const Nation& N1, const Nation& N2);

private:
	string nom;
	int medailles[3];
};


class CompareNationNbMedailles
{
public :
    bool operator() (const Nation& n1, const Nation& n2)
    {
        return n1.getNbMedailles() > n2.getNbMedailles();
    }
};

class CompareNationNoms
{
public :
    bool operator() (const Nation& n1, const Nation& n2)
    {
        return n1.getNom() < n2.getNom();
    }
};
