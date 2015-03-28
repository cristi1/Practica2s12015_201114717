#include <stdlib.h>
#include "pila.h"

void push(pila *p,nodo *actual,int direccion){
    nodoP *n=malloc(sizeof(nodoP));
    n->actual=actual;
    n->direccion=direccion;
    n->ant=NULL;
    n->sig=NULL;
    if(p->cima==NULL){
        p->cima=n;
    }else{
        p->cima->sig=n;
        n->ant=p->cima;
        p->cima=n;
    }
}

nodoP *pop(pila *p){
    nodoP *n;
    if(p->cima!=NULL){
        n=p->cima;
        if(p->cima->ant!=NULL){
            p->cima=n->ant;
            p->cima->sig=NULL;
    }
        return n;
        free(n);
    }else{
        return NULL;
    }
}

int vacia(pila *p){
    if(p->cima==NULL){
        return 0;   //pila vacia
    }else{
        return 1;   //pila no vacia
    }
}

void clear(pila *p){
    if(p->cima!=NULL){
        while(p->cima!=NULL){
            nodoP *aux;
            aux=p->cima;
            p->cima=aux->ant;
            free(aux);
        }
    }
}

int verificarRotacion(pila *p){
    nodoP *aux, *aux1, *aux2; 
    aux=p->cima;
    aux1=aux->ant;
    aux2=aux1->ant;
    if(aux1->direccion==1){
        if(aux2->direccion==1){
            return 11;   //rot II
        }else{
            return 12;   //rot ID
        }
    }else{
        if(aux2->direccion==2){
            return 22;   //rot DD
        }else{
            return 21;   //rot DI
        }
    }
    
}

