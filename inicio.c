#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "avl.h"
#include "lista.h"
# include <math.h>

void hello(){
    printf("\n\nHello Cristi :)!\n");
}

void llenarAVL(char nombre[], arbol *avl){
    FILE *archivo;
    char entrada[50];
    int num;
    int cant=0;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        //printf("<<contenido del archivo>>\n");
        while(feof(archivo)==0){
            fgets(entrada,50,archivo);
            num=atoi(entrada);
            add(avl,num,avl->raiz);
            cant++;
            //printf("%d ",num);            
        }
        //system("PAUSE");
        fclose(archivo);
    }
}

/*void llenarLista(char nombre[], Lista *list){
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
}*/

void llenarArray(int lista[],int tam,char nombre[]){
    FILE *archivo;
    char entrada[30];
    int num=0,i=0;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        while(feof(archivo)==0 && i<tam){
            fgets(entrada,30,archivo);
            num=atoi(entrada);
            lista[i]=num;
            //printf("[%d , %d]",num,i);  
            i++;
        }
        //system("PAUSE");
        fclose(archivo);
         }   
}

void recorrerArray(int lista[],int tam){
    int i=0;
    do{
       printf(" %d",lista[i]); 
       i++;
    }
    while(i<tam);
}

int contarDatos(char nombre[]){
    FILE *archivo;
    char entrada[30];
    int num=-1;
    archivo=fopen(nombre,"r");
    if(archivo==NULL){
        exit(1);
    }else{
        while(feof(archivo)==0){
            fgets(entrada,30,archivo);
            num++;
        }
        //system("PAUSE");
        fclose(archivo);
         printf("<<< el archivo contiene %d datos>>>\n",num);
    }
    return num;
}

void escribirArchivo(){
    FILE *fp;
    int num=1;
    fp = fopen ( "pruebas4.txt", "w" );
    while(num != 300){
        fprintf(fp, "%d \n",num);
        num++;
    }
    fclose ( fp );
}

void graficas(int n,double time_ingreso, double time_recArbol, double time_buble, double time_quick){

    char pendiente_avl[15];
    char cant_datos[15];
    sprintf(pendiente_avl, "%f", time_ingreso);
    sprintf(cant_datos, "%i", n);
    FILE *fp;                            
    fp = fopen ( "InsercionArbol.gplot", "w" );  
    fprintf ( fp, "plot [0:");
    fprintf(fp,"%s",cant_datos);
    fprintf(fp,"][0:");
    fprintf(fp,"%s",pendiente_avl);
    fprintf(fp,"] ");
    fprintf(fp,"%s",pendiente_avl);
    fprintf(fp,"*x/");
    fprintf(fp,"%s",cant_datos);
    fprintf(fp,",log10(");
    fprintf(fp,"%s",cant_datos);
    fprintf(fp,")*0.000001");
    fprintf(fp," title 'Inserccion en AVL log(n)'\n");     
    fprintf ( fp, "pause mouse \n" );    
    fclose ( fp );                       
    system("gnuplot InsercionArbol.gplot");
    
    char pendiente_inorden[15];
    sprintf(pendiente_inorden, "%f", time_recArbol);
    FILE *fp1;                            
    fp1 = fopen ( "RecorridoArbol.gplot", "w" );  
    fprintf ( fp1, "plot [0:");
    fprintf(fp1,"%s",cant_datos);
    fprintf(fp1,"][0:");
    fprintf(fp1,"%s",pendiente_inorden);
    fprintf(fp1,"] ");
    fprintf(fp1,"%s",pendiente_inorden);
    fprintf(fp1,"*x/");
    fprintf(fp1,"%s",cant_datos);
    fprintf(fp1," title 'Recorrido AVL'\n");     
    fprintf(fp1, "pause mouse \n" );    
    fclose (fp1);                       
    system("gnuplot RecorridoArbol.gplot");
    
    char pendiente_bubble[15];
    sprintf(pendiente_bubble, "%f", time_buble);
    FILE *fp2;                            
    fp2 = fopen("Bubble.gplot", "w" );  
    fprintf(fp2, "plot [0:");
    fprintf(fp2,"%s",cant_datos);
    fprintf(fp2,"][0:");
    fprintf(fp2,"%s",pendiente_bubble);
    fprintf(fp2,"] ");
    fprintf(fp2,"%s",pendiente_bubble);
    fprintf(fp2,"*x/");
    fprintf(fp2,"%s",cant_datos);
    fprintf(fp2,",");
    fprintf(fp2,"%s",cant_datos);
    fprintf(fp2,"*");
    fprintf(fp2,"%s*0.000001",cant_datos);
    fprintf(fp2," title 'BubbleSort n*n'\n");     
    fprintf(fp2, "pause mouse \n" );    
    fclose (fp2);                       
    system("gnuplot Bubble.gplot");
    
    char pendiente_quick[15];
    sprintf(pendiente_quick, "%f", time_quick);
    FILE *fp3;                            
    fp3 = fopen("Quick.gplot", "w" );  
    fprintf(fp3, "plot [0:");
    fprintf(fp3,"%s",cant_datos);
    fprintf(fp3,"][0:");
    fprintf(fp3,"%s",pendiente_quick);
    fprintf(fp3,"] ");
    fprintf(fp3,"%s",pendiente_quick);
    fprintf(fp3,"*x/");
    fprintf(fp3,"%s",cant_datos);
    fprintf(fp2,",");
    fprintf(fp2,"%s",cant_datos);
    fprintf(fp2,"*");
    fprintf(fp,"log10(");
    fprintf(fp,"%s",cant_datos);
    fprintf(fp,")*0.000001");
    fprintf(fp3," title 'QuickSort n log n'\n");     
    fprintf(fp3, "pause mouse \n" );    
    fclose (fp3);                       
    system("gnuplot Quick.gplot");
}

