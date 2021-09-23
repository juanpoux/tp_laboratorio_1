#include "Biblioteca.h"

float PedirFlotantee(char mensaje [], int minimo, int maximo)
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("Error, ingrese de nuevo: ");
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

float Suma (float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

float Resta (float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

float Multiplicacion (float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

float Division (float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
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
int CalcularFactorial(int numeroIngresado)

{
	int factorial;

	if(numeroIngresado==0)
	{
		factorial = 1;
	}
	else
	{
		factorial = numeroIngresado * CalcularFactorial(numeroIngresado - 1);
	}

	return factorial;
}
