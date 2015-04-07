#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"
#include "lista.h"

void hello(){
    printf("\nHello Cristi :)!\n");
}

void llenarAVL(char nombre[], arbol *avl){
    FILE *archivo;
    char entrada[30];
    int num;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        //printf("<<contenido del archivo>>\n");
        while(feof(archivo)==0){
            fgets(entrada,30,archivo);
            num=atoi(entrada);
            add(avl,num,avl->raiz);
            //printf("%d ",num);            
        }
        //system("PAUSE");
        fclose(archivo);
    }
}

void llenarLista(char nombre[], Lista *list){
    FILE *archivo;
    char entrada[30];
    int num;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        //printf("<<contenido del archivo>>\n");
        while(feof(archivo)==0){
            fgets(entrada,30,archivo);
            num=atoi(entrada);
            agregar(list,num);
            //printf("%d ",num);            
        }
        //system("PAUSE");
        fclose(archivo);
    }
}

int main()
{
    char nom[150];
    arbol *a=malloc(sizeof(arbol));
    Lista *l=malloc(sizeof(Lista));
    Lista *l1=malloc(sizeof(Lista));
    fflush(stdin);
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", nom);
    time_t I_ingArbol,F_ingArbol,I_recArbol,F_recArbol,I_ordBubble,F_ordBubble,I_ordQuick,F_ordQuick;
    double ingArbol,recArbol,ordBubble,ordQuick;
    time(&I_ingArbol);
    llenarAVL(nom,a);           //llenar el arbol
    time(&F_ingArbol);
    ingArbol=difftime(F_ingArbol, I_ingArbol);
    printf("Ingresar Arbol:  %f segundos\n",ingArbol); 
    time(&I_recArbol);
    InOrden(a->raiz);           //recorrido inorden del arbol
    time(&F_recArbol);
    recArbol=difftime(F_recArbol, I_recArbol);
    printf("Recorrer Arbol:  %f segundos\n",recArbol); 
    llenarLista(nom,l);         //llenar lista l -> ordBubble
    llenarLista(nom,l1);        //llenar lista l1-> ordQuick
    time(&I_ordBubble);
    bubbleSort(l);              //ordenamiento por BubbleSort
    time(&F_ordBubble);
    ordBubble=difftime(F_ordBubble, I_ordBubble);
    printf("Ordenado Burbuja:  %f segundos\n",ordBubble);
    time(&I_ordQuick);
    quickSort(l1);               //ordenamiento por QuickSort
    time(&F_ordQuick);
    ordQuick=difftime(F_ordQuick, I_ordQuick);
    printf("Ordenado Burbuja:  %f segundos\n",ordQuick);
    
    hello();
    system("read -p 'presione cualquier tecla para continuar 'var");
    return 0;
    
    
    
    /*agregar(l,56);
    agregar(l,78);
    agregar(l,23);
    agregar(l,45);
    agregar(l,4);
    agregar(l,6);
    agregar(l,3);
    agregar(l,96);
    imprimir(l);
    bubbleSort(l);
    printf("\nLista Ordenada por bubbleSort: ");
    imprimir(l);
    Lista *l1=malloc(sizeof(Lista));
    agregar(l1,1);
    agregar(l1,30);
    agregar(l1,25);
    agregar(l1,2);
    agregar(l1,3);
    agregar(l1,10);
    agregar(l1,50);
    agregar(l1,70);
    agregar(l1,82);
    agregar(l1,96);
    agregar(l1,100);
    printf("\n");
    imprimir(l1);
    printf("\nLista Ordenada por quickSort: ");
    quickSort(l1);
    imprimir(l1);
    char nom[150];
    fflush(stdin);
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", nom);
    fflush(stdin);
    printf("archivo: %s\n", nom);
    leerArchivo(nom);*/
}
