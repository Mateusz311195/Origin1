#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "header.h"

#define BUFSIZE 8192
#define ILE_ZNANYCH_FUNKCJI 9

struct f
{
	int gdzie_prototyp;
	int def_start;
	int def_koniec;
	int *gdzie_uzycie[150];
	int ile_uzyc;
	char *nazwa;
	char **co_wywoluje;
} autorskie_funkcje[150];

void analizator_skladni(char *nazwa_pliku)
{
  int ile_mamy_funkcji = 0;
  int tmp;
  int i;
  int j;
  int stop;
  int ignore;
  int numer_linii=0;
  int para_naw_k = 0; //czy nawiasy klamrowe sie zgadzaja
  int para_naw_z = 0; //czy zwykle nawiasy sie zgadzaja
  char buf[BUFSIZE];
  char *subbuf;
  char *funkcje[ILE_ZNANYCH_FUNKCJI] = {"for","while","sizeof","main","if","switch","return","printf","scanf"};

  FILE *in = fopen(nazwa_pliku, "r");

  if( in == NULL )
  {
    fprintf( stderr, "błąd: nie mogę czytać pliku %s\n", nazwa_pliku);
    return -1;
  }

  while( fgets( buf, BUFSIZE, in ) != NULL )
  {
    tmp = strlen(buf);
    i = -1;
    stop = 0;
    ignore = 0;
    while(i+1 < tmp && stop == 0)
    {
      i++;
      switch (buf[i])
        {
            case '(':
                if(ignore == 1)
                    continue;
                para_naw_z++;
                subbuf = malloc(BUFSIZE * sizeof(char));
                j = i;
                while(j-1>0 && ((buf[j-1] > 64 && buf[j-1]<91) || (buf[j-1] > 96 && buf[j-1]<123)))
                  j--;
                strncpy(subbuf, buf+j, i-j);
                subbuf[i-j+1] = '\0';
                for(j=0; j < ILE_ZNANYCH_FUNKCJI; j++) // sprawdzamy czy funkcja nalezy do znanych funkcji
                {
                  if(strcmp(funkcje[j], subbuf) == 0)
                  {
                    stop = 1;
                    break;
                  }
                }
          //zabawa w identyfikowanie i wypisywanie funkcji, wkladanie dziadostwa na stos, cos tam cos tam do zrobienia
                free(subbuf);
                break;
            case ')':
                if(ignore == 1)
                    continue;
                para_naw_z--;
         /*       if(buf[i+1] == ';')
                {
                  if protyp
			autorskie_funkcje(funkcja_na_stosie) -> gdzie_prototyp = i
			 zdejmij_ze_stosu()
                }
                else
                {
                  if(buf[i+1] == '{')
                  {

			autorskie_funkcje(funkcja_na_stosie) -> def_start = //linia pliku
			break;
                  }
                }*/
                break;
            case '{':
                if(ignore == 1)
                    continue;
                para_naw_k++;
                break;
            case '}':
                if(ignore == 1)
                    continue;
                para_naw_k--;
                break;
            case '/': // jesli wystepuje // lub /* lub kolejny case */ to zakladamy, ze nas nie interesuje
                if(ignore == 1)
                    continue;
                if(buf[i+1] == '/' || buf[i+1] == '*')
                  stop = 1;
                break;
          case '*':
                if(ignore == 1)
                    continue;
                if(buf[i+1] == '/')
                  stop = 1;
                break;
            case '"':
                if(ignore == 0)
                    ignore = 1;
                else
                    ignore = 0;
                break;
            default:
                printf("nic");
                break;
        }
    }

    if(ignore == 1)
      {
        printf("cos jest nie tak z cudzyslowem\n");
        return -1;
      }

    numer_linii++;
  }

  if(para_naw_z != 0)
  {
      fprintf(stderr, "Zwykle nawiasy sie nie zgadzaja!\n");
      return -1;
  }
  if(para_naw_k != 0)
  {
      fprintf(stderr, "Klamrowe nawiasy sie nie zgadzaja!\n");
      return -1;
  }

  return 0;
}

