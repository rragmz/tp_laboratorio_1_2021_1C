#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char bufferId[1000];
    char bufferNombre[1000];
    char bufferHoras[1000];
    char bufferSueldo[1000];

    Employee* auxEmp;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        //Hago una lectura fantasma de la primera línea
        fscanf(pFile,"[^\n]\n");

        //Mientras que no llegue al final del archivo
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHoras, bufferSueldo);
            auxEmp = employee_newParametros(bufferId, bufferNombre, bufferHoras, bufferSueldo);
            if(auxEmp != NULL)
            {
                ll_add(pArrayListEmployee, auxEmp);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

//}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    char confirma;
    Employee* auxEmp;

    //Pregunto si hay datos
    if(ll_len(pArrayListEmployee) > 0)
    {
        //Pregunto si confirma
        printf("Cuidado, la lista existe y se va a sobreescribir. Confirma? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
    }
    //Si es una lista vacía o si el usuario quiere sobreescribirla
    if(ll_len(pArrayListEmployee) == 0 || confirma == 's')
    {
        //Como aceptó sobreescribir, debería vaciar el archivo así no hay posibilidad de que se pisen datos
        ll_clear(pArrayListEmployee);
        //Mientras que no llegue al final del archivo
        while(!feof(pFile))
        {
            auxEmp = employee_new();
            if(auxEmp != NULL)
            {
                cant = fread(auxEmp, sizeof(Employee), 1, pFile);
                if(cant < 1)
                {
                    break;
                }
                ll_add(pArrayListEmployee, auxEmp);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}