int main()
{   
    //escribirArchivo();
    arbol *a=malloc(sizeof(arbol));
    clock_t I_ingArbol,F_ingArbol,I_recArbol,F_recArbol,I_ordBubble,F_ordBubble,I_ordQuick,F_ordQuick;
    double ingArbol,recArbol,ordBubble,ordQuick;
    char nom[150];
    int numDatos=0;
    printf("\nIngrese el nombre del archivo: ");
    scanf("%s", nom);
    numDatos=contarDatos(nom);
    //algoritmo quickSort con array
    int lista[numDatos];
    int lista1[numDatos];
    llenarArray(lista,numDatos,nom);
    I_ordQuick=clock();
    quickSort(lista,numDatos);
    F_ordQuick=clock();
    ordQuick=(double)(F_ordQuick-I_ordQuick)/ CLOCKS_PER_SEC;
    printf("\nOrdenado Quicksort:  %f segundos\n",ordQuick);
    //algoritmo bubblesort con array
    llenarArray(lista1,numDatos,nom);
    I_ordBubble=clock();
    bubbleSort(lista1,numDatos);
    F_ordBubble=clock();
    ordBubble=(double)(F_ordBubble-I_ordBubble)/ CLOCKS_PER_SEC;
    printf("Ordenado Burbuja:    %f segundos\n",ordBubble);
    printf("\nRecorrido QuickSort: \n");
    recorrerArray(lista,numDatos);
    printf("\nRecorrido BubbleSort: \n");
    recorrerArray(lista1,numDatos);
    //AVL
    I_ingArbol= clock();
    llenarAVL(nom,a);                                                    
    F_ingArbol = clock();
    ingArbol = (double)(F_ingArbol - I_ingArbol) / CLOCKS_PER_SEC;
    printf("\n\nIngresar Arbol:      %f segundos\n",ingArbol); 
    I_recArbol=clock();
    recInOrden(a->raiz);                                                 
    F_recArbol=clock();
    recArbol = (double)(F_recArbol-I_recArbol) / CLOCKS_PER_SEC;
    printf("Recorrer Arbol:      %f segundos\n",recArbol); 
    printf("\nRecorrido Arbol AVL: \n");
    InOrden(a->raiz);

 
    /*int n=0;
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
   /* I_recArbol=clock();
    recInOrden(a->raiz);                                                 //recorrido inorden del arbol
    F_recArbol=clock();
    recArbol = (double)(F_recArbol-I_recArbol) / CLOCKS_PER_SEC;
    printf("Recorrer Arbol:  %f segundos\n",recArbol); 
    llenarLista(nom,l);                                                  //llenar lista l -> ordBubble
    printf("----------------------------------------------------\n");
    llenarLista(nom,l1);                                              //llenar lista l1-> ordQuick
    I_ordBubble=clock();
    printf("Ordenado Burbuja--------------------------------------\n");
    bubbleSort(l);                                                      //ordenamiento por BubbleSort
    F_ordBubble=clock();
    ordBubble=(double)(F_ordBubble-I_ordBubble)/ CLOCKS_PER_SEC;
    printf("Ordenado Burbuja:  %f segundos\n",ordBubble);
    I_ordQuick=clock();
    printf("Ordenado QuickSort--------------------------------------\n");
    quickSort(l1);               //ordenamiento por QuickSort
    F_ordQuick=clock();
    ordQuick=(double)(F_ordQuick-I_ordQuick)/ CLOCKS_PER_SEC;
    printf("Ordenado Quicksort:  %f segundos\n",ordQuick);*/
    hello();
    graficas(numDatos,ingArbol, recArbol, ordBubble,ordQuick);
    system("read -p 'presione cualquier tecla para continuar 'var");
    return 0;
}
