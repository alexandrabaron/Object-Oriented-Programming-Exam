#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>

#include "Nation.h"
#define MAX_NATIONS 400

class TabNations
{
public:
    TabNations();
    
    void ajouterNation(const Nation& nation);
    void afficher() const;
    int getNbNations() const;
    Nation getNation(int i) const;
    void setNation(int i, const Nation& nation);
    int chercher(const string& nom) const;
    vector<Nation> getNationVect() const;

private:
	Nation nations[MAX_NATIONS];
	int nbNations;
};
