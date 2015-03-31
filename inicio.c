#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"

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
    clock_t i,f;
    i=clock();
    arbol *a=malloc(sizeof(arbol));
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
