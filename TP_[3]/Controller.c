#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL && !parser_EmployeeFromText(pFile, pArrayListEmployee))
		{
			retorno = 0;
		}
		fclose(pFile);
	}

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL && !parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			retorno = 0;
		}
		fclose(pFile);
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	Employee *aux;
	int id;
	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		aux = employee_newXTeclado();
		id = controller_leerId();
		id++;
		employee_setId(aux, id);
		controller_guardarId2(id);
		ll_add(pArrayListEmployee, aux);
		employee_encabezado();
		employee_mostrarUno(aux);
		Renglones(-1, 45, '-');
	}
	return retorno;
}

/*int controller_addEmployee(LinkedList *pArrayListEmployee, int *id)
{
	int retorno;
	Employee *aux;
	int idLocal;
	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		idLocal = *id;
		retorno = 0;
		aux = employee_newXTeclado(idLocal);
		ll_add(pArrayListEmployee, aux);
		employee_encabezado();
		employee_mostrarUno(aux);
		idLocal++;
		*id = idLocal;
	}
	return retorno;
}*/

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	int index;
	Employee *aux;
	int mod;
	int opcion;

	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		index = controller_pedirIdActivoYBuscarIndex(pArrayListEmployee);
		aux = ll_get(pArrayListEmployee, index);
		employee_mostrarUno(aux);
		Renglones(-1, 45, '-');
		PedirEnteroP(&mod, "1) Modificar este empleado \n2) Desea cancelar \nIngrese una opcion: ", "Error, ingreso invalido ", 1, 2);
		if(mod == 1)
		{
			retorno = 0;
			PedirEnteroP(&opcion, "1) Modificar sueldo \n2) Modificar horas tabajadas \n3) Modificar nombre "
					"\nIngrese una opcion: ", "Error, ingreso invalido ", 1, 5);
			switch(opcion)
			{
			case 1:
				employee_setSueldoXTeclado(aux);
				break;
			case 2:
				employee_setHorasTrabajadasXTeclado(aux);
				break;
			case 3:
				employee_setNombreXTeclado(aux);
				break;
			}
		}
		else
		{
			puts("Modificacion cancelada!");
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	int index;
	Employee *aux;
	int mod;
	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		index = controller_pedirIdActivoYBuscarIndex(pArrayListEmployee);
		aux = ll_get(pArrayListEmployee, index);
		employee_encabezado();
		employee_mostrarUno(aux);
		Renglones(-1, 45, '-');
		PedirEnteroP(&mod, "1) Remover este empleado \n2) Desea cancelar \nIngrese una opcion: ", "Error, ingreso invalido ", 1, 2);
		if(mod == 1)
		{
			retorno = 0;
			ll_remove(pArrayListEmployee, index);
			employee_delete(aux);
		}
		else
		{
			puts("Baja de empleado cancelada!");
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	int tam;
	Employee *aux;

	retorno = -1;
	tam = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		employee_encabezado();
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_mostrarUno(aux);
		}
		Renglones(-1, 45, '-');
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");
		if(!parser_TextFromEmployee(pFile, pArrayListEmployee))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if(!parser_BinaryFromEmployee(pFile, pArrayListEmployee))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}

int controller_buscarIndexPorId(LinkedList *pArrayListEmployee, int id)
{
	int retorno;
	int tam;
	int idEmpleado;
	Employee *aux;
	retorno = -1;
	tam = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &idEmpleado);
			if(idEmpleado == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int controller_pedirIdActivoYBuscarIndex(LinkedList *pArrayListEmployee)
{
	int idAux;
	int retorno;
	int index;
	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		retorno = 1;
		PedirEnteroP(&idAux, "Ingrese ID del empleado: ", "Error ", 0, 9999999);
		index = controller_buscarIndexPorId(pArrayListEmployee, idAux);
		while(index == -1)
		{
			printf("El ID ingresado no es valido\n");
			PedirEnteroP(&idAux, "Ingrese ID del empleado: ", "Error ", 0, 9999999);
			index = controller_buscarIndexPorId(pArrayListEmployee, idAux);
		}
		retorno = index;
	}
	return retorno;
}

int controller_menuDeOpciones()
{
	int retorno;

	PedirEnteroP(&retorno, "\t\t\t--------------------------------\n"
			"\t\t\t******* MENU DE OPCIONES *******\n"
			"\t\t\t--------------------------------"
			"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). "
			"\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). "
			"\n3. Alta de empleado "
			"\n4. Modificar datos de empleado "
			"\n5. Baja de empleado "
			"\n6. Listar empleados "
			"\n7. Ordenar empleados "
			"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto). "
			"\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario). "
			"\n10. Salir: ", "error ", 0, 10);

	return retorno;
}

void controller_guardarId(char *path, int bancoId)
{
	FILE *archivoId;

	archivoId = fopen(path, "w");
	fprintf(archivoId, "%d", bancoId);
	fclose(archivoId);
}
void controller_guardarId2(int guardarId)
{
	FILE *archivoId;

	archivoId = fopen(ARCHIVOID, "w");
	fprintf(archivoId, "%d", guardarId);
	fclose(archivoId);
}

int controller_leerId()
{
	FILE *archivoId;
	char idStr[25];
	int idNum;

	archivoId = fopen(ARCHIVOID, "r");
	fscanf(archivoId, "%s", idStr);
	idNum = atoi(idStr);
	fclose(archivoId);
	return idNum;
}

int controller_generarPrimerId(LinkedList *pArrayListEmployee, int *bancoId)
{
	int retorno;
	int tam;
	int id;
	int bandera;
	int masAlto;
	Employee *aux;

	retorno = -1;
	bandera = 0;
	tam = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &id);
			if(bandera == 0 || masAlto < id)
			{
				bandera = 1;
				masAlto = id;
			}
		}
		*bancoId = masAlto + 1;
	}
	return retorno;
}
