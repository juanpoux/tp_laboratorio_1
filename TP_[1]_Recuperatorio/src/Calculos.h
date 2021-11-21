#include <stdio.h>
#include <stdlib.h>
#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "Input.h"

/// @fn int Suma(float, float, float*)
/// @brief recibe 2 numeros flotantes y los suma entre si, devuelve el resultado por puntero
///
/// @param numeroUno primer numero ingresado
/// @param numeroDos segundo numero ingresado
/// @param resultado puntero float al resultado
/// @return -1 si no pudo hacerlo, 0 si pudo
int Suma(float numeroUno, float numeroDos, float *resultado);

/// @fn int Resta(float, float, float*)
/// @brief recibe 2 numeros flotantes y resta el primero por el segundo, devuelve el resultado por puntero
///
/// @param numeroUno primer numero ingresado
/// @param numeroDos segundo numero ingresado
/// @param resultado puntero float al resultado
/// @return -1 si no pudo hacerlo, 0 si pudo
int Resta (float numeroUno, float numeroDos, float *resultado);

/// @fn int Multiplicacion(float, float, float*)
/// @brief recibe 2 numeros flotantes y divide el primero por el segundo, devuelve el resultado por puntero
///
/// @param numeroUno primer numero ingresado
/// @param numeroDos segundo numero ingresado
/// @param resultado puntero float al resultado
/// @return -1 si no pudo hacerlo, 0 si pudo
int Multiplicacion (float numeroUno, float numeroDos, float *resultado);

/// @fn int Division(float, float, float*)
/// @brief recibe 2 numeros flotantes y divide el primero por el segundo, devuelve el resultado por puntero
///
/// @param numeroUno primer numero ingresado
/// @param numeroDos segundo numero ingresado
/// @param resultado puntero float al resultado
/// @return -1 si no pudo hacerlo, 0 si pudo
int Division(float numeroUno, float numeroDos, float *resultado);

/// @fn int CalcularFactorial(int*, float)
/// @brief calcula el factorial de un numero que recibe por parametro y devuelve el resultado por puntero
///
/// @param resultado puntero float al resultado
/// @param numeroIngresado numero para calcular el factorial
/// @return -1 si no pudo hacerlo, 0 si pudo
int CalcularFactorial(int *resultado, float numeroIngresado);

/// @fn int VerificarSiEsEntero(float)
/// @brief Verifica si un flotante es numero entero o es numero con decimales
///
/// @param numero
/// @return 1 si es numero con decimales, 0 si es numero entero
int VerificarSiEsEntero(float numero);

#endif /* CALCULOS_H_ */
