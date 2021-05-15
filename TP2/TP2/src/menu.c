/*
 * menu.c
 *
 *  Created on: 15 may. 2021
 *      Author: rragm
 */

#include "menu.h"
#include "utn.h"

int menu(){
	int opcion;
	utn_getNumero(&opcion,
			"--------- SISTEMA DE EMPLEADOS ---------\n\n"
			                "1. Alta empleado\n"
			                "2. Modificacion datos de un empleado\n"
			                "3. Baja empleado\n"
			                "4. Informes\n"
			                "5. Salir\n"
			                "Ingrese opcion: ",
			                "Error, ingrese opcion valida\n", 1, 5, 3);
			    return opcion;
}

