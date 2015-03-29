/* 
 * File:   avl.h
 * Author: clnx
 *
 * Created on 28 de marzo de 2015, 09:09 AM
 */

#ifndef AVL_H
#define	AVL_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct nodoAVL{
        int valor;
        int i;
        int d;
        int fe;
        struct nodoAVL *Hizq;
        struct nodoAVL *Hder;
        struct nodoAVL *padre;
    }nodo;

    typedef struct arbolAVL{
        nodo *raiz;
    }arbol;
    
    void add(arbol *avl, int valor, nodo *padre);
    int factorEqulibrio(nodo *raiz);
    void verificarEquilibrio(arbol *avl, nodo *hoja);
    void equilibrar(arbol *avl, int rotacion, nodo *n, nodo *n1, nodo *n2);
    void ii(arbol *avl, nodo *n, nodo *n1);
    void dd(arbol *avl, nodo *n, nodo *n1);
    void id(arbol *avl, nodo *n, nodo *n1, nodo *n2);
    void di(arbol *avl, nodo *n, nodo *n1, nodo *n2);
    void InOrden(nodo *raiz);


#ifdef	__cplusplus
}
#endif

#endif	/* AVL_H */

