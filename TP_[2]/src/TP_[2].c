/*
 ============================================================================
 Name        : tp2_prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "ArrayEmpleados.h"
#include "Input.h"
#define T 7

int SaberSiHayActivos(Empleado listaEmpleados[], int tam);

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int banderaUno;
	int bancoId;
	int orden;
	int opcionInformar;
	int baja;
	Empleado listaEmpleados[T] =
	{
	{ 1, "jUAn caRLOs", "Gomez", 123121, 3, 2 }/*,
	{ 2, "pedro pik", "Gomez", 12312, 1, 2 },
	{ 3, "mariano", "Gomez", 34312, 4, 2 },
	{ 4, "jose", "Gomez", 12312, 2, 2 },
	{ 5, "andres", "avila", 12312, 1, 2 },
	{ 6, "asdas", "asd", 12312, 2, 2 },
	{ 7, "dasdas", "poux", 12312, 1, 2 }*/ };

	banderaUno = 1;//acordarme de modificar
	bancoId = 8;//acordarme de modificar
	//InicializarEmpleados(listaEmpleados, T);

	do
	{
		switch (MenuDeOpciones())
		{
		case 1:
			AltaEmpleados(listaEmpleados, T, &bancoId);
			banderaUno = 1;
			system("cls");
			break;
		case 2:
			if (banderaUno == 1)
			{
				ModificarEmpleado(listaEmpleados, T);
			}
			else
			{
				printf("Error, primero haga la carga de empleados\n");
			}
			system("pause");
			system("cls");
			break;
		case 3:
			if (banderaUno == 1)
			{
				baja = RemoverEmpleado(listaEmpleados, T);
				if (baja == 1)
				{
					printf("Removido con exito!\n");
				}
				else
				{
					if(baja == 2)
					{
						printf("Baja cancelada!\n");
					}
					else
					{
						printf("No existe el ID ingresado\n");
					}
				}
			}
			else
			{
				printf("Error, primero haga la carga de empleados\n");
			}

			banderaUno = SaberSiHayActivos(listaEmpleados, T);
			system("pause");
			system("cls");
			break;
		case 4:

			if (banderaUno == 1)
			{
				PedirEnteroP(&opcionInformar, "Ingrese 1 para ver listado de los empleados ordenados alfabeticamente por Apellido y Sector: \n"
						"Ingrese 2 para ver total y promedio de los salarios, y cuantos empleados superan el salario promedio: ", "ERROR ", 1, 2);
				switch(opcionInformar)
				{
				case 1:
					PedirEnteroP(&orden, "Ingrese 1 para ordenar alfabeticamente de A a Z:\n"
							"Ingrese 2 para ordenar alfabeticamente de Z a A: ",
							"ERROR ", 1, 2);
					OrdenarDobleCriterio(listaEmpleados, T, orden);
					MostrarListaEmpleadoConDescripcionSector(listaEmpleados, T);
					break;
				case 2:
					system("cls");
					MostrarTotalYPromedio(listaEmpleados, T);
					break;
				}
			}
			else
			{
				printf("Error, primero haga la carga de empleados\n");
			}
			system("pause");
			system("cls");
			break;
		case 5:
			PedirEnteroP(&opcion, "Ingrese 1 si desea salir:\nIngrese 2 si desea continuar: ", "Error ", 1, 2);
			system("cls");
			if(opcion == 1)
			{
				printf("=================================================\n "
						"Saliendo... Gracias por usar nuestra aplicacion! \n"
						"=================================================");
				sleep(2);
			}
			break;
		}
	} while (opcion != 1);

	return EXIT_SUCCESS;
}

int SaberSiHayActivos(Empleado listaEmpleados[], int tam)
{
	int retorno;
	int i;

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(i = 0; i < 0; i++)
		{
			if(listaEmpleados[i].isEmpty == OCUPADO)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
