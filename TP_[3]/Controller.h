#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"
#include "parser.h"
#define ARCHIVOID "guardarId.csv"
#define ARCHIVOPRINCIPAL "data.csv"
#define ARCHIVOBINARIO "data.bin"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
//int controller_addEmployee(LinkedList* pArrayListEmployee, int *id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_buscarIndexPorId(LinkedList *pArrayListEmployee, int id);
int controller_pedirIdActivoYBuscarIndex(LinkedList *pArrayListEmployee);
int controller_menuDeOpciones();
void controller_guardarId(char *path, int bancoId);
int controller_leerId();
int controller_generarPrimerId(LinkedList *pArrayListEmployee, int *bancoId);
void controller_guardarId2(int guardarId);
