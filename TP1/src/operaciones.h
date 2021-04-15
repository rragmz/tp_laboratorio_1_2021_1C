/*
 * operaciones.h
 *
 *  Created on: 13 abr. 2021
 *      Author: rragm
 */

#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/** \brief Realiza la suma entre dos n�meros enteros
 *
 * \param Primer n�mero entero
 * \param Segundo n�mero entero
 * \return Devuelve el resultado de la suma
 *
 */
int suma(int a, int b);

/** \brief Realiza la resta entre dos n�meros enteros
 *
 * \param a int Primer n�mero entero
 * \param b int Segundo n�mero entero
 * \return int Devuelve el resultado de la resta
 *
 */
int resta(int a, int b);

/** \brief Realiza la divisi�n de dos n�meros enteros
 *
 * \param a int Dividendo de la operaci�n
 * \param b int Divisor de la operaci�n
 * \param c float* Puntero/variable que guarda una direcci�n de memoria
 * \return float Devuelve 1 si pudo hacer la divisi�n o 0 si no pudo (cuando el divisor sea 0).
 *
 */
float dividir(int a, int b, float* c);

/** \brief Realiza la multiplicaci�n de dos n�meros enteros
 *
 * \param a int Primer n�mero entero
 * \param b int Segundo n�mero entero
 * \return int Devuelve el resultado de la multiplicaci�n
 *
 */
int multiplicacion(int a, int b);

/** \brief Realiza el producto de todos los numeros enteros positivos desde 1 hasta n. Permite el c�lculo hasta el n�mero 17.
 *
 * \param n int �nico n�mero entero
 * \return int Devuelve el resultado.
 *
 */
int factorial(int n);

#endif // OPERACIONES_H_INCLUDED
