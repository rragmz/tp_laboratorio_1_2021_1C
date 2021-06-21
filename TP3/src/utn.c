#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utn.h"


int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    int num;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
        while (reintentos>0){
            printf(mensaje);
            if (getInt(&num)==1){
                if (num<=maximo && num>=minimo)
                break ;
            }

            fflush(stdin);
            reintentos--;
            printf(mensajeError);
        }
        if (reintentos==0){
            ret=-1;
        }
        else{
            ret=0;
            *pResultado = num;
        }
}
return ret;
}

float utn_getNumeroFlotante( float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    float num;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

        while (reintentos>0)
            {
            printf(mensaje);
            if(getFloat(&num) == 1){

            if (num<=maximo && num>=minimo){
                break;
            }
            }
            fflush(stdin);
            reintentos--;
            printf(mensajeError);
            }
        if (reintentos==0)
        {
            ret=-1;
        }
        else
        {
            ret=0;
            *pResultado = num;
        }
    }
    return ret;
}


float getFloat(float* pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf( "%s" ,buffer);
    if (esNumericoFlotante(buffer)){
        *pResultado = atof(buffer);
        ret=1;
    }
    return ret;
}


int getInt(int * pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf( "%s" ,buffer);
    if (esNumerico(buffer)){
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int esNumericoFlotante(char str[])
{
    int    retorno = 1;
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           retorno = 0;
       i++;
   }
   return retorno;
}

int esNumerico(char str[])
{
    int i=0;
    int retorno = 1;
    if (str != NULL && strlen (str) > 0){
        while (str[i] != '\0' ){
            if (str[i] < '0' || str[i] > '9' ){
                retorno = 0;
                break ;
            }
            i++;
        }
}
return retorno;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


/*int getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
    return 1;
}*/


/*int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
*/
/*int getNombre(char* pResultado, int longitud){
    int todoOk = 0;
    char buffer[4096];

    if(pResultado != NULL){

        if(getString(buffer, "Ingrese nombre: " ) &&
            esNombre(buffer, sizeof(buffer)) &&
            strlen((buffer) < longitud)){
                strcpy(pResultado, buffer);
                todoOk = 1;
        }
    }
    return todoOk;
}
*/
int esNombre(char* cadena){
    int todoOk = 1;
    if(cadena != NULL){
        for(int i = 0; cadena[i] != '\0' && i < strlen(cadena); i++){
            if((cadena[i] < 'A' || cadena [i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z')){
                todoOk = 0;
                break;
            }
        }
    }
    return todoOk;
}

//No acepta numeros
int utn_getName(char* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
    int retorno = 1;
    char bufferStr[max];

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
            if(!getString(bufferStr, mensaje, mensajeError, min, max, reintentos))
            {
                if(esNombre(bufferStr) == 1)
                {
                    strcpy(pResultado, bufferStr);
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("%s \n",mensajeError);
                    printf("Quedan %d reintentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getString(char* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
    int retorno = -1;
    char bufferStr[max+10];
    // Valida los parametros de la funcion
    if(pResultado != NULL && mensaje !=NULL && mensajeError!=NULL && min <= max && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            fgets(bufferStr, sizeof(bufferStr), stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';

            if(strlen(bufferStr) >= min && strlen(bufferStr) < max)
            {
                strcpy(pResultado, bufferStr);
                retorno=0;
                break;
            }
            else
            {
                printf("%s \n",mensajeError);
                printf("Quedan %d reintentos\n", reintentos);
            }

            reintentos--;
        }
        while(reintentos >= 0);
    }
    return retorno;
}
