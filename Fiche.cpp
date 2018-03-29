#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class Fiche {

private :

	string nom;
	int pv;
	int pm;
	int force;
	
	
public :

	Fiche() {
		string nom ="inconnu";
		pv = 5;
		pm = 1;
		force = 2;			
	}

	void carac() {
		cout << "--------Fiche---------" << endl;
		cout << "Nom : " << nom << "PV : "<< pv << "PM : "<< pm <<"Force : "<< force << endl;
		cout << "----------------------" << endl;
	}

};

int main() {
	
		Fiche joueur;
		joueur.carac();
}
