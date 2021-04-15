/*
 * operaciones.h
 *
 *  Created on: 13 abr. 2021
 *      Author: rragm
 */

#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/** \brief Realiza la suma entre dos números enteros
 *
 * \param Primer número entero
 * \param Segundo número entero
 * \return Devuelve el resultado de la suma
 *
 */
int suma(int a, int b);

/** \brief Realiza la resta entre dos números enteros
 *
 * \param a int Primer número entero
 * \param b int Segundo número entero
 * \return int Devuelve el resultado de la resta
 *
 */
int resta(int a, int b);

/** \brief Realiza la división de dos números enteros
 *
 * \param a int Dividendo de la operación
 * \param b int Divisor de la operación
 * \param c float* Puntero/variable que guarda una dirección de memoria
 * \return float Devuelve 1 si pudo hacer la división o 0 si no pudo (cuando el divisor sea 0).
 *
 */
float dividir(int a, int b, float* c);

/** \brief Realiza la multiplicación de dos números enteros
 *
 * \param a int Primer número entero
 * \param b int Segundo número entero
 * \return int Devuelve el resultado de la multiplicación
 *
 */
int multiplicacion(int a, int b);

/** \brief Realiza el producto de todos los numeros enteros positivos desde 1 hasta n. Permite el cálculo hasta el número 17.
 *
 * \param n int Único número entero
 * \return int Devuelve el resultado.
 *
 */
int factorial(int n);

#endif // OPERACIONES_H_INCLUDED
