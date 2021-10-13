/*
 * ArrayEmpleados.h
 *
 *  Created on: 29 sep. 2021
 *      Author: poux_
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define OCUPADO 2
#define VACIO 0
#define LARGONOMBRE 51

typedef struct
{
	int id;
	char name[LARGONOMBRE];
	char lastName[LARGONOMBRE];
	float salary;
	int sector;
	int isEmpty;
}Empleado;

/// @fn int MenuDeOpciones()
/// @brief muestra el menu principal y pide un entero
///
/// @return retorna el numero ingresado que es la opcion del menu
int MenuDeOpciones();

/// @fn Empleado CargarEmpleados()
/// @brief pide el ingreso de los campos de la estructura
///
/// @return retorna la variable cargada completa
Empleado CargarEmpleados();

/// @fn int AgregarEmpleado(Empleado[], int, int, char[], char[], float, int, int)
/// @brief
///
/// @param listaEmpleados
/// @param tam
/// @param id
/// @param nombre
/// @param apellido
/// @param salario
/// @param sector
/// @param index
/// @return
int AgregarEmpleado(Empleado listaEmpleados[], int tam, int id, char nombre[],char apellido[],float salario,int sector, int index);

/// @fn int InicializarEmpleados(Empleado[], int)
/// @brief inicia el campo que verifica que el empleado esta cargado en 0
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @return no retorna nada por el momento
int InicializarEmpleados(Empleado listaEmpleados[], int tam);

/// @fn int AltaEmpleados(Empleado[], int, int*)
/// @brief da de alta un empleado nuevo, llama a la funcion que pide los ingresos de datos
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @param generadorId variable del main que genera el numero de ID del usuario
/// @return retorna 1 si se pudo hacer la carga correctamente, 0 si hubo algun error
int AltaEmpleados(Empleado listaEmpleados[], int tam, int* generadorId);

/// @fn int FormatearCadena(char[])
/// @brief pone mayusculas a las primeras letras del nombre y apellido
///
/// @param cadena
/// @return retorna 1 si logro hacerlo, 0 si no pudo
int FormatearCadena(char cadena[]);
//void MostrarEmpleado(Empleado listaEmpleados);
//void MostrarListaEmpleados(Empleado listaEmpleados[], int tam);

/// @fn int BuscarEmpleadoPorID(Empleado[], int, int)
/// @brief por id busca un empleado en el array
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @param id del empleado
/// @return retorna -1 si no lo encontro, sino retorna la posicion en el array
int BuscarEmpleadoPorID(Empleado listaEmpleados[], int tam, int id);

/// @fn int RemoverEmpleado(Empleado[], int)
/// @brief remueve un empleado cambiando el estado de isEmpty
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @return retorna 0 si no encuentra el id, 1 si logro removerlo con exito y 2 si la baja fue cancelada
int RemoverEmpleado(Empleado listaEmpleados[], int tam);

/// @fn int ModificarEmpleado(Empleado[], int)
/// @brief le da al usuario opciones de los campos de un empleado que puede modificar
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @return retorna 1 si encontro un empleado para modificar, 0 si no encontro el empleado
int ModificarEmpleado(Empleado listaEmpleados[], int tam);

/// @fn int BuscarLibre(Empleado[], int)
/// @brief busca espacios del array que tengan el campo isEmpty en 0
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @return retorna -1 si no encontro espacio libre y retorna la posicion del array si encontro alguno libre
int BuscarLibre(Empleado listaEmpleados[], int tam);

/// @fn void Encabezado()
/// @brief encabezado estetico
///
void Encabezado();
//int OrdenarApellido (Empleado listaEmpleados[], int tam, int orden);
//int OrdenarSector (Empleado listaEmpleados[], int tam, int orden);

/// @fn int OrdenarDobleCriterio(Empleado[], int, int)
/// @brief ordena por apellido en orden alfabetico de A a Z o de Z a A y en segundo lugar por sector
///
/// @param listaEmpleados array empleados
/// @param tam tamaño del array
/// @param orden opcion para que elija el ordenamiento
/// @return retorna 1 si puede ordenar y retorna 0 si no puede
int OrdenarDobleCriterio (Empleado listaEmpleados[], int tam, int orden);

/// @fn void MostrarEmpleadoConDescripcionSector(Empleado)
/// @brief muestra los datos de un empleado y muestra un string del sector del empleado segun el entero ingresado
///
/// @param listaEmpleados array de empleados
void MostrarEmpleadoConDescripcionSector(Empleado listaEmpleados);

/// @fn int MostrarListaEmpleadoConDescripcionSector(Empleado[], int)
/// @brief muestra todos los empleados cargados
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @return retorna 1 si lo pudo realizar y 0 si no pudo
int MostrarListaEmpleadoConDescripcionSector(Empleado listaEmpleados[],int tam);

/// @fn int CalcularTotalYPromedio(Empleado[], int, float*, float*)
/// @brief suma los salarios de los empleados cargados y hace un promedio
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @param promedio puntero para modificar y devolver el valor del promedio
/// @param total puntero para modificar y devolver el valor de la suma de salarios
/// @return retorna 1 si pudo realizar la accion, 0 si no pudo
int CalcularTotalYPromedio(Empleado listaEmpleados[],int tam, float* promedio, float* total);

/// @fn int ContarSalarioPorEncimaDelPromedio(Empleado[], int, float, int*)
/// @brief cuenta la cantidad de empleados que superan el promedio de salario
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @param promedio promedio de salario
/// @param cantidad puntero para modificar y devolver la cantidad de empleados que superan el promedio
/// @return retorna 1 si pudo realizar la accion, 0 si no pudo
int ContarSalarioPorEncimaDelPromedio(Empleado listaEmpleados[],int tam, float promedio, int* cantidad);

/// @fn int MostrarTotalYPromedio(Empleado[], int)
/// @brief muestra en pantalla los calculos que hizo en las funciones de total y promedio
///
/// @param listaEmpleados array de empleados
/// @param tam tamaño del array
/// @return retorna 1 si pudo hacerlo, 0 si no pudo
int MostrarTotalYPromedio(Empleado listaEmpleados[], int tam);

#endif /* ARRAYEmpleadoS_H_ */
