/*
 * validaciones.c
 *
 *  Created on: 15 may. 2021
 *      Author: rragm
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "utn.h"
#include "arrayEmployee.h"

int validarNombre(Employee empleado){
    int retorno;
    while(!esSoloLetras(empleado.name) || strlen(empleado.name) > 51){
        printf("Error. Ingrese nombre: ");
        fflush(stdin);
        gets(empleado.name);
    }
    retorno = 0;
    return retorno;
}

int validarApellido(Employee empleado){
    int retorno = -1;
    while(!esSoloLetras(empleado.lastName) || strlen(empleado.lastName) > 51){
        printf("Error. Ingrese apellido: ");
        fflush(stdin);
        gets(empleado.lastName);
    }
    retorno = 0;
    return retorno;
}



