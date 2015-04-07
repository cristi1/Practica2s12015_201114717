#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void escribirArchivo(){
    FILE *fp;
    int num=1;
    fp = fopen ( "pruebas3.txt", "w" );
    while(num != 500000){
        fprintf(fp, "%d \n",num);
        num++;
    }
    fclose ( fp );
}

int main()
{   
    //escribirArchivo();
    char nom[150];
    arbol *a=malloc(sizeof(arbol));
    Lista *l=malloc(sizeof(Lista));
    Lista *l1=malloc(sizeof(Lista));
    fflush(stdin);
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", nom);
    clock_t I_ingArbol,F_ingArbol,I_recArbol,F_recArbol,I_ordBubble,F_ordBubble,I_ordQuick,F_ordQuick;
    double ingArbol,recArbol,ordBubble,ordQuick;
    I_ingArbol= clock();
    llenarAVL(nom,a);                                                    //llenar el arbol
    F_ingArbol = clock();
    ingArbol = (double)(F_ingArbol - I_ingArbol) / CLOCKS_PER_SEC;
    printf("Ingresar Arbol:  %f segundos\n",ingArbol); 
    I_recArbol=clock();
    recInOrden(a->raiz);                                                 //recorrido inorden del arbol
    F_recArbol=clock();
    recArbol = (double)(F_recArbol-I_recArbol) / CLOCKS_PER_SEC;
    printf("Recorrer Arbol:  %f segundos\n",recArbol); 
    llenarLista(nom,l);                                                  //llenar lista l -> ordBubble
    llenarLista(nom,l1);                                              //llenar lista l1-> ordQuick
    I_ordBubble=clock();
    bubbleSort(l);                                                      //ordenamiento por BubbleSort
    F_ordBubble=clock();
    ordBubble=(double)(F_ordBubble-I_ordBubble)/ CLOCKS_PER_SEC;
    printf("Ordenado Burbuja:  %f segundos\n",ordBubble);
    I_ordQuick=clock();
    quickSort(l1);               //ordenamiento por QuickSort
    F_ordQuick=clock();
    ordQuick=(double)(F_ordQuick-I_ordQuick)/ CLOCKS_PER_SEC;
    printf("Ordenado Quicksort:  %f segundos\n",ordQuick);
    fflush(stdin);
    printf("Salida Recorrido Arbol: \n");
    //InOrden(a->raiz);
    fflush(stdin);
    printf("\nSalida Ordenada por BubbleSort: \n");
    //imprimir(l);
    printf("\nSalida Ordenada por QuickSort: \n");
    //imprimir(l1);
    hello();
    system("read -p 'presione cualquier tecla para continuar 'var");
    return 0;
}
