#include <stdio.h>
#include <stdlib.h>

float prctajeElemNoCero(int fils, int cols, int cantElemNoCero);
bool matrizEsDispersa(float prctajeElemNoCero, float prctajeUsuario);

float prctajeElemNoCero(int fils, int cols, int cantElemNoCero)
{
	//Regla de Tres
	//si 100% ----------> fils*cols
	//cantElemNoCero---->   x
	//x = (fils*cols)/cantElemNoCero
	return (fils*cols)/cantElemNoCero; //Retorna el porcentaje de elemntos diferentes de cero que hay
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