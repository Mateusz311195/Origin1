#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "header.h"

#define BUFSIZE 8192
#define MAXLINII 1000
#define MAXSLOW 100

int main(int argc, char *argv[])
{
	int i;
	for(i=1;i <= argc-1; i++)
		analizator_skladni(argv[i]);
	
	return 0;
}
