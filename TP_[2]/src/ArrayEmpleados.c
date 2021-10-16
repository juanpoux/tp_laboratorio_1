#include "ArrayEmpleados.h"

#include "Input.h"

int MenuDeOpciones()
{
	int retorno;

	printf("====================\n\tMENU\n====================\n\n1) ALTA \n2) MODIFICAR \n3) BAJA \n4) INFORMAR \n5) SALIR\n\n");
	PedirEnteroP(&retorno, "Ingrese una opcion: ", "Error, opcion invalida! ", 1, 5);

	return retorno;
}

Empleado CargarEmpleados()
{
	Empleado empleados;

	PedirNombre("Ingrese nombre del empleado: ", empleados.name, 51);
	PedirNombre("Ingrese apellido del empleado: ", empleados.lastName, 51);
	PedirFlotanteP(&empleados.salary, "Ingrese salario del empleado: ", "Error, opcion invalida! ", 0, 99999999);
	PedirEnteroP(&empleados.sector, "Ingrese sector del empleado:\n1 Administracion.\n2 Contabilidad. \n3 RRHH. \n4 Ventas. \n5 Logistica ", "Error, opcion invalida! ", 1, 5);

	return empleados;
}

int AgregarEmpleado(Empleado listaEmpleados[], int tam, int id, char nombre[],char apellido[],float salario,int sector, int index)
{
	int retorno;

	retorno = 0;

	if(listaEmpleados != NULL && nombre != NULL && apellido != NULL)
	{
		listaEmpleados[index].id = id;
		strcpy(listaEmpleados[index].name, nombre);
		strcpy(listaEmpleados[index].lastName, apellido);
		listaEmpleados[index].salary = salario;
		listaEmpleados[index].sector = sector;
		listaEmpleados[index].isEmpty = OCUPADO;
		retorno = 1;
	}

	return retorno;
}

/*PROTOTIPO 1 DE MOSTRAR
void MostrarEmpleado(Empleado listaEmpleados)
{
	printf("%-4d |", listaEmpleados.id);
	FormatearCadena(listaEmpleados.name);
	printf("%-15s |", listaEmpleados.name);
	FormatearCadena(listaEmpleados.lastName);
	printf("%-15s |", listaEmpleados.lastName);
	printf("%-8d |", listaEmpleados.sector);
	printf("$ %-8.2f |\n", listaEmpleados.salary);
	printf("--------------------------------------------------------------\n");
}*/
/* PROTOTIPO 1 DE MOSTRAR LISTA
void MostrarListaEmpleados(Empleado listaEmpleados[], int tam)
{
	int i;

	Encabezado();

	for(i = 0; i < tam; i++)
	{
		if(listaEmpleados[i].isEmpty == 2)
		{
			MostrarEmployee(listaEmpleados[i]);
		}
	}
}*/

int InicializarEmpleados(Empleado listaEmpleados[], int tam)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		listaEmpleados[i].isEmpty = VACIO;
	}

	return 0;
}

int AltaEmpleados(Empleado listaEmpleados[], int tam, int* generadorId)
{
	int retorno;
	int libre;
	Empleado aux;

	retorno = 0;

	libre = BuscarLibre(listaEmpleados, tam);

	if(libre != -1)
	{
		aux = CargarEmpleados();
		AgregarEmpleado(listaEmpleados, tam, *generadorId, aux.name, aux.lastName, aux.salary, aux.sector, libre);
		*generadorId = *generadorId + 1;
		retorno = 1;
	}

	return retorno;
}

int FormatearCadena(char cadena[])
{
	int retorno;
	int i;
	int tam;

	retorno = 0;
	tam = strlen(cadena);

	strlwr(cadena);

	if (cadena != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if (i == 0 || cadena[i - 1] == 32) //32 es ASCCI de "espacio"
			{
				cadena[i] = toupper(cadena[i]);
			}
		}
		retorno = 1;
	}
	return retorno;
}

