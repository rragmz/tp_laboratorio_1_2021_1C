
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

#define TAM 30


int controller_loadFromText(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int nextId = 1;
    FILE* f = NULL;

    f = fopen("data.csv", "r");


    if(f == NULL)
    {
        printf("No se puede abrir el archivo");
    }
    else
    {
        if(parser_EmployeeFromText(f, pArrayListEmployee) != 0){
            printf("Datos cargados con éxito\n");
            todoOk = 1;
        }
        fclose(f);
    }

   controller_mayorId(pArrayListEmployee, &nextId);

    return todoOk;

}

int controller_loadFromBinary(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int nextId = 1;
    FILE* f = NULL;

    f = fopen("data.bin", "rb");


    if(f == NULL)
    {
        printf("No se puede abrir el archivo");
    }
    else
    {
        if(parser_EmployeeFromBinary(f, pArrayListEmployee)){
            printf("Datos cargados con éxito\n");
        }
        fclose(f);
    }

   controller_mayorId(pArrayListEmployee, &nextId);

    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	Employee* auxEmp;
	int auxId;
	char idChar[TAM];
	char nombre[TAM];
	char horasTrabajadas[TAM];
	int auxHoras;
	char sueldo[TAM];
	int auxSueldo;
	if(pArrayListEmployee!=NULL)
	{
	    controller_mayorId(pArrayListEmployee, &auxId);
		printf("ID: %d \n", auxId);

		//Como lo voy a usar en newEmpleadoParam, necesito el ID en char, lo parseo
		sprintf(idChar, "%d", auxId);

		//Pido los datos mediante la biblioteca utn. Si todas arrojan 0, los datos están validados

        if(!(getString(nombre, "Ingrese nombre: ", "Error. Reingrese nombre: ", 1, 30, 3)) &&
           !(utn_getNumero(&auxHoras, "Ingrese horas trabajadas: ", "Error. Reingrese horas: ", 1, 400, 3)) &&
           !(utn_getNumero(&auxSueldo, "Ingrese sueldo: ", "Error. Reingrese sueldo: ", 1, 1000000, 3)))
        {
            sprintf(horasTrabajadas, "%d", auxHoras);
            sprintf(sueldo, "%d", auxSueldo);
			auxEmp = employee_newParametros(idChar, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, auxEmp);
			todoOk = 1;
        }

		printf("Empleado agregado exitosamente\n");
	}
    return todoOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int idModificar;
    int posicion;
    int opcion;
    char auxNombre[30];
    int auxHoras;
    int auxSueldo;

    Employee* auxEmp = NULL;


    utn_getNumero(&idModificar, "Ingrese Id a modificar: ", "Error, reingrese el Id a modificar: ", 1, 2000, 3);
    posicion = employee_findEmployeeById(pArrayListEmployee, idModificar);

    if(posicion == -1){
        printf("No se encontraron empleados con ese Id\n");
    }
    else{
        auxEmp = (Employee*)ll_get(pArrayListEmployee, posicion);

        utn_getNumero(&opcion, "Qué desea modificar?: \n1. Nombre\n2. Horas trabajadas\n3. Sueldo\nIngrese opción: ",
                      "Error, reingrese: ", 1, 3, 3);

        switch(opcion){
            case 1:
                if(!(getString(auxNombre, "Ingrese nombre: ", "Error. Reingrese nombre: ", 1, 30, 3))){
                    employee_setNombre(auxEmp, auxNombre);
                }
                break;

            case 2:
                if(!(utn_getNumero(&auxHoras, "Ingrese las horas trabajadas: ", "Error. Reingrese las horas trabajadas: ",
                    1, 500, 3))){
                    employee_setHorasTrabajadas(auxEmp, auxHoras);
                }
                break;

            case 3:
                if(!(utn_getNumero(&auxSueldo, "Ingrese las horas trabajadas: ", "Error. Reingrese las horas trabajadas: ",
                     1, 1000000, 3))){
                    employee_setSueldo(auxEmp, auxSueldo);
                }
                break;
            }
            todoOk = 1;
    }

    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int idEliminar;
    int posicion;
    char confirma;


    if(pArrayListEmployee != NULL){
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumero(&idEliminar, "Ingrese Id a eliminar: ", "Error, reingrese el Id a eliminar: ", 1, 2000, 3);
        posicion = employee_findEmployeeById(pArrayListEmployee, idEliminar);

        if(posicion == -1){
            printf("No se encontraron empleados con ese Id\n");
        }
        else{
            printf("Confirma la eliminación del ID: %d (s/n): ", idEliminar);
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's'){
                ll_remove(pArrayListEmployee, posicion);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
	Employee* auxEmp;
	if(pArrayListEmployee != NULL)
	{
		printf("ID     Nombre    Horas Trabajadas    Sueldo \n");
		for(int i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
			printf("%d   %10s    %d   %d\n",auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
		}
		todoOk = 1;
	}
    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int todoOk;

    if(pArrayListEmployee != NULL){
        utn_getNumero(&opcion, "Ingrese cómo desea ordenar:\n1.Nombre ascendente\n2.Menos horas trabajadas a más horas\n3.Menor sueldo a mayor sueldo\n", "Error, reingrese opción: ", 1, 3, 3);

        switch(opcion){
            case 1:
                ll_sort(pArrayListEmployee, empleadoCmpNombre, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                ll_sort(pArrayListEmployee, empleadoCmpHoras, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                ll_sort(pArrayListEmployee, empleadoCmpSueldo, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
        }
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsText(LinkedList* pArrayListEmployee)
{
    char confirma;
    int todoOk = 1;
    int auxId;
    char auxNombre[30];
    int auxHoras;
    int auxSueldo;


    Employee* auxEmp;
    FILE* f = NULL;

    f = fopen("data.csv", "r");

    if(f != NULL)
    {
        //Si llega a existir, aviso
        printf("Cuidado el archivo existe, se va a sobreescribir. Confirma? (s/n): \n");
        fflush(stdin);
        scanf("%c", &confirma);
    }
    //Cierro el archivo
    fclose(f);

    if(confirma == 's'){
        //Si acepta sobre escribir, lo voy a abrir en modo escritura
        f = fopen("data.csv", "w");
        if(f == NULL){
            printf("No se pudo abrir el archivo\n");
        }
        else{
            //Guardo el archivo
            for(int i = 0; i < ll_len(pArrayListEmployee); i++){
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(auxEmp, &auxId);
                employee_getNombre(auxEmp, auxNombre);
                employee_getHorasTrabajadas(auxEmp, &auxHoras);
                employee_getSueldo(auxEmp,&auxSueldo);
                fprintf(f,"%d,%s,%d,%d", auxId, auxNombre, auxHoras, auxSueldo);
                todoOk = 1;
            }
            fclose(f);
        }
    }
    return todoOk;
}

int controller_saveAsBinary(LinkedList* pArrayListEmployee)
{
    char confirma = 's';
    int todoOk = 1;

    Employee* auxEmp;
    FILE* f = NULL;

    f = fopen("data.bin", "rb");


    if(f != NULL)
    {
        //Si llega a existir, aviso
        printf("Cuidado el archivo existe, se va a sobreescribir. Confirma? (s/n): \n");
        fflush(stdin);
        scanf("%c", &confirma);
    }
    //Cierro el archivo
    fclose(f);

    if(confirma == 's'){
        //Si acepta sobre escribir, lo voy a abrir en modo escritura
        f = fopen("data.csv", "wb");
        if(f == NULL){
            printf("No se pudo abrir el archivo\n");
        }
        else{
            //Guardo el archivo
            for(int i = 0; i < ll_len(pArrayListEmployee); i++){
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(auxEmp, sizeof(Employee), 1, f);
            }
            todoOk = 1;
        }
        fclose(f);
    }
    return todoOk;
}

int controller_mayorId(LinkedList* pArrayListEmployee, int* pId){
    int todoOk = 0;
    int mayor;
    Employee* auxEmp = NULL;
    if(pArrayListEmployee != NULL && pId != NULL){
        for(int i = 0; i < ll_len(pArrayListEmployee); i++){
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                if(i == 0 || auxEmp->id > mayor){
                    mayor = auxEmp->id;
                }
        }
        *pId = mayor + 1;
        printf("\n");
        todoOk = 1;
    }
    return todoOk;
}

