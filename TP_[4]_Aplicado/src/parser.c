#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[MAXNAME];
	char nombre[MAXNAME];
	char horas[MAXNAME];
	char sueldo[MAXNAME];
	Employee *aux;
	retorno = -1;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
			aux = employee_newParametros(id, nombre, horas, sueldo);
			ll_add(pArrayListEmployee, aux);
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee *aux;

	retorno = -1;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		while(!feof(pFile))
		{
			aux = employee_new();
			fread(aux, sizeof(Employee), 1, pFile);
			if(feof(pFile))
			{
				break;
			}
			else
			{
				ll_add(pArrayListEmployee, aux);
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los empleados desde la lista para guardar en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	char nombre[MAXNAME];
	int horas;
	int sueldo;
	Employee *aux;
	int tam;

	tam = ll_len(pArrayListEmployee);
	retorno = -1;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		fprintf(pFile, "%s\n", "id,nombre,horasTrabajadas,sueldo");
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &id);
			employee_getNombre(aux, nombre);
			employee_getHorasTrabajadas(aux, &horas);
			employee_getSueldo(aux, &sueldo);
			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los empleados desde la lista para guardar en el archivo data.bin(modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_BinaryFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee *aux;
	int tam;

	retorno = -1;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				fwrite(aux, sizeof(Employee), 1, pFile);
			}
		}
	}
	return retorno;
}
