#include <stdio.h>
#include <stdlib.h>
#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "Input.h"


float Resta (float numeroUno, float numeroDos, float *resultado);
float Multiplicacion (float numeroUno, float numeroDos, float *resultado);
int Division(float numeroUno, float numeroDos, float *resultado);
int ConvertirFlotanteAEntero(float numeroIngresado);
int CalcularFactorial(int* resultado, int numeroIngresado);

#endif /* CALCULOS_H_ */
