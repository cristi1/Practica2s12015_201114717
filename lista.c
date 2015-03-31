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
        int n=l->ultimo->id, act, sig;
        nodoLs *aux,*aux1,*auxu;
        aux=l->primero;
        auxu=l->ultimo;
        for(int i=1;i<=n;i++){
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
        }
    }
    
    void imprimir(Lista *l){
        
    }
}