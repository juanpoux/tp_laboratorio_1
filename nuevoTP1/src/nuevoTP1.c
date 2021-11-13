/*
 ============================================================================
 Name        : nuevoTP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

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
	int factorialUno;
	int factorialDos;
	int primerEntero;
	int segundoEntero;

	banderaNumeroUno = 0;
	banderaNumeroDos = 0;
	do
	{
		if(banderaNumeroUno == 1)
		{
			printf("1)Ingresar el primer operando (A = %.2f)", numeroUno);
		}
		else
		{
			printf("1) Ingresar el primer operando (A = x)");
		}

		if(banderaNumeroDos == 1)
		{
			printf("\n2) Ingresar el segundo operando (B = %.2f)", numeroDos);
		}
		else
		{
			printf("\n2) Ingresar el segundo operando (B = y)");
		}
		printf("\n3) Calcular todas las operaciones "
				"\n4) Informar resultados \n5) Salir \n");
		PedirEnteroP(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion valida\n", 1, 5);

		switch(opcion)
		{
		case 1:
			PedirFlotanteP(&numeroUno, "Ingrese el primer operando: ", "Error, ingrese una opcion valida\n", -99999999, 99999999);
			banderaNumeroUno = 1;
			primerEntero = VerificarSiEsEntero(numeroUno);
			system("cls");
			break;
		case 2:
			PedirFlotanteP(&numeroDos, "Ingrese el segundo operando: ", "Error, ingrese una opcion valida\n", -99999999, 99999999);
			banderaNumeroDos = 1;
			segundoEntero = VerificarSiEsEntero(numeroDos);
			system("cls");
			break;
		case 3:
			if(Suma(numeroUno, numeroDos, &suma))
			{
				puts("Error en la suma");
			}
			if(Resta(numeroUno, numeroDos, &resta))
			{
				puts("Error en la resta");
			}
			if(Multiplicacion(numeroUno, numeroDos, &multiplicacion))
			{
				puts("Error en la resta");
			}
			if(Division(numeroUno, numeroDos, &division))
			{
				puts("Error en la division");
			}
			if(CalcularFactorial(&factorialUno, numeroUno))
			{
				puts("Error en el calculo de factorial con el primer numero");
			}
			if(CalcularFactorial(&factorialDos, numeroDos))
			{
				puts("Error en el calculo de factorial con el segundo numero");
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if(!numeroDos)
			{
				puts("No es posible dividir por 0");
			}
			else
			{
				printf("d) La division de %.2f / %.2f es %.2f\n", numeroUno, numeroDos, division);
			}
			if(!primerEntero && numeroUno >= 0 && numeroUno < 13)
			{
				printf("e) El factorial del numero %.2f es %d\n", numeroUno, factorialUno);
			}
			else
			{
				printf("e) No es posible calcular el factorial de %.2f\n", numeroUno);
			}
			if(!segundoEntero && numeroDos >= 0 && numeroDos < 13)
			{
				printf("e) El factorial del numero %.2f es %d\n", numeroDos, factorialDos);
			}
			else
			{
				printf("e) No es posible calcular el factorial de %.2f\n", numeroDos);
			}
			banderaNumeroUno = 0;
			banderaNumeroDos = 0;
			system("pause");
			system("cls");
			break;
		}
	} while(opcion != 5);

	return EXIT_SUCCESS;
}
