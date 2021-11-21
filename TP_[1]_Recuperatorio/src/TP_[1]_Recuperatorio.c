/*
 ============================================================================
 Name        : nuevoTP1.c
 Author      : Juan Poux
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
	int banderaCalculo;
	int salir;

	banderaNumeroUno = 0;
	banderaNumeroDos = 0;
	banderaCalculo = 0;
	do
	{
		puts("   ******* Menu de opciones *******\n");
		if(banderaNumeroUno == 1)
		{
			printf("1) Ingresar el primer operando (A = %.2f)", numeroUno);
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
			if(!banderaNumeroUno)
			{
				system("cls");
				puts("Primero debe ingresar el primer operando!\n");
			}
			else
			{
				PedirFlotanteP(&numeroDos, "Ingrese el segundo operando: ", "Error, ingrese una opcion valida\n", -99999999, 99999999);
				banderaNumeroDos = 1;
				segundoEntero = VerificarSiEsEntero(numeroDos);
				system("cls");
			}
			break;
		case 3:
			if(!banderaNumeroUno || !banderaNumeroDos)
			{
				puts("Primero debe ingresar los 2 operandos!");
			}
			else
			{
				if(Suma(numeroUno, numeroDos, &suma))
				{
					puts("Error en la suma");
				}
				else
				{
					puts("Operacion suma realizada con exito!");
				}
				if(Resta(numeroUno, numeroDos, &resta))
				{
					puts("Error en la resta");
				}
				else
				{
					puts("Operacion resta realizada con exito!");
				}
				if(Multiplicacion(numeroUno, numeroDos, &multiplicacion))
				{
					puts("Error en la resta");
				}
				else
				{
					puts("Operacion multiplicacion realizada con exito!");
				}
				if(numeroDos != 0)
				{
					if(Division(numeroUno, numeroDos, &division))
					{
						puts("Error en la division");
					}
					else
					{
						puts("Operacion division realizada con exito!");
					}
				}
				if(!primerEntero && numeroUno > -1 && numeroUno < 13)
				{
					if(CalcularFactorial(&factorialUno, numeroUno))
					{
						puts("Error en el calculo de factorial con el primer operando");
					}
					else
					{
						puts("Operacion factorial del primer operando realizada con exito!");
					}
				}
				if(!segundoEntero && numeroDos >= 0 && numeroDos < 13)
				{
					if(CalcularFactorial(&factorialDos, numeroDos))
					{
						puts("Error en el calculo de factorial con el segundo operando");
					}
					else
					{
						puts("Operacion factorial del segundo operando realizada con exito!");
					}
				}
				banderaCalculo = 1;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if(!banderaCalculo)
			{
				puts("Primero se deben calcular las operaciones!");
			}
			else
			{
				printf("El resultado de %.2f + %.2f es: %.2f \n", numeroUno, numeroDos, suma);
				printf("El resultado de %.2f - %.2f es: %.2f \n", numeroUno, numeroDos, resta);
				if(!numeroDos)
				{
					puts("No es posible dividir por 0");
				}
				else
				{
					printf("El resultado %.2f / %.2f es %.2f\n", numeroUno, numeroDos, division);
				}
				printf("El resultado de %.2f * %.2f es: %.2f \n", numeroUno, numeroDos, multiplicacion);
				if(!primerEntero && numeroUno > -1 && numeroUno < 13 && !segundoEntero && numeroDos > -1 && numeroDos < 13)
				{
					printf("El factorial de %.2f es %d y El factorial de %.2f es %d\n", numeroUno, factorialUno, numeroDos,
							factorialDos);
				}
				else
				{
					if(!primerEntero && numeroUno > -1 && numeroUno < 13 && (segundoEntero || numeroDos < 0 || numeroDos > 12))
					{
						printf("El factorial de %.2f es %d y no es posible calcular el factorial de %.2f\n",
								numeroUno, factorialUno, numeroDos);
					}
					else
					{
						if(!segundoEntero && numeroDos > -1 && numeroDos < 13 && (primerEntero || numeroUno < 0 || numeroUno > 12))
						{
							printf("No es posible calcular el factorial de %.2f y el factorial de %.2f es %d\n",
									numeroUno, numeroDos, factorialDos);
						}
						else
						{
							puts("No es posible calcular los factoriales.\n");
						}
					}
				}
				banderaNumeroUno = 0;
				banderaNumeroDos = 0;
				banderaCalculo = 0;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			PedirEnteroP(&salir, "1) Salir \n2) Cancelar \nIngrese una opcion: ", "Error, ingreso invalido\n", 1, 2);
			break;
		}
	} while(salir != 1);

	return EXIT_SUCCESS;
}
