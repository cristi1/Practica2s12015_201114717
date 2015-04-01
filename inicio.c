#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"
#include "lista.h"

void hello(){
    printf("\nHello Cristi :)!\n");
}

void leerArchivo(char nombre[]){
    FILE *archivo;
    char entrada[30];
    int num;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        printf("<<contenido del archivo>>\n");
        while(feof(archivo)==0){
            fgets(entrada,30,archivo);
            num=atoi(entrada);
            printf("%d ",num);            
        }
        //system("PAUSE");
        fclose(archivo);
    }
}

int main()
{
    //clock_t i,f;
    //i=clock();
    //arbol *a=malloc(sizeof(arbol));
    Lista *l=malloc(sizeof(Lista));
    agregar(l,56);
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
    leerArchivo(nom);
    hello();
    system("read -p 'presione cualquier tecla para continuar 'var");
    return 0;
    
}
