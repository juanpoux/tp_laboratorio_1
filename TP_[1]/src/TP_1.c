/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include <unistd.h>
#include <ctype.h>

int main(void)
{
	setbuf(stdout, NULL);

	float numeroUno;
	int banderaNumeroUno;
	float numeroDos;
	int banderaNumeroDos;
	int opcion;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float factorialUno;
	float factorialDos;

	banderaNumeroUno = 0;
	banderaNumeroDos = 0;

	do
	{
		printf("Ingrese la opcion deseada:\n\n");
		if(banderaNumeroUno == 1)
		{
			printf("1) Ingresar el primer operando: %.2f", numeroUno);
		}
		else
		{
			printf("1) Ingresar el primer operando: ");
		}

		if(banderaNumeroDos == 1)
		{
			printf("\n2) Ingresar el segundo operando: %.2f", numeroDos);
		}
		else
		{
			printf("\n2) Ingresar el segundo operando: ");
		}
		printf("\n3) Calcular todas las operaciones: ");
		printf("\n4) Informar resultados: ");
		printf("\n5) Salir: \n");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			numeroUno = PedirFlotantee("Ingrese el primer operando: ", -1000, 1000);
			banderaNumeroUno = 1;
			system("cls");
			break;
		case 2:
			numeroDos = PedirFlotantee("Ingrese el segundo operando: ", -1000, 1000);
			banderaNumeroDos = 1;
			system("cls");
			break;
		case 3:
			suma = Suma(numeroUno, numeroDos);
			resta = Resta(numeroUno, numeroDos);
			multiplicacion = Multiplicacion(numeroUno, numeroDos);
			division = Division(numeroUno, numeroDos);
			factorialUno = CalcularFactorial(numeroUno);
			factorialDos = CalcularFactorial(numeroDos);
			printf("Operaciones calculadas con exito!!\n\n");
			system("pause");
			system("cls");
			break;
		case 4:
			printf("Informe de resultados:\n\n");
			printf("a) La suma de %.2f + %.2f es: %.2f", numeroUno, numeroDos, suma);
			printf("\nb) La resta de %.2f - %.2f es %.2f", numeroUno, numeroDos, resta);
			if (numeroUno == 0 || numeroDos == 0)
			{
				printf("\nd) No es posible dividir por 0");
			}
			else
			{
				printf("\nc) La division de %.2f / %.2f es %.2f", numeroUno, numeroDos, division);
			}
			printf("\nd) La multiplicacion de %.2f * %.2f es %.2f\n", numeroUno, numeroDos, multiplicacion);
			if(ConvertirFlotanteAEntero(numeroUno) == 0 || numeroUno < 0 || numeroUno > 12)
			{
				printf("e) Primer operando: Solo se calcula factorial de numeros enteros, positivos y menores a 13\n");
			}
			else
			{
				printf("e) Primer Operando: El factorial de %.2f es: %.2f\n", numeroUno, factorialUno);
			}

			if(ConvertirFlotanteAEntero(numeroDos) == 0 || numeroDos < 0 || numeroDos > 12)
			{

				printf("e) Segundo Operando: Solo se calcula factorial de numeros enteros, positivos y menores a 13\n");
			}
			else
			{
				printf("e) Segundo Operando: El factorial de %.2f es: %.2f\n\n", numeroDos, factorialDos);
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			printf("Saliendo... Gracias por usar la aplicacion!!\n\n\n");
			sleep(2);
			break;
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
