#include <stdio.h>
#include <stdlib.h>
#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "Input.h"

int Suma(float numeroUno, float numeroDos, float *resultado);
int Resta (float numeroUno, float numeroDos, float *resultado);
int Multiplicacion (float numeroUno, float numeroDos, float *resultado);
int Division(float numeroUno, float numeroDos, float *resultado);
int CalcularFactorial(int *resultado, float numeroIngresado);
int VerificarSiEsEntero(float numero);

#endif /* CALCULOS_H_ */
