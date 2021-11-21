/*
 * parser.h
 *
 *  Created on: 1 nov. 2021
 *      Author: Negocio
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"
#include <string.h>
#include <ctype.h>


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_BinaryFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
