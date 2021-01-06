#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "header.h"

#define BUFSIZE 8192
#define MAXLINII 1000
#define MAXSLOW 100

int linie[MAXSLOW][MAXLINII];

int main(int argc, char *argv[])
{
	int i;
	int ile_linii;
	char buf[BUFSIZE];
	
	FILE *in;
	
	for(i=1;i <= argc-1; i++)
	{
		in = fopen( argv[i], "r" );
		ile_linii= 0;
		
		while( fgets( buf, BUFSIZE, in ) != NULL ) 
		{
			ile_linii++;
			for( i= 0; i < ile_slow; i++ )
				if( strstr( buf, slowa[i] ) != NULL )
				{
					linie[i][0]++;
					linie[i][linie[i][0]]= ile_linii;
				}
  		}
	}
	//zaczynamy
	return 0;
}
