/* 
 * File:   lista.h
 * Author: clnx
 *
 * Created on 30 de marzo de 2015, 05:39 PM
 */

#ifndef LISTA_H
#define	LISTA_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct nodoLista{
        int id;
        int valor;
        struct nodoLista *ant;
        struct nodoLista *sig;
    }nodoLs;

    typedef struct ListaDoble{
        nodoLs *primero;
        nodoLs *ultimo;
    }Lista;
    
    void agregar(Lista *l, int valor);
    void bubbleSort(Lista *l);
    void quickSort(Lista *l);
    void imprimir(Lista *l);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTA_H */

