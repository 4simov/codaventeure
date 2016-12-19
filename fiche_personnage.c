//fiches_personnage.c

#include <stdio.h>
#include <string.h>



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

};

// classes

fiche guerrier = { "", "", 0, "", "guerrier", 14, 3 };

fiche mage = { "", "", 0, "", "mage", 5, 12 };

fiche voleur = { "", "", 0, "", "guerrier", 9, 5 };

//Fin-classes

fiche joueur = { "", "", 0, "", "druide", 0, 0 };

int remplir()
{
	
	printf( "Votre sexe ? ( écrire 'homme' ou 'femme' )\n=> " );
	scanf("%s", joueur.sexe );

	printf("Votre prénom ? ( 20 caractères max )\n=> ");
	scanf("%s", joueur.prenom );

	printf("Votre nom ? ( 20 caractères max )\n=> ");
	scanf("%s", joueur.nom );

	printf("Votre âge ?\n=> ");
	scanf("%d", &joueur.age );


}

int ChoixClasse( char t[][ 10 ])
{

	int continuer = 1;
	char tab[ 20 ];

	while( continuer )
	{

		printf("classe entre guerrier, mage et voleur ?\n=> ");
		scanf("%s", tab );

		if( strcmp( t[ 0 ], tab ) == 0 )//guerrier
			return 1;

		else if( strcmp( t[ 1 ], tab ) == 0 )//mage
			return 2;

		else if( strcmp( t[ 2 ], tab ) == 0 )//voleur
			return 3;

	}

}

void caracteristiques( char tab[][ 10 ])
{

	if( ChoixClasse( tab ) == 1 )
	{

		joueur.pv = guerrier.pv;
		joueur.pm = guerrier.pm;
		strcpy( joueur.classe, guerrier.classe );

	}

	else if( ChoixClasse( tab ) == 2 )
	{
		
		joueur.pv = mage.pv;
		joueur.pm = mage.pm;
		strcpy( joueur.classe, mage.classe );

	}

	else if( ChoixClasse( tab ) == 3 )
	{
		
		joueur.pv = voleur.pv;
		joueur.pm = voleur.pm;
		strcpy( joueur.classe, voleur.classe );

	}

	printf("%s\n", joueur.classe );

	remplir();


}

void affichepj()
{

	printf( " #--Personnage--#\n");
	printf( " | Prénom : %s\n", joueur.prenom );
	printf( " | Nom : %s\n", joueur.nom );
	printf( " | Age : %d\n", joueur.age );
	printf( " | Sexe : %s\n", joueur.sexe );
	printf( " | Classe : %s\n", joueur.classe );
	printf( " | Points de vie : %d\n", joueur.pv );
	printf( " | Points de magie : %d\n", joueur.pm );
	printf( " #---------------#\n" );

}


int main()
{

	char classe[ 3 ][ 10 ] = { "guerrier", "mage", "voleur" };
	printf( "%s\n", guerrier.classe ); 
	caracteristiques( classe );
	affichepj();


}











