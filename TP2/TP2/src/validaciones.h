/*
 * validaciones.h
 *
 *  Created on: 15 may. 2021
 *      Author: rragm
 */

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "arrayEmployee.h"

/** \brief Valida que el nombre ingresado sea solo letras y menor al tamaño del string
 *
 * \param empleado Employee
 * \return int
 *
 */
int validarNombre(Employee empleado);

/** \brief Valida que el apellido ingresado sea solo letras y menor al tamaño del string
 *
 * \param empleado Employee
 * \return int
 *
 */
int validarApellido(Employee empleado);

#endif // VALIDACIONES_H_INCLUDED