int BuscarEmpleadoPorID(Empleado listaEmpleados[], int tam, int id)
{
	int i;
	int retorno;

	retorno = -1;

	for(i = 0; i < tam; i++)
	{
		if(listaEmpleados[i].id == id)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

int RemoverEmpleado(Empleado listaEmpleados[], int tam)
{
	int idEmpleado;
	int index;
	int retorno = 0;
	int opcion;

	if(listaEmpleados != NULL && tam > 0)
	{
		MostrarListaEmpleadoConDescripcionSector(listaEmpleados, tam);

		PedirEnteroP(&idEmpleado, "Seleccione el ID del empleado que quiere dar de baja: ",
				"Error, opcion invalida! ", 1, 9999);
		system("cls");
		index = BuscarEmpleadoPorID(listaEmpleados, tam, idEmpleado);

		if(index != -1 && listaEmpleados[index].isEmpty == OCUPADO)
		{
			Encabezado();
			MostrarEmpleadoConDescripcionSector(listaEmpleados[index]);
			PedirEnteroP(&opcion, "Quiere dar de baja este empleado?\n\nPresione 1 para dar de baja:"
					"\nPresione 2 para cancelar: ", "Error, opcion invalida! ", 1, 2);
			if(opcion == 1)
			{
				retorno = 1;
				listaEmpleados[index].isEmpty = VACIO;
			}
			else
			{
				retorno = 2;
			}
		}
	}

	return retorno;
}

int ModificarEmpleado(Empleado listaEmpleados[], int tam)
{
	int retorno;
	int respuestaS;
	int idEmpleado;
	int index;

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		MostrarListaEmpleadoConDescripcionSector(listaEmpleados, tam);
		PedirEnteroP(&idEmpleado, "Seleccione el ID del empleado que desea modificar: ", "Error, opcion invalida! ", 1, 9999);
		system("cls");
		index = BuscarEmpleadoPorID(listaEmpleados, tam, idEmpleado);

		if(index != -1 && listaEmpleados[index].isEmpty == OCUPADO)
		{
			retorno = 1;
			do
			{
				Encabezado();
				MostrarEmpleadoConDescripcionSector(listaEmpleados[index]);
				PedirEnteroP(&respuestaS, "1) Modificar nombre \n2) Modificar apellido \n3) Modificar sector \n"
						"4) Modificar salario \n5) Volver al menu principal: ", "Error, opcion invalida! ", 1, 5);
				switch(respuestaS)
				{
				case 1:
					PedirCadena("Ingrese modificacion del nombre: ", listaEmpleados[index].name, tam);
					break;
				case 2:
					PedirCadena("Ingrese modificacion del apellido: ", listaEmpleados[index].lastName, tam);
					break;
				case 3:
					PedirEnteroP(&listaEmpleados[index].sector, "Ingrese modificacion del sector: ",
							"Error, opcion invalida! ", 0, 999);
					break;
				case 4:
					PedirFlotanteP(&listaEmpleados[index].salary, "Ingrese modificacion del salario: ",
							"Error, opcion invalida! ", 0, 9999999);
					break;
				}
			}while(respuestaS != 5);
		}
	}

	return retorno;
}

int BuscarLibre(Empleado listaEmpleados[], int tam)
{
	int i;
	int retorno;

	retorno = -1;

	for(i = 0; i < tam; i++)
	{
		if(listaEmpleados[i].isEmpty == VACIO)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

void Encabezado()
{
	printf("===========================================================================\n");
	printf("|%-4s |%-15s |%-15s |%-15s |%-15s |\n", "ID", "Nombre", "Apellido", "Sector", "Salario");
	printf("===========================================================================\n");
}

/*
int OrdenarApellido(Empleado listaEmpleados[], int tam, int orden)
{
	int i;
	int j;
	int retorno;
	Empleado aux;

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		retorno = 1;

		switch(orden)
		{
		case 1:
			for (i = 0; i < tam - 1; i++)
			{
				for (j = i + 1; j < tam; j++)
				{
					if (listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO &&
							stricmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName) > 0)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
				}
			}
			break;
		case 2:
			for (i = 0; i < tam - 1; i++)
			{
				for (j = i + 1; j < tam; j++)
				{
					if (listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO &&
							stricmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName) < 0)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
				}
			}
			break;
		}
	}

	return retorno;
}*/

/*
int OrdenarSector(Empleado listaEmpleados[], int tam, int orden)
{
	int i;
	int j;
	int retorno;
	Empleado aux;

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		retorno = 1;

		switch(orden)
		{
		case 1:
			for (i = 0; i < tam - 1; i++)
			{
				for (j = i + 1; j < tam; j++)
				{
					if (listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO &&
							listaEmpleados[i].sector > listaEmpleados[j].sector)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
				}
			}
			break;
		case 2:
			for (i = 0; i < tam - 1; i++)
			{
				for (j = i + 1; j < tam; j++)
				{
					if (listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO &&
							listaEmpleados[i].sector < listaEmpleados[j].sector)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
				}
			}
			break;
		}
	}

	return retorno;
}*/

int OrdenarDobleCriterio(Empleado listaEmpleados[], int tam, int orden)
{

	int i;
	int j;
	int retorno;
	Empleado aux;

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		retorno = 1;

		switch(orden)
		{
		case 1:
			for (i = 0; i < tam - 1; i++)
			{
				for (j = i + 1; j < tam; j++)
				{
					if (listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO &&
							stricmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName) > 0)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
					else
					{
						if(stricmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName) == 0 &&
								listaEmpleados[i].sector > listaEmpleados[j].sector)
						{
							aux = listaEmpleados[i];
							listaEmpleados[i] = listaEmpleados[j];
							listaEmpleados[j] = aux;
						}
					}
				}
			}
			break;
		case 2:
			for (i = 0; i < tam - 1; i++)
			{
				for (j = i + 1; j < tam; j++)
				{
					if (listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO &&
							stricmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName) < 0)
					{
						aux = listaEmpleados[i];
						listaEmpleados[i] = listaEmpleados[j];
						listaEmpleados[j] = aux;
					}
					else
					{
						if(stricmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName) == 0 &&
								listaEmpleados[i].sector < listaEmpleados[j].sector)
						{
							aux = listaEmpleados[i];
							listaEmpleados[i] = listaEmpleados[j];
							listaEmpleados[j] = aux;
						}
					}
				}
			}
			break;
		}
	}

	return retorno;
}

