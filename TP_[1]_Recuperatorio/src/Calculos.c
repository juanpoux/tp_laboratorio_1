#include "Calculos.h"

int Suma(float numeroUno, float numeroDos, float *resultado)
{
	float calculo;
	int retorno;

	retorno = -1;
	if(resultado != NULL)
	{
		retorno = 0;
		calculo = numeroUno + numeroDos;
		*resultado = calculo;
	}
	return retorno;
}

int Resta(float numeroUno, float numeroDos, float *resultado)
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

int Multiplicacion(float numeroUno, float numeroDos, float *resultado)
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
		retorno = 0;
		calculo = numeroUno / numeroDos;
		*resultado = calculo;
	}
	return retorno;
}

int CalcularFactorial(int *resultado, float numeroIngresado)
{
	int retorno;
	int factorial;

	retorno = -1;
	if(resultado != NULL)
	{
		factorial = (int) numeroIngresado;
		retorno = 0;
		if(factorial == 0)
		{
			factorial = 1;
		}
		else
		{
			for(int i = factorial - 1; i > 0; i--)
			{
				factorial = factorial * i;
			}
		}
		*resultado = factorial;
	}
	return retorno;
}

int VerificarSiEsEntero(float numero)
{
	int retorno;
	int parteEntera;
	float decimal;
	int resultado;
	retorno = 1;
	parteEntera = (int) numero;
	decimal = numero - parteEntera;
	resultado = decimal * 100;
	if(!resultado)
	{
		retorno = 0;
	}
	return retorno;
}
