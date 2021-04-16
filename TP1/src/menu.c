/*
 * menu.c
 *
 *  Created on: 13 abr. 2021
 *      Author: rragm
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int menu(int* estadoPrimerOperando, int* estadoSegundoOperando, int* primerNumero, int* segundoNumero) {
	int opcion;

	if (!*estadoPrimerOperando) {

		printf("*******************************\n");
		printf("* BIENVENIDO A LA CALCULADORA *\n");
		printf("*******************************\n");
		printf("Menú de opciones: \n");
		printf("1. Ingresar 1er operando (A=x)\n");
		printf("2. Ingresar 2do operando (B=x)\n");
		printf("3. Calcular todas las operaciones\n");
		printf("a) Calcular la suma (A+B)\n");
		printf("b) Calcular la resta (A-B)\n");
		printf("c) Calcular la division (A/B)\n");
		printf("d) Calcular la multiplicacion (A*B)\n");
		printf("e) Calcular el factorial (A!)\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");

		printf("Ingrese opción: ");
		scanf("%d", &opcion);
	}

	else if (!*estadoSegundoOperando) {

		system("cls");
		printf("*******************************\n");
		printf("* BIENVENIDO A LA CALCULADORA *\n");
		printf("*******************************\n");
		printf("Menú de opciones: \n");
		printf("1. Ingresar 1er operando (A=%d)\n", *primerNumero);
		printf("2. Ingresar 2do operando (B=x)\n");
		printf("3. Calcular todas las operaciones\n");
		printf("a) Calcular la suma (%d+B)\n", *primerNumero);
		printf("b) Calcular la resta (%d-B)\n", *primerNumero);
		printf("c) Calcular la division (%d/B)\n", *primerNumero);
		printf("d) Calcular la multiplicacion (%d*B)\n", *primerNumero);
		printf("e) Calcular el factorial (%d!)\n", *primerNumero);
		printf("4. Informar resultados\n");
		printf("5. Salir\n");

		printf("Ingrese opción: ");
		scanf("%d", &opcion);
	} else {

		printf("*******************************\n");
		printf("* BIENVENIDO A LA CALCULADORA *\n");
		printf("*******************************\n");
		printf("Menú de opciones: \n");
		printf("1. Ingresar 1er operando (A=%d)\n", *primerNumero);
		printf("2. Ingresar 2do operando (B=%d)\n", *segundoNumero);
		printf("3. Calcular todas las operaciones\n");
		printf("a) Calcular la suma (%d+%d)\n", *primerNumero, *segundoNumero);
		printf("b) Calcular la resta (%d-%d)\n", *primerNumero, *segundoNumero);
		printf("c) Calcular la division (%d/%d)\n", *primerNumero, *segundoNumero);
		printf("d) Calcular la multiplicacion (%d*%d)\n", *primerNumero, *segundoNumero);
		printf("e) Calcular el factorial (%d!)\n", *primerNumero);
		printf("4. Informar resultados\n");
		printf("5. Salir\n");

		printf("Ingrese opción: ");
		scanf("%d", &opcion);
	}

	return opcion;
}

