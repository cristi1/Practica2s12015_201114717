#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    printf("\nHello Cristi :)!\n");
    arbol *a=malloc(sizeof(arbol));
    add(a,4,a->raiz);
    add(a,99,a->raiz);

    InOrden(a->raiz);
    printf("\nHello Cristi :)!\n");
    return 0;
}
