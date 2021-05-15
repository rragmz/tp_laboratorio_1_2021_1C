/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployee.h"
#include "utn.h"
#include "validaciones.h"
#include "menu.h"

#define TAM 1000

int main()
{
	setbuf(stdout, NULL);
    char seguir;
    int proxId = 1;
    int legajoBaja;
    int legajoModifica;
    int orden;
    int flagAlta = 0;
    Employee lista[TAM];
    initEmployees(lista, TAM);
    Employee unEmpleado;

    do{

    switch(menu()){
        case 1:
            system("cls");
            printf("-------- Alta empleado --------\n");
            //Asigno ID
            printf("Id empleado: %d\n", proxId);
            //Pido datos y valido
            //Nombre
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(unEmpleado.name);
            validarNombre(unEmpleado);

            //Apellido
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(unEmpleado.lastName);
            validarApellido(unEmpleado);
            //Salario
            utn_getNumeroFlotante(&unEmpleado.salary, "Ingrese salario: ", "Error. Debe ser un numero\n", 1, 1000000, 3);
            //Sector
            utn_getNumero(&unEmpleado.sector, "Ingrese ID sector: ", "Error. Debe ser un numero entre 1 y 100\n", 1, 100, 3);

            //Si addEmployee == 0 significa que todos los datos se cargaron correctamente
            if(!addEmployee(lista, TAM, &proxId, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector)){
                printf("Se realizo con exito la carga!!\n");
            }
            else{
                printf("No se pudo realizar el alta\n");
            }
            printEmployees(lista, TAM);
            flagAlta = 1;
            break;
        case 2:
            system("cls");
            if(flagAlta){
                printf("-------- Ordenamiento de empleados --------\n\n");
                printEmployees(lista, TAM);
                utn_getNumero(&legajoModifica, "Ingrese ID del empleado que quiere modificar: ", "Error. Reingrese el ID\n",1,100,3);
                if(modifyEmployee(lista, TAM,legajoModifica)){
                    printf("Se realizó con éxito la modificación!!\n");
                }
                else{
                    printf("No se pudo completar la modificación\n");
                }
            }
            else{
                printf("Primero debe dar de alta\n");
            }
            break;
        case 3:
            system("cls");
            if(flagAlta){
                printf("-------- Baja de Empleados --------\n\n");
                printEmployees(lista, TAM);
                utn_getNumero(&legajoBaja, "Ingrese ID del empleado a dar de baja: ", "Error. Reingrese el ID\n", 1, 100, 3);
                if(removeEmployee(lista, TAM, legajoBaja) == 0){
                    printf("La baja se realizo correctamente\n");
                }
                else{
                    printf("No se pudo realizar la baja\n");
                }
            }
            else{
                printf("Primero debe dar de alta\n");
            }
            break;
        case 4:
            system("cls");
            if(flagAlta){
                printf("-------- Informes --------\n\n");
                utn_getNumero(&orden, "Escoja un orden: \n 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n2.  Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n", "Error. Reingrese\n",1,2,1);
                if(!sortEmployees(lista, TAM, orden)){
                    printf("Se realizo el ordenamiento correctamente!\n");
                }
                else{
                    printf("No se pudo realizar correctamente el ordenamiento!\n");
                }
            }
            else{
                printf("Primero debe dar de alta\n");
            }
            break;
        case 5:
            printf("Confirma salida? s/n: ");
            fflush(stdin);
            scanf("%s", &seguir);
            break;
        }
        system("pause");
    }while(seguir != 's');
    return 0;
}

