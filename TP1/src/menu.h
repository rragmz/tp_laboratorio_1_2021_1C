/*
 * menu.h
 *
 *  Created on: 13 abr. 2021
 *      Author: rragm
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


/** \brief Despliega el men� de opciones
 *
 * \param a int Paso por par�metro el puntero a FlagPrimerOperando (1 o 0)
 * \param b int Paso por par�metro el puntero a FlagSegundoOperando (1 o 0)
 * \param c int Paso por par�metro el puntero al primer n�mero ingresado por el usuario
 * \param d int Paso por par�metro el puntero al primer segundo ingresado por el usuario
 * \return int Devuelve el n�mero de la opci�n elegida por el usuario
 *
 */
int menu(int* estadoPrimerOperando, int* estadoSegundoOperando, int* primerNumero, int* segundoNumero);

#endif // MENU_H_INCLUDED
