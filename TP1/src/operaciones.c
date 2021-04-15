/*
 * operaciones.c
 *
 *  Created on: 13 abr. 2021
 *      Author: rragm
 */


#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

//Suma
int suma(int a, int b){
return a + b;
}

//Resta
int resta(int a, int b){
return a - b;
}

//División
float dividir(int a, int b, float* c){
float todoOk = 0;

    if(b != 0 && c != NULL){
        *c = (float)a/b;
        todoOk = 1;
    }
    return todoOk;
}

//Multiplicación
int multiplicacion(int a, int b){
return a*b;
}

//Factorial
int factorial(int n){
int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}
