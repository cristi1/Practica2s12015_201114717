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
    printf("\nLista Ordenada: ");
    imprimir(l);
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
