/*
 * arrayEmployee.c
 *
 *  Created on: 15 may. 2021
 *      Author: rragm
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployee.h"
#include "utn.h"

//Inicializo los empleados poniendo su isEmpty en 1 (vacío)
int initEmployees(Employee* list, int len)
{
    int todoOk = -1;
    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            list[i].isEmpty = 1;
            todoOk = 0;
    }
}
    return todoOk;
}

//Alta empleado
int addEmployee(Employee* list, int len, int* id, char name[],char
lastName[],float salary,int sector)
{
    int todoOk = -1;
    int indice;
    //Verifico que la lista y el id no estén vacíos y que el tamaño sea mayor a 0
    if(list != NULL && len > 0 && id != NULL){
        //Guardo en mi variable el indice del primer elemento vacío de la lista que retorna la función
        indice = freePlaceIndex(list, len);
        //Copio los datos que pedí y validé en el índice del array que obtuvimos en el paso anterior
        if(indice != -1){
            list[indice].id = *id;
            strcpy(list[indice].name, name);
            strcpy(list[indice].lastName, lastName);
            list[indice].salary = salary;
            list[indice].sector = sector;
            //Ocupo el lugar
            list[indice].isEmpty = 0;
            todoOk = 0;
            //Modifico el valor del legajo
            (*id)++;
       }
    }
    else{
        printf("No hay lugar para cargar mas empleados \n");
    }

    return todoOk;
}

//Busco empleado por Id
int findEmployeeById(Employee* list, int len,int id)
{
    int index = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            //Busco el legajo coincidente dentro de las estructuras ACTIVAS
            if(list[i].id == id && !list[i].isEmpty){
                index = i;
                break;
            }
        }
    }
return index;
}

//Baja empleado
int removeEmployee(Employee* list, int len, int id)
{
    int todoOk = -1;
    int index;
    int confirma;

    if(list != NULL && len > 0){
        //Guardo el indice correspondiente al id que pasamos por parámetro en mi variable
        index = findEmployeeById(list, len, id);

        if(index == -1){
            printf("No hay ningún empleado registrado con el ID %d \n", id);
        }
        else{
            mostrarEmpleado(list[index]);
            confirma = getChar("Confirma la baja? s/n: ");
            confirma = tolower(confirma);
            if(confirma == 's'){
                //Vacío el lugar
                list[index].isEmpty = 1;
                todoOk = 0;
            }
        }

    }

    return todoOk;
}

//Ordeno el listado de empleados
int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmp;
    int todoOk = -1;
    float totSalario = 0;
    int contEmployee = 0;
    float promSalario;
    int contEmployeeMayorSueldo = 0;

    if(list != NULL && len > 0){
        switch(order){
            //Ordeno por alfabeto y sector
            case 1:
                for(int i = 0; i < len-1; i++){
                    for(int j = i+1; j < len; j++){
                        if(list[i].sector > list[j].sector){
                            auxEmp = list[i];
                            list[i] = list[j];
                            list[j] = auxEmp;
                        }
                        else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0){
                            auxEmp = list[i];
                            list[i] = list[j];
                            list[j] = auxEmp;
                        }
                    }
                }
                printEmployees(list, len);
                todoOk = 0;

                break;
            case 2:
                //Muestro total y promedio de salarios. Muestro empleados por encima del promedio de salarios
                for(int i = 0; i < len; i++){
                    if(!list[i].isEmpty){
                        totSalario += list[i].salary;
                        contEmployee++;
                        }
                    }
                promSalario = totSalario/contEmployee;

                for(int i = 0; i < len; i++){
                    if(list[i].salary > promSalario){
                        contEmployeeMayorSueldo++;
                    }
                }
                printf("El total de los salarios es de: $%.2f.\nEl promedio es de: %.2f.\nLa cantidad de empleados que superan el salario promedio es: %d\n\n",totSalario,promSalario,contEmployeeMayorSueldo);
                todoOk = 0;
                break;
        }
    }

return todoOk;
}

//Imprimo el listado de empleados
int printEmployees(Employee* list, int length)
{
    int retorno = -1;
    int flag = 1;
    printf("      Listado de Empleados\n\n");
    printf("Legajo          Nombre          Apellido          Sueldo          Sector\n");
   if(list != NULL && length > 0){
        for(int i = 0; i < length; i++){
            if(!list[i].isEmpty){ //Entro cuando esto valga 0, cuando no esté vacía la estructura.
                mostrarEmpleado(list[i]);
                flag = 0;
            }
        }
        printf("\n");
        if(flag){
            printf("No se pueden mostrar datos.");
        }
        printf("\n");
        printf("\n");
    }
    retorno = 0;
    return retorno;
}

//Muestro un empleado
void mostrarEmpleado(Employee unEmpleado){
    printf("  %d          %10s        %10s          %.2f            %d\n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.salary,
           unEmpleado.sector
           );
}

//Busco el primer espacio libre en el array y devuelvo su índice
int freePlaceIndex(Employee list[], int len){
//Inicializo con un indice que no es posible para que el retorno no devuelva basura
    int index = -1;

    if(list != NULL && len > 0){
        for(int i = 0; i < len; i++){
            //Analizo si está vacío
            if(list[i].isEmpty){
                //De estarlo, devuelvo el indice
                index = i;
                //Rompo para que muestre el primer lugar libre
                break;
            }
        }
    }
    return index;
}

//Modifico empleado
int modifyEmployee(Employee* list, int length, int id){
    Employee empAux;
    int index;
    int opcion;
    int todoOk = 0;

    index = findEmployeeById(list, length, id);

    if(list != NULL && length > 0){
        if(index == -1){
        printf("No hay empleados con ese ID\n");
    }
    else{
        empAux = list[index];
        mostrarEmpleado(empAux);
        printf("1. Nombre\n");
        printf("2. Apellido\n");
        printf("3. Salario\n");
        printf("4. Sector\n");
        utn_getNumero(&opcion, "Ingrese opcion: ", "Error. Reingrese opcion\n", 1, 4, 2);

        switch(opcion){
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(empAux.name);
            while(!esSoloLetras(empAux.name) || strlen(empAux.name) > 51){
                printf("Error. Ingrese nombre: ");
                fflush(stdin);
                gets(empAux.name);
            }
            break;
        case 2:
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(empAux.lastName);
            while(!esSoloLetras(empAux.lastName) || strlen(empAux.lastName) > 51){
                printf("Error. Ingrese apellido: ");
                fflush(stdin);
                gets(empAux.lastName);
            }
            break;
        case 3:
            utn_getNumeroFlotante(&empAux.salary, "Ingrese salario: ", "Error. Reingrese salario: ", 1, 1000000, 2);
            break;
        case 4:
            utn_getNumero(&empAux.sector, "Ingrese ID sector: ", "Error. Reingrese ID sector\n",1,1000,2);
            break;
        }
        mostrarEmpleado(empAux);
        opcion = getChar("Confirma cambios? s/n: ");
        opcion = tolower(opcion);
        if(opcion == 's'){
            list[index] = empAux;
            todoOk = 1;
        }
        else{
            printf("Modificación cancelada por el usuario. \n");
        }
    }
    }
    return todoOk;
}
