using namespace std;

#include <iostream>
#include <math.h>
#include <stdbool.h> 
#include <string>
#include <vector>
#include <fstream> 

#include "Nation.h"
#include "TabNations.h"
#include "TabMedailles.h"

int main()
{
	Nation n1;
	Nation n2("France", 2,2,10);
	Nation n3("Chili", 2, 4, 0);
	Nation n4("Argentine", 22,32,10);
	Nation n5("Russie", 24, 0, 0);
	cout<<n1;
	cout<<n2;
	cout<<n3;
	//cin>>n1;
	cout<<n1;
	if(n2>n3) cout<<"yupiiii"<<endl;
	
	TabNations tab;
	tab.ajouterNation(n2);
	tab.ajouterNation(n3);
	tab.ajouterNation(n4);
	tab.ajouterNation(n5);
	tab.setNation(0, n3);
	tab.afficher();
	
	cout<<tab.chercher("Argentine");
	TabMedailles tabm("FicMed.txt");
	tabm.setMedailles("Pologne", 2, 4, 8);
	tabm.mettreTabDansFic("FicMed2.txt");
	
	tabm.setCritere(ALPHA);
	tabm.setFiltre(TOUTES_NATIONS, "");
	tabm.afficher();
	
	
	return 0;
}
