//postion.c
#include "position.h"
#include <string.h>


struct position
{

	int x;
	int y;
	

};


typedef struct position position;

position Lieu = { 1, 1 };

int deplacement( int a )
{

	char tab[ 20 ], Nord[ ] = { "Nord" }, Sud = { "Sud" }, Est = { "Est" }, Ouest = { "Ouest" };
	scanf( "%s", tab );

	if( strcmp( tab, Nord ) == 0 )
		Lieu.y += 1;
	
	
	else
		return -1;

}

int verification(  )
{

	if( Lieu.x == 1 || Lieu.y == 1 )
		printf( "Sud et Nord\n" );
	
	if( Lieu.x == 6 || Lieu.y == 1 )
		printf( "Sud et Ouest\n" );

}

void init()
{

	int pos[1][1];

}
