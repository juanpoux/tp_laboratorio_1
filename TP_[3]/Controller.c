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
	int respuesta;

	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		aux = employee_newXTeclado();
		id = controller_leerId();
		id++;
		employee_setId(aux, id);
		employee_encabezado();
		employee_mostrarUno(aux);
		Renglones(-1, 45, '-');
		PedirEnteroP(&respuesta, "Desea guardar el empleado asi? \n1) Si \n2) No \nIngrese una opcion: ", "Error ingreso inalido \n", 1, 2);
		if(respuesta == 1)
		{
			ll_add(pArrayListEmployee, aux);
			controller_guardarId2(id);
		}
		else
		{
			free(aux);
			retorno = 1;
		}
	}
	return retorno;
}

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
		PedirEnteroP(&mod, "1) Desea remover este empleado \n2) Desea cancelar \nIngrese una opcion: ", "Error, ingreso invalido \n", 1, 2);
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
	int retorno;
	int opcion;
	int order;
	LinkedList *aux;

	aux = ll_clone(pArrayListEmployee);
	retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		PedirEnteroP(&opcion, "1) Ordenar por nombres \n2) Ordenar por sueldos \n3) Ordenar por horas trabajadas "
				"\n4) Ordenar por ID \nIngrese una opcion: ", "Error, ingreso invalido \n", 1, 4);
		switch(opcion)
		{
		case 1:
			puts("\t  *************** Ordenar por nombre ***************");
			PedirEnteroP(&order, "1) Ordenar de A a Z \n0) Ordenar de Z a A \nIngrese una opcion: ", "Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, employee_compararNombres, order);
			break;
		case 2:
			puts("\t  *************** Ordenar por sueldo ***************");
			PedirEnteroP(&order, "1) Ordenar de forma ascendente \n0) Ordenar de forma descendente \nIngrese una opcion: ",
					"Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, employee_compararSueldo, order);
			break;
		case 3:
			puts("\t  *************** Ordenar por horas trabajadas ***************");
			PedirEnteroP(&order, "1) Ordenar de forma ascendente \n0) Ordenar de forma descendente \nIngrese una opcion: ",
					"Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, employee_compararHoras, order);
			break;
		case 4:
			puts("\t  *************** Ordenar por ID ***************");
			PedirEnteroP(&order, "1) Ordenar de forma ascendente \n0) Ordenar de forma descendente \nIngrese una opcion: ",
					"Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, employee_compararId, order);
			break;
		}
		controller_ListEmployee(aux);
		ll_deleteLinkedList(aux);
	}
	return retorno;
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
		if(pFile != NULL && !parser_TextFromEmployee(pFile, pArrayListEmployee))
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
		if(pFile != NULL && !parser_BinaryFromEmployee(pFile, pArrayListEmployee))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}

/// @fn int controller_buscarIndexPorId(LinkedList*, int)
/// @brief busca un indice por ID
///
/// @param pArrayListEmployee
/// @param id
/// @return -1 si no encontro, el indice si lo encontro
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

/// @fn int controller_pedirIdActivoYBuscarIndex(LinkedList*)
/// @brief pide el id que va a usar para buscar el indice hasta que ingrese un id correcto
///
/// @param pArrayListEmployee
/// @return -1 si no encontro, el indice si lo encontro
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

/// @fn int controller_menuDeOpciones()
/// @brief menu principal de opciones
///
/// @return nada
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

/// @fn int controller_guardarId2(int)
/// @brief guarda un id en un archivo especifico
///
/// @param guardarId
/// @return retorna -1 si no pudo, 0 si pudo
int controller_guardarId2(int guardarId)
{
	FILE *archivoId;
	int retorno;

	retorno = -1;
	archivoId = fopen(ARCHIVOID, "w");
	if(archivoId != NULL)
	{
		retorno = 0;
		fprintf(archivoId, "%d", guardarId);
		fclose(archivoId);
	}
	return retorno;
}

/// @fn int controller_leerId()
/// @brief lee el ultimo id de un archivo
///
/// @return retorna -1 si no pudo, 0 si pudo
int controller_leerId()
{
	FILE *archivoId;
	char idStr[25];
	int idNum;

	idNum = -1;
	archivoId = fopen(ARCHIVOID, "r");
	if(archivoId != NULL)
	{
		fscanf(archivoId, "%s", idStr);
		idNum = atoi(idStr);
		fclose(archivoId);
	}
	return idNum;
}

/*
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
}*/

/// @fn int controller_GuardarPrimerId(int*)
/// @brief guarda el primer id en una variable por si se cierra el programa sin guardar
///
/// @param id
/// @return -1 si hubo algun error, 0 si pudo
int controller_GuardarPrimerId(int *id)
{
	int primerId;
	int retorno;

	retorno = -1;
	if(id != NULL)
	{
		retorno = 0;
		primerId = controller_leerId();
		*id = primerId;
	}
	return retorno;
}
