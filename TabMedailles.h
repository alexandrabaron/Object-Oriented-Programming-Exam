#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> 
#include <stdbool.h> 
#include "Nation.h"
#include "TabNations.h"

enum Critere
{
	ALPHA, MEDAILLES_OR, TOTAL_MEDAILLES
};

enum Filtre
{
	TOUTES_NATIONS, UNE_NATION
};

class TabMedailles : public TabNations
{
public : 
	TabMedailles();
	TabMedailles(const string& nomFichier);
	
	int getMedailles(const string& nom, Metal metal) const;
	bool setMedailles(const string& nom, int nbOr, int nbArgent, int nbBronze); //true si ajouté ou créé, false si il s'est rien passé
	bool ajouterMedailles(const string& nom, Metal metal, int nb); //true si ajouté ou créé, false si il s'est rien passé
	void mettreTabDansFic(const string& nomFichier) const;
	
	/*~~~~~~~~~~Partie 4~~~~~~~~~~*/
	void afficher() const;
	void setCritere(Critere c);
	void setFiltre(Filtre f, const string& n);
private :
	Critere critere;
	Filtre filtre;
	string nomFiltre;
	
};


