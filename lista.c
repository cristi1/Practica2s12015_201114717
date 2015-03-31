#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void agregar(Lista *l, int valor){
    nodoLs *n=malloc(sizeof(nodoLs));
    n->valor=valor;
    n->sig=NULL;
    if(l->primero==NULL){
        n->id=1;
        n->ant=NULL;
        l->primero=n;
        l->ultimo=n;
    }else{
        n->id=l->ultimo->id+1;
        n->ant=l->ultimo;
        l->ultimo->sig=n;
        l->ultimo=n;
    }
}

void bubbleSort(Lista *l){
    if(l->primero!=NULL){
        
    }
}

void 