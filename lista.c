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
        int act, sig;
        nodoLs *aux,*aux1,*auxu;
        aux=l->primero;
        auxu=l->ultimo;
        while(aux!=auxu){
            while(aux!=auxu){
                aux1=aux->sig;
                act=aux->valor;
                sig=aux1->valor;
                if(act>sig){
                    aux->valor=sig;
                    aux1->valor=act;
                }
                aux=aux->sig;
            }
            auxu=auxu->ant;
            aux=l->primero;
        }
    }
}
    
void imprimir(Lista *l){
    nodoLs *p;
    if(l->primero!=NULL){
        p=l->primero;
        while(p!=NULL){
            printf("%d ",p->valor);
            p=p->sig;
        }
    }
}