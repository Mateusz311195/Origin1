#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct StackElement {
    char *data;
    struct stackElement * next;
} StackElement_type;

int push(StackElement_type **top, char *funame);
int pop(StackElement_type **top);
void show(StackElement_type *top);
int rozmiar(StackElement_type *top);

/*int main()
{
    StackElement_type *top;
    top=NULL;

printf("%s\n", top->data);
    push(&top, "f1");
    pop(&top);
    show(top);
    rozmiar(top);
    printf("%s\n", top->data);


    return 0;
}*/

int push(StackElement_type **top, char *funame) {

    if(rozmiar(*top)==MAX_SIZE) {
        printf("\nSTACK OVERFLOW!! Nie mozna dodac elementu do stosu.");
        return 1;
    }

    if(*top==NULL) {
        *top=(StackElement_type *) malloc (sizeof(StackElement_type));
        (*top)->data=funame;
        (*top)->next=NULL;
    }else {
        StackElement_type *newElement;
        newElement=(StackElement_type *)malloc(sizeof(StackElement_type));
        newElement->data=funame;
        newElement->next=*top;
        *top=newElement;
    }
}

int pop(StackElement_type **top) {

    if (*top==NULL) {
      printf("\nSTACK UNDERFLOW!! Nie ma czego zdjac ze stosu.");
	}else {
	 StackElement_type * tmp=NULL;
   	 tmp=(*top)->next;
   	 free(*top);
   	 *top=tmp;
	}
}

void show(StackElement_type *top) {

    printf("\n");
    if(top==NULL) printf("List is empty");
    else {
        StackElement_type *current=top;
        do {
            printf("%s", current->data);
            printf("\n");
            current = current->next;
         }while (current != NULL);

    }
}

int rozmiar(StackElement_type *top) {

    int counter=0;
    StackElement_type *current=top;

    while(current!=NULL)
    {
        counter++;
        current=current->next;
    }

    return counter;
}

