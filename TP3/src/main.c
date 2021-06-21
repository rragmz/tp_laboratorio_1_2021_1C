/*
 ============================================================================
 Name        : TP3.c
 Author      : Rocío Gómez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdin, NULL);
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option = menu();
        switch(option)
        {
            case 1:
                controller_loadFromText(listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary(listaEmpleados);
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)){
                    printf("\n\n");
                }
                else{
                    printf("Ocurrió un error\n");
                }
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados)){
                    printf("Modificación exitosa!\n");
                }
                else{
                    printf("Se produjo un error\n");
                }
                break;
            case 5:
                if(controller_removeEmployee(listaEmpleados)){
                    printf("Eliminación exitosa\n");
                }
                else{
                    printf("Se produjo un error\n");
                }
                break;
            case 6:
                if(controller_ListEmployee(listaEmpleados)){
                    printf("\n\n");
                }
                else{
                    printf("Ocurrió un error\n");
                }
                break;
            case 7:
                if(controller_sortEmployee(listaEmpleados)){
                    printf("\n\n");
                }
                else{
                    printf("Ocurrió un error\n");
                }
                break;
            case 8:
                controller_saveAsText(listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary(listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
