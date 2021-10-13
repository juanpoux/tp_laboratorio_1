#include "Input.h"

void CargarVectorEntero(char mensaje[], int listaValores[], int tam, int min, int max)
{
	int i;
	for(i=0; i<tam; i++)
	{
		printf("%s", mensaje);
		scanf("%d", &listaValores[i]);

		while(listaValores[i] < min || listaValores[i] > max)
		{
			printf("Error, ingrese un numero valido entre %d y %d: ", min, max);
			scanf("%d", &listaValores[i]);
		}
	}
}

int PedirCadena(char mensaje[], char cadena[], int tam)
{
	int retorno = 0;

	if (mensaje != NULL && cadena != NULL)
	{
		fflush(stdin);
		printf("%s\n", mensaje);
		scanf("%[^\n]", cadena);
		retorno = 1;
	}

	return retorno;
}

int VerificarLetras(char cadena[])
{
    int i = 0;
    while (cadena[i])
    {
        // Si no es del alfabeto y no es un espacio regresamos 0
        if (!isalpha(cadena[i]) && cadena[i] != ' '// El espacio cuenta como v�lido, si no, simplemente quita la condici�n
                )
        return 0;
        i++;
    }
    // Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1 o true
    return 1;
}

int PedirNombre(char mensaje[], char cadena[], int tam)
{
	int retorno = 0;
	int bandera;

	bandera = 0;

	do
	{
		if(mensaje != NULL && cadena != NULL)
		{
			fflush(stdin);
			printf("%s", mensaje);
			scanf("%[^\n]", cadena);
			retorno = 1;

			if(VerificarLetras(cadena) == 1)
			{
				bandera = 1;
				retorno = 1;
			}
			else
			{
				printf("Error, solo puede ingresar letras.\n");
			}
		}
	}while(bandera == 0);

	return retorno;
}

int MyGets(char* cadena, int tam)
{
	int retorno;

	retorno = 0;

	fflush(stdin);
	fgets(cadena, tam, stdin);
	cadena[strlen(cadena) - 1] = '\0';

	return retorno;
}

int EsEntero(char* cadena)
{
	int retorno;
	int i = 0;

	retorno = 1;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for(;cadena[i] != '\0'; i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int GetInt(int* pResultado)
{
	int retorno = 0;
	char buffer[1000];

	if(MyGets(buffer, sizeof(buffer)) == 0 && EsEntero(buffer) == 1)
	{
		retorno = 1;

		*pResultado = atoi(buffer);
	}

	return retorno;
}

void PedirEnteroP(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int buffer;
	int bandera = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s", mensaje);

			if(GetInt(&buffer) == 1 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				bandera = 1;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(bandera == 0);
	}
}

int EsFloat(char* cadena)
{
	int retorno;
	int i = 0;
	int contadorPuntos = 0;

	retorno = 1;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for(;cadena[i] != '\0'; i++)
	{
		if(cadena[i] == '.')
		{
			contadorPuntos++;
		}
		if(cadena[i] < '.' || cadena[i] > '9' || contadorPuntos > 1 || cadena[0] == '.' || cadena[i] == '/')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int GetFloat(float* pResultado)
{
	int retorno = 0;
	char buffer[1000];

	if(MyGets(buffer, sizeof(buffer)) == 0 && EsFloat(buffer) == 1)
	{
		retorno = 1;

		*pResultado = atof(buffer);
	}

	return retorno;
}

void PedirFlotanteP(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	float buffer;
	int bandera = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s", mensaje);

			if(GetFloat(&buffer) == 1 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				bandera = 1;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(bandera == 0);
	}
}

