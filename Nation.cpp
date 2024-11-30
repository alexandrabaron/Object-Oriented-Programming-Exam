using namespace std;

#include <iostream>
#include <math.h>
#include <stdbool.h> 
#include <cstring> 
#include <cctype>

#include <string> 
#include "Nation.h"


Nation::Nation() : nom()
{
	for(int i = 0; i<3; i++)
	{
		medailles[i] = 0;
	}
}
/*
Nation::Nation(const char* s) : nom(s)
{
	for(int i = 0; i<3; i++)
	{
		medailles[i] = 0;
	}
}
*/
/*
Nation::Nation(const char* s, int o, int a, int b) : nom(s)
{
	medailles[0] = o;
	medailles[1] = a;
	medailles[2] = b;
}
*/
Nation::Nation(const string& s) : nom(s)
{
	for(int i = 0; i<3; i++)
	{
		medailles[i] = 0;
	}
}

Nation::Nation(const string& s, int o, int a, int b) : nom(s)
{
	medailles[0] = o;
	medailles[1] = a;
	medailles[2] = b;
}
void Nation::setMedailles(int nbOr, int nbArgent, int nbBronze)
{
	medailles[0] = nbOr;
	medailles[1] = nbArgent;
	medailles[2] = nbBronze;
}
void Nation::ajouterMedailles(Metal metal, int nb)
{
	medailles[metal] += nb;
}

string Nation::getNom() const
{
	return nom;
}
int Nation::getMedailles(Metal metal) const
{
	return medailles[metal];
}

ostream& operator<<(ostream& flux, const Nation& N)
{
	flux<<N.nom<<" : Or = "<<N.medailles[0]<<" : Argent = "<<N.medailles[1]<<" : Bronze = "<<N.medailles[2]<<endl;
	return flux;
}

istream& operator>>(istream& flux, Nation& N)
{
	cout<<"Pays nbO nbA nbB"<<endl;
	flux>>N.nom>>N.medailles[0]>>N.medailles[1]>>N.medailles[2];
	return flux;
}

bool operator>(const Nation& N1, const Nation& N2)
{
	if(N1.medailles[0]>N2.medailles[0]) return true;
	else if ((N1.medailles[0]==N2.medailles[0])&&(N1.medailles[1]>N2.medailles[1])) return true;
	else if((N1.medailles[0]==N2.medailles[0])&&(N1.medailles[1] == N2.medailles[1]) && (N1.medailles[2] > N2.medailles[2])) return true;
	else return false;
}


int Nation::getNbMedailles() const
{
	return medailles[0]+medailles[1]+medailles[2];
}

bool operator<(const Nation& N1, const Nation& N2)
{
	if(N1.medailles[0]<N2.medailles[0]) return true;
	else if ((N1.medailles[0]==N2.medailles[0])&&(N1.medailles[1]<N2.medailles[1])) return true;
	else if((N1.medailles[0]==N2.medailles[0])&&(N1.medailles[1] == N2.medailles[1]) && (N1.medailles[2] < N2.medailles[2])) return true;
	else return false;
}


