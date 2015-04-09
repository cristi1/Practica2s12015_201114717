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

/*void bubbleSort(Lista *l){////metodo para ordenar con bubblesort
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
}*/

void bubbleSort(int lista[],int tam){
    int i,j,act,sig;
    i=0;
    j=tam-1;
    while(i!=j){
        while(i!=j){
            act=lista[i];
            sig=lista[i+1];
            if(act>sig){
                lista[i]=sig;
                lista[i+1]=act;
            }
            i++;
        }
        j--;
        i=0;
    }
}

/*void quickSort(Lista *l){
    qs(l->primero,l->ultimo);
}

void qs(nodoLs *izq, nodoLs *der){//metodo para ordenar con quicksort
    if(izq!=der){
        nodoLs *i, *d, *temp;
        int pivote;
        i=izq;
        d=der;
        temp=izq;
        pivote=izq->valor;
        while(i!=d){
            if(i==temp){
                if(d->valor<pivote){
                    i->valor=d->valor;
                    i=i->sig;
                    temp=d;
                }else{
                    d=d->ant;
                }
            }else if(d==temp){
                if(i->valor>pivote){
                    d->valor=i->valor;
                    d=d->ant;
                    temp=i;
                }else{
                    i=i->sig;
                }
            }
        }
        i->valor=pivote;
        if(i->ant!=izq && i->ant!=NULL && i!=izq){
            qs(izq,i->ant);
        }
        if(i->sig!=der && i->sig!=NULL && i!=der){
            qs(i->sig,der);
        }
    }
}*/

void qs(int lista[],int limite_izq,int limite_der){
    int izq,der,temporal,pivote;
    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2];
    
    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;
        }
    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}
}

void quickSort(int lista[],int n){
    qs(lista,0,n-1);
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