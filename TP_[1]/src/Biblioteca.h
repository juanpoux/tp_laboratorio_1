#ifndef PEDIRFLOTANTE_H_
#define PEDIRFLOTANTE_H_
#include <stdio.h>
#include <stdlib.h>

/// @fn float PedirFlotantee(char[], int, int)
/// @brief pide al usuario el ingreso de un numero flotante
///
/// @param mensaje que el usuario lee
/// @param numero mas chico que puede ingresar el usuario
/// @param numero mas grande que puede ingresar
/// @return retorna el numero que ingresa el usuario
float PedirFlotantee(char[], int, int);

/// @fn float Suma(float, float)
/// @brief realiza una suma entre 2 numeros flotantes
///
/// @param primer numero ingresado por el usuario
/// @param segundo numero ingresado
/// @return retorna el valor de la suma
float Suma (float, float);

/// @fn float Resta(float, float)
/// @brief realiza la resta entre 2 numeros flotantes
///
/// @param primer numero ingresado por el usuario
/// @param segundo numero ingresado por el usuario
/// @return retorna el valor de la resta
float Resta (float, float);

/// @fn float Multiplicacion(float, float)
/// @brief realiza una multiplicacion entre 2 numeros
///
/// @param primer numero ingresado por el usuario
/// @param segundo numero ingresado por el usuario
/// @return retorna el valor de la multiplicacion
float Multiplicacion (float, float);

/// @fn float Division(float, float)
/// @brief realiza una division entre el primer numero ingresado sobre el segundo numero ingresado
///
/// @param primer numero ingresado por el usuario
/// @param segundo numero ingresado por el usuario
/// @return retorna el valor de la division
float Division (float, float);

/// @fn long int CalcularFactorial(int)
/// @brief calcula el factorial del numero que se ingrese mientras sea menor que 13, positivo y entero
///
/// @param numero ingresado por el usuario
/// @return retorna el valor del factorial
int CalcularFactorial(int);

/// @fn int ConvertirFlotanteAEntero(float)
/// @brief Verifica si el numero es flotante o entero
///
/// @param el numero que haya ingresado el usuario
/// @return retorna 1 si el numero es entero y si es flotante devuelve 0
int ConvertirFlotanteAEntero(float);

#endif /* PEDIRFLOTANTE_H_ */
