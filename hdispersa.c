#include <stdio.h>
#include <stdlib.h>
#include "distribuirHilos.h"
#include "leerMatriz.h"

void imprimirMatriz(int** matriz, int fils, int cols);

int main(int argc, char *argv[])
{
    if(argc > 4)
    {
        int fils = atoi(argv[1]);//atoi convierte argv[1] y argv[2] en enteros
        int cols = atoi(argv[2]);
        int p = atoi(argv[4]);//cantidad de hilos a ejecutar
        int cantElementos;

        int **matrix; //Crea la matriz de enteros
        //int *vector; //vector que contiene la cantidad de numeros por proceso

        matrix = leerMatriz(argv[3], fils, cols); //Guarda en memoria la matriz del archivo

        imprimirMatriz(matrix, fils, cols);

        cantElementos = distribuirHilos(fils, cols, p, matrix);

        printf("Cantidad de Elementos diferentes de cero : %d\n", cantElementos);
        //imprimirVector(vector, p);
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
}