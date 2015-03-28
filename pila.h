/* 
 * File:   pila.h
 * Author: clnx
 *
 * Created on 28 de marzo de 2015, 09:09 AM
 */

#ifndef PILA_H
#define	PILA_H
#include "avl.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct nodoPila{
        int direccion;
        nodo *actual;
        struct nodoPila *sig;
        struct nodoPila *ant;
    }nodoP;
    
    typedef struct estrPila{
        nodoP *cima;
    }pila;
    
    void push(pila *p, nodo *actual, int direccion);
    nodoP *pop(pila *p);
    int vacia(pila *p);
    void clear(pila *p);
    int verificarRotacion(pila *p);


#ifdef	__cplusplus
}
#endif

#endif	/* PILA_H */

