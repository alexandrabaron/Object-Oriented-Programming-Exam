using namespace std;


#include <iostream>
#include <math.h>
#include <stdbool.h> 
#include <string>
#include <fstream> 
#include <vector>
#include "Nation.h"
#include "TabNations.h"
#include "TabMedailles.h"

TabMedailles::TabMedailles()
{}


TabMedailles::TabMedailles(const string& nomFichier)
{
	ifstream fic(nomFichier);
	while(!fic.fail())
	{
		
		string newN;
		int nbOr, nbArgent, nbBronze;
		fic>>newN>>nbOr>>nbArgent>>nbBronze;
		if(!fic.fail()) //données lues ok
		{
			Nation nat(newN);
			nat.setMedailles(nbOr, nbArgent, nbBronze);
			TabNations::ajouterNation(nat);	
		}
	}
}

int TabMedailles::getMedailles(const string& nom, Metal metal) const
{
	int index = TabNations::chercher(nom);
	if(index >-1)
	{
		return TabNations::getNation(index).getMedailles(metal);
	}
	else return 0;
}

bool TabMedailles::setMedailles(const string& nom, int nbOr, int nbArgent, int nbBronze)
//on set = met à, pas ajoute
{
	int index = TabNations::chercher(nom);
	
	if(index >-1)
	{
		TabNations::getNation(index).setMedailles(nbOr, nbArgent, nbBronze);
		return true;
	}
	else if(index == -1)
	{
		Nation nat(nom, nbOr, nbArgent, nbBronze); 
		TabNations::ajouterNation(nat);
		return true;
	}
	return false;
}
bool TabMedailles::ajouterMedailles(const string& nom, Metal metal, int nb)
{
	int index = TabNations::chercher(nom);
	
	if(index >-1)
	{
		TabNations::getNation(index).ajouterMedailles(metal, nb);
		return true;
	}
	else if(index == -1)
	{
		Nation nat(nom);
		nat.ajouterMedailles(metal, nb);
		TabNations::ajouterNation(nat);
		return true;
	}
	return false;
}

void TabMedailles::mettreTabDansFic(const string& nomFichier) const
{
	ofstream fic(nomFichier);
	for(int i=0; i< TabNations::getNbNations(); i++)
	{
		fic<<TabNations::getNation(i);
	}
}

/*~~~~~~~~~~Partie 4~~~~~~~~~~*/

void TabMedailles::afficher() const
{
	if(filtre == UNE_NATION)
	{
		int index = TabNations::chercher(nomFiltre);
		if(index >-1)
		{
			cout<<TabNations::getNation(index);
			cout<<"Nb total de médailles = "<<TabNations::getNation(index).getNbMedailles()<<endl;
		}
	}
	if(filtre == TOUTES_NATIONS)
	{
		vector<Nation> vectNat = TabNations::getNationVect();
		if( critere == ALPHA)
		{
			sort(vectNat.begin(), vectNat.end(), CompareNationNoms());
			for (int i = 0; i < TabNations::getNbNations(); i++)
       			{
       				 cout<<vectNat[i];
       				 cout<<"Nb total de médailles = "<<vectNat[i].getNbMedailles()<<endl;
       			}
		}
		else if( critere == MEDAILLES_OR) //utilise operator > et <
		{
			sort(vectNat.begin(), vectNat.end(), CompareNationNbMedailles());
			for (int i = 0; i < TabNations::getNbNations(); i++)
       			{
       				 cout<<vectNat[i];
       				 cout<<"Nb total de médailles = "<<vectNat[i].getNbMedailles()<<endl;
       			}
		}
		else if( critere == TOTAL_MEDAILLES)
		{
			int tabtot[TabNations::getNbNations()];
			for (int i = 0; i < TabNations::getNbNations(); i++)
       			{
       				 tabtot[i] = vectNat[i].getNbMedailles();
       			}
       			//je n'ai pas eu le temps de finir :/
		}
	}
}


void TabMedailles::setCritere(Critere c)
{
	critere = c;
}
void TabMedailles::setFiltre(Filtre f, const string& n)
{
	filtre = f;
	nomFiltre = n;
}


