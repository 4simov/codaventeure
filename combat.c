//combat.c
#include <stdio.h>
#include <time.h>
#include <string.h>

#define WAIT 1500000

void wait(unsigned timeout)//fonction pour faire une pause sur le terminal
{

	timeout += clock();

	while(clock() < timeout)
 		continue;

}

typedef struct fiche fiche;
struct fiche
{

	char prenom[ 20 ];
	char nom[ 20 ];
	int age;
	char sexe[ 5 ];

	char classe[ 20 ];
	int pv;
	int pm;
	int dgt;

};

// classes

fiche guerrier = { "", "", 0, "", "guerrier", 14, 3, 6 };

fiche mage = { "", "", 0, "", "mage", 5, 12, 2 };

fiche voleur = { "", "", 0, "", "guerrier", 9, 5, 4 };

//Fin-classes


void affactions()
{

	printf("Que faites-vous ?\nAttaquer\tMagie\tFuir\n");

}


int saisiecombat( char t[ ][ 20 ] )
{

	int continuer = 1;
	char tab[ 20 ];

	while( continuer )
	{
		affactions();

		printf("=> ");
		scanf("%s", tab );
	
		if( strcmp( t[ 0 ], tab ) == 0 )//attaquer 
			return 1;

		else if( strcmp( t[ 1 ], tab ) == 0 )//magie
			return 2;

		else if( strcmp( t[ 2 ], tab ) == 0 )//fuir
			return 3;

		else 
			printf( "Saisie invalide\n" );

	}

}


int Attaque( fiche *joueur, fiche *gobelin )
{

	gobelin->pv -= joueur->dgt;
	printf("Il reste %d à l'ennemi.\n", gobelin->pv );
	wait( WAIT );
}

int AttaqueEnnemi( fiche *joueur, fiche *gobelin )
{

	joueur->pv -= gobelin->dgt;
	if( joueur->pv > 0 )
	{

		printf( "Il vous reste %d points de vie.\n", joueur->pv );
		wait( WAIT ); 

	}

	else if( joueur->pv < 1 )
		printf( " Vos points de vie sont tombés à 0. " );

}


int MenuMagie()
{

	
	printf("-feu\tglace\tfoudre" );



}


int main()
{

	int action = 0;
	char choix[ ][ 20 ] = { "Attaquer", "Magie", "Fuir" };
	fiche joueur = { "Niendor", "Korden", 28, "homme", "Guerrier", 14, 3, 6 };
	
	fiche gobelin = { "Gobelin", "", 12, "homme", "Guerrier", 10, 0, 3 };

	while( joueur.pv > 0 && gobelin.pv > 0 )
	{

//joueur	

		action = saisiecombat( choix );

		if( action == 1 )
			Attaque( &joueur, &gobelin );

		else if( action == 2 )
			MenuMagie();

		
//ennemi

		AttaqueEnnemi( &joueur, &gobelin );

		printf( "\n" );
	}

	if( gobelin.pv < 1 ) 
		printf( " Vous avez gagné\n" );

	else if( joueur.pv < 1 ) 
		printf( " Vous avez perdu\n" );

}










