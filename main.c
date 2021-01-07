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
	//for(i=1;i <= argc-1; i++)
		//analizator_skladni(argv[i]);
    StackElement_type *top;
    top=NULL;
    push(&top, "f1");
    push(&top, "f2");
    show(top);
    pop(&top);
    push(&top, "f3");
    show(top);

	return 0;
}
