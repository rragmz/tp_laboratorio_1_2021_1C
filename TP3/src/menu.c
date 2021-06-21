#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED

int menu(){
    int opcion;
    printf("*** MENU ***\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10. Salir\n");
    printf("Ingrese opción: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

#endif // MENU_C_INCLUDED
