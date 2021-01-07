//to bedzie plik spinajacy naglowki
#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>

struct tab_wys
{
	char *nazwa_f;
	int ile_wystapien;
};

struct f
{
	int gdzie_prototyp;
	int def_start;
	int def_koniec;
	int gdzie_uzycie[20];
	char *nazwa;
    struct tab_wys co_wywoluje[20]; //trzymamy wywolania roznych funkcji w jednej funkcji
};

typedef struct StackElement {
    char *data;
    struct stackElement * next;
} StackElement_type;

void analizator_skladni(char *nazwa_pliku);
int push(StackElement_type **top, char *funame);
int pop(StackElement_type **top);
void show(StackElement_type *top);
int rozmiar(StackElement_type *top);

#endif
