#include <stdio.h>

#include "header.h"

#define BUFSIZE 8192


void analizator_skladni(char *nazwa_pliku)
{
  int tmp;
  int i;
  int stop;
  int para_naw_k = 0; //czy nawiasy klamrowe sie zgadzaja 
  int para_naw_z = 0; //czy zwykle nawiasy sie zgadzaja
  char buf[BUFSIZE];

  FILE *in = fopen(nazwa_pliku, "r");
  
  
  
  if( in == NULL ) 
  {
    fprintf( stderr, błąd: nie mogę czytać pliku %s\n", nazwa_pliku);
    return EXIT_FAILURE;
  }
  
  while( fgets( buf, BUFSIZE, in ) != NULL ) 
  {
    tmp = strlen(buf);
    i = 0;
    stop = 0;
    while(i < tmp && stop == 0)
    {
      analizator_leksykalny(buf);
    }
  }
  
  
}

