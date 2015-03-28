#include <stdlib.h>
#include "avl.h"
#include "pila.h"

int i=0, d=0, fe=0;
pila *p;

void recorridoInOrden(nodo *raiz){
    
}

void ii(arbol *avl, nodo *n, nodo *n1){
    nodo *padre, *aux;
    padre=n->padre;
    aux=n;
    n->Hizq=n1->Hder;
    if(n->Hizq!=NULL){
        n->Hizq->padre=n;
    }
    n1->Hder=n;
    n->padre=n1;
    if(padre==NULL){
        avl->raiz=n1;
    }else{
        if(aux==padre->Hizq){
            padre->Hizq=n1;
        }else{
            padre->Hder=n1;
        }
        n1->padre=padre;
    }
}

void dd(arbol *avl, nodo *n, nodo *n1){
    nodo *padre, *aux;
    padre=n->padre;
    aux=n;
    n->Hder=n1->Hizq;
    if(n->Hder!=NULL){
        n->Hder->padre=n;
    }
    n1->Hizq=n;
    n->padre=n1;
    if(padre==NULL){
        avl->raiz=n1;
    }else{
        if(aux==padre->Hizq){
            padre->Hizq=n1;
        }else{
            padre->Hder=n1;
        }
        n1->padre=padre;
    }
}
        
void id(arbol *avl, nodo *n, nodo *n1, nodo *n2){
    nodo *padre, *aux;
    padre=n->padre;
    aux=n;
    n1->Hder=n2->Hizq;
    if(n1->Hder!=NULL){
        n1->Hder->padre=n1;
    }
    n2->Hizq=n1;
    n1->padre=n2;
    n->Hizq=n2->Hder;
    if(n->Hizq!=NULL){
        n->Hizq->padre=n;
    }
    n2->Hder=n;
    n->padre=n2;
    if(padre==NULL){
        avl->raiz=n2;
    }else{
        if(aux==padre->Hizq){
            padre->Hizq=n2;
        }else{
            padre->Hder=n2;
        }
        n2->padre=padre;
    }
}

void di(arbol *avl, nodo *n, nodo *n1, nodo *n2){
    nodo *padre, *aux;
    padre=n->padre;
    aux=n;
    n1->Hizq=n2->Hder;
    if(n1->Hizq!=NULL){
        n1->Hizq->padre=n1;
    }
    n2->Hder=n1;
    n1->padre=n2;
    n->Hder=n2->Hizq;
    if(n->Hder!=NULL){
        n->Hder->padre=n;
    }
    n2->Hizq=n;
    n->padre=n2;
    if(padre==NULL){
        avl->raiz=n2;
    }else{
        if(aux==padre->Hizq){
            padre->Hizq=n2;
        }else{
            padre->Hder=n2;
        }
        n2->padre=padre;
    }
}

void equilibrar(arbol *avl, int r, nodo *n, nodo *n1, nodo *n2){ //tipo de equilibrio a realizar
    switch(r){
        case 11:
            ii(avl,n,n1);
            break;
        case 22:
            dd(avl,n,n1);
            break;
        case 12:
            id(avl,n,n1,n2);
            break;
        case 21:
            di(avl,n,n1,n2);
            break;
    }
}

void verificarEquilibrio(arbol *avl, nodo *hoja){
    nodo *padre;
    nodoP *n, *n1, *n2;
    int r=0;
    if(hoja!=avl->raiz){
        padre=hoja->padre;
        if(hoja==padre->Hizq){
            push(p,hoja,1);
        }else{
            push(p,hoja,2);
        }
        fe=padre->d - padre->i;
        if(fe<-1 || fe>1){
            push(p,padre,0);
            r=verificarRotacion(p);
            n=pop(p);
            n1=pop(p);
            n2=pop(p);
            equilibrar(avl,r,n->actual,n1->actual,n2->actual);
            clear(p);
        }else{
            verificarEquilibrio(avl,padre);
        }
    }else{
        clear(p);
    }
}

int factorEquilibrio(nodo *raiz){ //calcula factores de equilibrio para cada nodo del arbol
    if(raiz==NULL){
        return 0;
    }else{
        i=factorEquilibrio(raiz->Hizq)+1;
        d=factorEquilibrio(raiz->Hder)+1;
    }
    raiz->i=i;
    raiz->d=d;
    fe=d-i;
    raiz->fe=fe;
    if(i>d){
        return i;
    }else{
        return d;
    }
}

void add(arbol *avl, int valor, nodo *padre){ //adhiere un nuevo nodo al arbol
    if(avl->raiz==NULL){
        nodo *n=malloc(sizeof(nodo));
        n->valor=valor;
        n->padre=NULL;
        n->Hizq=NULL;
        n->Hder=NULL;
        avl->raiz=n;
    }else if(valor<padre->Hizq->valor){
        if(padre->Hizq==NULL){
            nodo *n=malloc(sizeof(nodo));
            n->valor=valor;
            n->padre=padre;
            n->Hizq=NULL;
            n->Hder=NULL;
            factorEquilibrio(avl->raiz);
        }else{
            add(avl,valor,padre->Hizq);
        }
    }else if(valor>padre->Hder->valor){
        if(padre->Hder==NULL){
            nodo *n=malloc(sizeof(nodo));
            n->valor=valor;
            n->padre=padre;
            n->Hizq=NULL;
            n->Hder=NULL;
            factorEquilibrio(avl->raiz);
        }else{
            add(avl,valor,padre->Hder);
        }
    }
}

