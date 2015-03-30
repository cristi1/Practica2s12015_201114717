#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void hello(){
    printf("\nHello Cristi :)!\n");
}

void leerArchivo(char nombre[]){
    
}

int main()
{
    arbol *a=malloc(sizeof(arbol));
    char nom[150];
    fflush(stdin);
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", nom);
    fflush(stdin);
    printf("archivo: %s", nom);
    hello();
    return 0;
    
}
