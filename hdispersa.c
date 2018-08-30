#include <stdio.h>
#include <stdlib.h>
#include "leerMatriz.h"
#include "distribuirHilos.h"
#include "dispersa.h"

void imprimirMatriz(int** matriz, int fils, int cols);

int main(int argc, char *argv[])
{
    if(argc > 4)
    {
        int fils = atoi(argv[1]);//atoi convierte argv[1] y argv[2] en enteros
        int cols = atoi(argv[2]);
        int p = atoi(argv[4]);//cantidad de hilos a ejecutar
        float prctajeUsuario = atof(argv[5]);
        float porcentElemNoCero;
        int cantElemNoCero = 0;


        int **matrix; //Crea la matriz de enteros
        //int *vector; //vector que contiene la cantidad de numeros por proceso

        matrix = leerMatriz(argv[3], fils, cols); //Guarda en memoria la matriz del archivo

        imprimirMatriz(matrix, fils, cols);

        cantElemNoCero = distribuirHilos(fils, cols, p, matrix);

        printf("Cantidad de Elementos diferentes de cero : %d\n\n", cantElemNoCero);

        porcentElemNoCero = prctajeElemNoCero(fils, cols, cantElemNoCero);
        
        if(matrizEsDispersa(porcentElemNoCero, prctajeUsuario))
        {
            printf("El Usuario exigio %f%, y el prctajeCeros es %f%", prctajeUsuario, 100 - porcentElemNoCero);
            printf("La matriz SI es dispersa\n");            
        }
        else
        {
            printf("El Usuario exigio %f%, y el prctajeCeros es %f%", prctajeUsuario, 100 - porcentElemNoCero);
            printf("La matriz NO es dispersa\n");    
        }

    }
    else
    {
        perror("ERROR       Verifique: ./pdispersa M N archivo nprocesos porcentaje\n");
    }

    return 0;
}


void imprimirMatriz(int** matriz, int fils, int cols)
{
    for(int i = 0; i < fils; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}