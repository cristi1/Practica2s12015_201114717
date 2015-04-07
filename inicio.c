#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "avl.h"
#include "lista.h"

void hello(){
    printf("\nHello Cristi :)!\n");
}

int llenarAVL(char nombre[], arbol *avl){
    FILE *archivo;
    char entrada[30];
    int num;
    int cant=0;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        //printf("<<contenido del archivo>>\n");
        while(feof(archivo)==0){
            fgets(entrada,30,archivo);
            num=atoi(entrada);
            add(avl,num,avl->raiz);
            cant++;
            //printf("%d ",num);            
        }
        //system("PAUSE");
        fclose(archivo);
    }
    return cant;
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

void grafica(int n,double time_ingreso, double time_recArbol, double time_buble, double time_quick){
    
    char a_Plotear[80];
    char pendiente_avl[15];
    char cant_datos[15];
// Conversion a char las variables
   sprintf(pendiente_avl, "%f", time_ingreso);
   sprintf(cant_datos, "%i", n);
// comando para "Plotear"
    strcpy(a_Plotear, "gnuplot -p -e \"plot [0:");
    strcat(a_Plotear, pendiente_avl);
    strcat(a_Plotear, "][0:");
    strcat(a_Plotear, cant_datos);
    strcat(a_Plotear, "] ");
    strcat(a_Plotear, cant_datos);
    strcat(a_Plotear, "*x/");
    strcat(a_Plotear, pendiente_avl);
    strcat(a_Plotear, " title 'Inserccion en AVL'\"");
    system(a_Plotear);
    //getchar();

    //InOrden
    char a_Plotear2[80];
    char pendiente_inorden[15];
    sprintf(pendiente_inorden, "%f", time_recArbol);
    strcpy(a_Plotear2, "gnuplot -p -e \"plot [0:");
    strcat(a_Plotear2, pendiente_inorden);
    strcat(a_Plotear2, "][0:");
    strcat(a_Plotear2, cant_datos);
    strcat(a_Plotear2, "] ");
    strcat(a_Plotear2, cant_datos);
    strcat(a_Plotear2, "*x/");
    strcat(a_Plotear2, pendiente_inorden);
    strcat(a_Plotear2, " title 'Recorrido EnOrden'\"");
    system(a_Plotear2);
    //burbuja
    char a_Plotear3[80];
    char pendiente_bubble[15];
    sprintf(pendiente_bubble, "%f", time_buble);
    strcpy(a_Plotear3, "gnuplot -p -e \"plot [0:");
    strcat(a_Plotear3, pendiente_bubble);
    strcat(a_Plotear3, "][0:");
    strcat(a_Plotear3, cant_datos);
    strcat(a_Plotear3, "] ");
    strcat(a_Plotear3, cant_datos);
    strcat(a_Plotear3, "*x/");
    strcat(a_Plotear3, pendiente_bubble);
    strcat(a_Plotear3, " title 'Ordenamiento BubbleSort'\"");
    system(a_Plotear3);
    //quicksort
    char a_Plotear4[80];
    char pendiente_quick[15];
    sprintf(pendiente_quick, "%f", time_quick);
    strcpy(a_Plotear4, "gnuplot -p -e \"plot [0:");
    strcat(a_Plotear4, pendiente_quick);
    strcat(a_Plotear4, "][0:");
    strcat(a_Plotear4, cant_datos);
    strcat(a_Plotear4, "] ");
    strcat(a_Plotear4, cant_datos);
    strcat(a_Plotear4, "*x/");
    strcat(a_Plotear4, pendiente_quick);
    strcat(a_Plotear4, " title 'Ordenamiento QuickSort'\"");
    system(a_Plotear4);
}

int main()
{   
    //escribirArchivo();
    char nom[150];
    int n=0;
    arbol *a=malloc(sizeof(arbol));
    Lista *l=malloc(sizeof(Lista));
    Lista *l1=malloc(sizeof(Lista));
    fflush(stdin);
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", nom);
    clock_t I_ingArbol,F_ingArbol,I_recArbol,F_recArbol,I_ordBubble,F_ordBubble,I_ordQuick,F_ordQuick;
    double ingArbol,recArbol,ordBubble,ordQuick;
    I_ingArbol= clock();
    n=llenarAVL(nom,a);                                                    //llenar el arbol
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
    hello();
    grafica(n,ingArbol, recArbol, ordBubble,ordQuick);
    system("read -p 'presione cualquier tecla para continuar 'var");
    return 0;
}
