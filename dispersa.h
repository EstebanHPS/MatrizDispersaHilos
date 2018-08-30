#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float prctajeElemNoCero(int fils, int cols, int cantElemNoCero);
bool matrizEsDispersa(float prctajeElemNoCero, float prctajeUsuario);

float prctajeElemNoCero(int fils, int cols, int cantElemNoCero)
{
	//Regla de Tres
	//si 100% ----------> fils*cols
	//   x    ---------->CantElemNoCero
	//x = (fils*cols)/cantElemNoCero
	return (100*cantElemNoCero)/(fils*cols); //Retorna el porcentaje de elemntos diferentes de cero que hay
}

bool matrizEsDispersa(float prctajeElemNoCero, float prctajeUsuario)
{
	float prctajeCeros = 100 - prctajeElemNoCero;

	if(prctajeCeros >= prctajeUsuario)
	{
		return true;
	}
	else
	{
		return false;
	}
}