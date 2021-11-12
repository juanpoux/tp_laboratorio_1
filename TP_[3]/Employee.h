#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "Input.h"
#define MAXNAME 100

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// @fn Employee employee_new*()
/// @brief
///
/// @return
Employee* employee_new();

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldoStr
/// @return
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char *sueldoStr);

/// @fn int employee_delete(Employee*)
/// @brief
///
/// @param this
/// @return
int employee_delete(Employee *this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setSueldoXTeclado(Employee *this);
int employee_setNombreXTeclado(Employee *this);
int employee_setHorasTrabajadasXTeclado(Employee *this);
Employee* employee_newXTeclado();

int employee_mostrarUno(Employee *this);
void employee_encabezado();
int employee_compararNombres(void* empleadoUno, void* empleadoDos);
int employee_compararSueldo(void* empleadoUno, void* empleadoDos);
int employee_compararHoras(void* empleadoUno, void* empleadoDos);
int employee_compararId(void* empleadoUno, void* empleadoDos);

#endif // employee_H_INCLUDED
