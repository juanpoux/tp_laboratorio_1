#include "Calculos.h"

float Resta (float numeroUno, float numeroDos, float *resultado)
{
	float calculo;
	int retorno;

	retorno = -1;
	if(resultado != NULL)
	{
		retorno = 0;
		calculo = numeroUno - numeroDos;
		*resultado = calculo;
	}
	return retorno;
}

float Multiplicacion (float numeroUno, float numeroDos, float *resultado)
{
	float calculo;
	int retorno;

	retorno = -1;
	if(resultado != NULL)
	{
		retorno = 0;
		calculo = numeroUno * numeroDos;
		*resultado = calculo;
	}
	return retorno;
}

int Division(float numeroUno, float numeroDos, float *resultado)
{
	float calculo;
	int retorno;

	retorno = -1;
	if(resultado != NULL)
	{
		if(numeroUno == 0 || numeroDos == 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
			calculo = numeroUno / numeroDos;
			*resultado = calculo;
		}
	}
	return retorno;
}

int ConvertirFlotanteAEntero(float numeroIngresado)
{
	int retorno;

	if(numeroIngresado - (int)numeroIngresado == 0)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

int CalcularFactorial(int* resultado, int numeroIngresado)
{
	int retorno;
	int factorial;

	factorial = -1;
	if(resultado != NULL)
	{
		retorno = 0;
		if(numeroIngresado == 0)
		{
			numeroIngresado = 1;
			*resultado = numeroIngresado;
		}
		else
		{
			for(int i = factorial; i > 0; i--)
			{
				numeroIngresado = numeroIngresado * i;
			}
			*resultado = numeroIngresado;
		}
	}
	return retorno;
}
