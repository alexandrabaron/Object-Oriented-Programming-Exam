using namespace std;


#include <iostream>
#include <math.h>
#include <stdbool.h> 
#include <string>
#include <vector>
#include "Nation.h"
#include "TabNations.h"


TabNations::TabNations() : nbNations(0)
{}

void TabNations::ajouterNation(const Nation& nation)
{
	nations[nbNations++] = nation;
}

void TabNations::afficher() const
{
	cout<<endl<<"Tableaux des nations : "<<endl;
	for(int i=0; i<nbNations; i++)
	{
		cout<<nations[i];
	}
	cout<<endl;
}

int TabNations::getNbNations() const
{
	return nbNations;
}
Nation TabNations::getNation(int i) const
{
	return nations[i];
}

void TabNations::setNation(int i, const Nation& nation)
{
	nations[i] = nation;
}

int TabNations::chercher(const string& nom) const
{
	for(int i=0; i<nbNations; i++)
	{
		if(nations[i].getNom() == nom)
		{
			return i;
		}
	}
	return -1;
}


vector<Nation> TabNations::getNationVect() const
{
	vector<Nation> vectNat;
	for(int i=0; i<nbNations; i++)
	{
		vectNat.push_back(nations[i]);
	}
	return vectNat;
	
}