void MostrarEmpleadoConDescripcionSector(Empleado listaEmpleados)
{
	char descripcionSectores[5][LARGONOMBRE] =
	{ "Administracion", "Contabilidad", "RRHH", "Ventas", "Logistica" };

	printf("|%-4d |", listaEmpleados.id);
	FormatearCadena(listaEmpleados.name);
	printf("%-15s |", listaEmpleados.name);
	FormatearCadena(listaEmpleados.lastName);
	printf("%-15s |", listaEmpleados.lastName);
	printf("%-15s |", descripcionSectores[listaEmpleados.sector - 1]);
	printf("$ %-13.2f |\n", listaEmpleados.salary);
	printf(
			"---------------------------------------------------------------------------\n");
}

int MostrarListaEmpleadoConDescripcionSector(Empleado listaEmpleados[], int tam)
{
	int i;
	int retorno;

	retorno = 0;

	Encabezado();

	if(listaEmpleados != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (listaEmpleados[i].isEmpty == OCUPADO)
			{
				MostrarEmpleadoConDescripcionSector(listaEmpleados[i]);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int CalcularTotalYPromedio(Empleado listaEmpleados[],int tam, float* promedio, float* total)
{
	int i;
	float acumulador;
	int contador;
	float auxPromedio;
	int retorno;

	acumulador = 0;
	contador = 0;
	retorno = 0;

	if(listaEmpleados != NULL && tam > 0 && promedio != NULL && total != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == OCUPADO)
			{
				acumulador += listaEmpleados[i].salary;
				contador++;
			}
		}

		auxPromedio = acumulador / contador;
		*promedio = auxPromedio;
		*total = acumulador;

		retorno = 1;
	}

	return retorno;
}

int ContarSalarioPorEncimaDelPromedio(Empleado listaEmpleados[],int tam, float promedio, int* cantidad)
{
	int contador;
	int retorno;
	int i;

	retorno = 0;
	contador = 0;

	if(listaEmpleados != NULL && tam > 0 && cantidad != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			if(listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[i].salary > promedio)
			{
				contador++;
			}
		}

		retorno = 1;
		*cantidad = contador;
	}

	return retorno;
}

int MostrarTotalYPromedio(Empleado listaEmpleados[], int tam)
{
	int retorno;
	int cantidadFinal;
	float promedioFinal;
	float totalFinal;

	CalcularTotalYPromedio(listaEmpleados, tam, &promedioFinal, &totalFinal);
    ContarSalarioPorEncimaDelPromedio(listaEmpleados, tam, promedioFinal, &cantidadFinal);

	retorno = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		retorno = 1;
		printf("El total de la suma de los salarios es: %.2f\n\n"
				"El promedio de los salarios es: %.2f\n\n"
				"Y la cantidad de empleados que superan el salario promedio es: %d\n\n", totalFinal, promedioFinal, cantidadFinal);
	}

	return retorno;
}

int SaberSiHayActivos(Empleado listaEmpleados[], int tam)
{
	int retorno;
	int i;

	retorno = 0;
	if(listaEmpleados != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
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
