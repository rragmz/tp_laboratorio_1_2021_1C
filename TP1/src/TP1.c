/*
 ============================================================================
 Name        : TP1.c
 Author      : Rocío Gómez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "operaciones.h"

int menu(int* estadoPrimerOperando, int* estadoSegundoOperando, int* primerNumero, int* segundoNumero);

int main() {
	setbuf(stdout, NULL);

	int primerOperando;
	int segundoOperando;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagCalcular = 0;
	int rSuma;
	int rResta;
	int rMultiplicacion;
	int rFactorial;
	int todoOkDivision;
	float resultadoDivision;
	char salida = 'n';

	do {

		switch (menu(&flagPrimerOperando, &flagSegundoOperando, &primerOperando, &segundoOperando)) {
		case 1:
			printf("Ingrese el primer operando: ");
			scanf("%d", &primerOperando);
			flagPrimerOperando = 1;
			break;

		case 2:
			if (flagPrimerOperando) {
				printf("Ingrese el segundo operando: ");
				scanf("%d", &segundoOperando);
				flagSegundoOperando = 1;
			} else {
				printf("Primero debe ingresar el primer operando\n");
			}
			break;

		case 3:
			if (flagPrimerOperando && flagSegundoOperando) {
				rSuma = suma(primerOperando, segundoOperando);
				rResta = resta(primerOperando, segundoOperando);
				todoOkDivision = dividir(primerOperando, segundoOperando, &resultadoDivision);
				rMultiplicacion = multiplicacion(primerOperando, segundoOperando);
				rFactorial = factorial(primerOperando);
				flagCalcular = 1;
			} else {
				if (flagPrimerOperando) {
					printf("Primero debe ingresar el segundo operando\n");
				} else {
					printf("Primero debe ingresar el primer operando\n");
				}
			}
			break;

		case 4:
			if (flagPrimerOperando && flagSegundoOperando && flagCalcular) {
				printf("El resultado de %d+%d es: %d \n", primerOperando, segundoOperando, rSuma);
				printf("El resultado de %d-%d es: %d\n", primerOperando, segundoOperando, rResta);
				if (todoOkDivision) {
					printf("El resultado de %d/%d es: %.2f \n", primerOperando, segundoOperando, resultadoDivision);
				} else {
					printf("No es posible hacer la división.\n");
				}
				printf("El resultado de %d*%d es: %d\n", primerOperando, segundoOperando, rMultiplicacion);
				if (!rFactorial) {
					printf("Error al calcular el factorial.\n");
				} else {
					printf("El resultado del factorial de %d es %d \n", primerOperando, rFactorial);
				}
				flagPrimerOperando = 0;
				flagSegundoOperando = 0;
				flagCalcular = 0;
			} else {
				printf("Faltan realizar operaciones previas.\n");
			}
			break;
		case 5:
			printf("¡Adiós!\n");
			salida = 's';
			break;
		default:
			printf("Ingrese un número correcto.\n");
			break;

		}
		system("pause");
	} while (salida != 's');

	return 0;
}

