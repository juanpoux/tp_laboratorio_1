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
#define T 1000



int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int banderaUno;
	int bancoId;
	int orden;
	int opcionInformar;
	int baja;
	Empleado listaEmpleados[T]/* =
	{
	{ 1, "jUAn caRLOs", "poux", 123121, 3, OCUPADO },
	{ 2, "pedro", "Gomez", 12312, 1, OCUPADO },
	{ 3, "mariano", "Gomez", 34312, 4, 2 },
	{ 4, "jose", "Gomez", 12312, 2, 2 },
	{ 5, "andres", "avila", 12312, 1, 2 },
	{ 6, "pablo", "fernandez", 12312, 2, 2 },
	{ 7, "ezequiel", "gomez", 12312, 1, 2 } }*/;

	banderaUno = 0;//acordarme de modificar
	bancoId = 1;//acordarme de modificar
	InicializarEmpleados(listaEmpleados, T);

	do
	{
		switch (MenuDeOpciones())
		{
		case 1:
			if(AltaEmpleados(listaEmpleados, T, &bancoId) == 1)
			{
				banderaUno = 1;
				system("cls");
				printf("Empleado cargado en el sistema!\n");
			}
			else
			{
				printf("No hay espacio para agregar mas empleados!\n");
			}
			system("pause");
			system("cls");
			break;
		case 2:
			if (banderaUno != 0)
			{
				if(ModificarEmpleado(listaEmpleados, T) == 0)
				{
					printf("No se encontro ningun empleado activo con ese ID.\n");
				}
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
					printf("Empleado removido con exito!\n");
				}
				else
				{
					if(baja == 2)
					{
						printf("Baja cancelada!\n");
					}
					else
					{
						printf("No se encontro ningun empleado activo con ese ID.\n");
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

			if (banderaUno != 0)
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

