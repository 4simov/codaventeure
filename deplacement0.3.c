//deplacement0.3.c
/*Programme débuté le 9 décembre, il va gérer les deplacements du joueur dans l'univers du rpg.

-Aides-
	. Pour répondre aux questions il faut écrire entièrement la réponse ( plus tard il y aura le choix entre répondre le chiffre ou réecrire la réponse entièrement ).

*/

#include <stdio.h>
#include <string.h>


#define MAXX 10
#define MAXY 10
#define MAXZ 100

/* Valeurs globales */

char pos[ MAXX ][ MAXY ][ MAXZ ];//definition de la longueur du tableau x et y et en z sera stocké la phrase de description du lieu.

int x = 1, y = 1;


/* Fonctions pour le deplacement */

void verification( int *a, int *b, int *c, int *d ) //Ici nous vérifions les directions possibles selon la position x,y du joueur.
{
	
	*a = 1; *b = 1; *c = 1; *d = 1;

	if( y > ( MAXY - 1 ) )//Nord
		*a = 0;

	if( y < 2 )//Sud
		*b = 0;

	if( x > ( MAXX - 1 ) )//Est
		*c = 0;

	if( x < 2 )//Ouest
		*d = 0;

}

void MenuDeplacement( int a, int b, int c, int d )//Ici nous allons gérer l'affichage des choix de directions disponible à l'utilisateur.
{
	
	int i = 0, nb[ 4 ] = { a, b, c, d }, n = 1;
	char dir[ 4 ][ 6 ] = { "Nord", "Sud", "Est", "Ouest" };

	for( i = 0; i < 4; i++ )
	{
		
		if( nb[i] == 1 )//vérification des valeures bouléennes contenu dans les différentes variable de direction.
		{		
			printf( "%d) %s\n", n, dir[i] );
			n++;
		}

	}

}




int saisieMap( int a, int b, int c, int d )
{
	int n = 1;
	char dir[ 4 ][ 6 ] = { "Nord", "Sud", "Est", "Ouest" }, tabsaisie[ 20 ];

	printf( "Dans quelle direction allez-vous ?\n=> " );
	scanf( "%s", &tabsaisie );	

	if( strcmp( dir[ 0 ], tabsaisie) == 0 && a == 1 )//Nord
	{
		y++;
//		n = 0;
	}

	else if( strcmp( dir[ 1 ], tabsaisie ) == 0 && b == 1 )//Sud
	{
		y--;
//		n = 0;
	}

	else if( strcmp( dir[ 2 ], tabsaisie ) == 0 && c == 1 )//Est
	{
		x++;
//		n = 0;
	}

	else if( strcmp( dir[ 3 ], tabsaisie ) == 0 && d == 1 )//Ouest
	{
		x--;
//		n = 0;
	}
	
	else 
		printf( "saisie invalide\n" );

	printf( "\n" );

	return n;
}


int deplacement( )
{
	int continuer = 1, Nord = 1, Sud = 1, Est = 1, Ouest = 1;


	while( continuer )
	{
		printf( "Où allez-vous ? ( position(%d,%d) )\n", x, y );

		verification( &Nord, &Sud, &Est, &Ouest );//Vérifie les directions possibles

		MenuDeplacement( Nord, Sud, Est, Ouest );//Affiche les différentes direction que l'utilisateur peut prendre

		continuer = saisieMap( Nord, Sud, Est, Ouest );//Lorsque la saisie du joueur est valide saisie() retourne 0, ainsi la boucle s'arrete
	}

}

/* Fin des fonctions de déplacement */

int main()
{
	
	deplacement( );


	return 0;

}
