#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesGenerales.h"


int getInt(char mensaje[]){

    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;

}

float getFloat(char mensaje[]){
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);

    return auxiliar;
}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin); //UNIX
    scanf("%c",&auxiliar);
    return auxiliar;
}

int esNumerico(char str[]){
    int i=0;

    while(str[i]!='\0'){
        if(str[i] < '0'|| str[i] > '9'){
            return 0;
        }
        i++;
    }
    return 1;
}



int esNumericoFlotante(char str[])
{
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
           return 0;
       i++;
   }
   return 1;
}

int esTelefono(char str[]){
int i=0;
int contadorGuiones=0;

    while(str[i]!='\0'){
        if((str[i]!= ' ')&&(str[i]< '0'|| str[i] > '9')&&(str[i]!='-')){
            return 0;
        }
        if(str[i]== '-'){
            contadorGuiones++;
        }
        i++;

    }
    if(contadorGuiones==1){
         return 1;
    }

return 0;
}


int esAlfanumerico(char str[]){
int i=0;

    while(str[i]!='\0'){
        if((str[i]!= ' ')&&(str[i]< 'a'|| str[i] > 'z')&&(str[i]< 'A'|| str[i] > 'Z')&&(str[i]<'0' || str[i]>'9')){
            return 0;
        }
        i++;
    }
    return 1;

}


int esSoloLetras(char str[]){
int i=0;

    while(str[i]!='\0'){
        if((str[i]!= ' ')&&(str[i]< 'a'|| str[i] > 'z')&&(str[i]< 'A'|| str[i] > 'Z')){
            return 0;
        }
        i++;
    }
    return 1;

}

void getString(char mensaje[], char input[]){
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getStringLetras(char mensaje[], char input[]){
    char auxiliar[256];
    getString(mensaje,auxiliar);
        if(esSoloLetras(auxiliar)){
            strcpy(input,auxiliar);
            return 1;
        }
        return 0;
}

int getStringLetrasNum(char mensaje[], char input[]){
    char auxiliar[256];
   printf("%s",mensaje);
   fflush(stdin);
   gets(auxiliar);
        if(esAlfanumerico(auxiliar)){
            strcpy(input,auxiliar);
            return 1;
        }
        return 0;
}


int getStringNumeros(char mensaje[], char input[]){
char auxiliar[256];
    getString(mensaje,auxiliar);
        if(esNumerico(auxiliar)){
            strcpy(input,auxiliar);
            return 1;
        }
        return 0;


}




int getStringFlotantes(char mensaje[],char input[])
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


int getValidInt(char respuestaMensaje[],int limiteBajo, int limiteAlto){

    char auxString[256];
    int auxInt;
    while(1){
        if(!getStringNumeros(respuestaMensaje,auxString)){
            printf("Error solo numeros\n");
            continue;
        }
        auxInt=atoi(auxString);
        if(auxInt<limiteBajo || auxInt>limiteAlto){
            printf("El numero debe estar entre: %d y %d\n",limiteBajo,limiteAlto);
            continue;
        }
        return auxInt;
    }


}

int getIntValid(char respuestaMensaje[]){

    char auxString[256];
    int auxInt;
    while(1){
        if(!getStringNumeros(respuestaMensaje,auxString)){
            printf("Error solo numeros\n");
            continue;
        }
        auxInt=atoi(auxString);
        if(auxInt < 0){
            printf("El numero debe ser mayor a 0");
            continue;
        }
        return auxInt;
    }


}

void getValidString(char respuestaMensaje[],char mensajeError[],char input[]){

    while(1){
        if(!getStringLetras(respuestaMensaje,input)){
            printf("%s\n",mensajeError);
            continue;
        }
        fflush(stdin);
        break;

    }

}


char getCharCharacter(char mensaje[],char a,char b)
{
    char auxiliar;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar = toupper(auxiliar);

    while(auxiliar != a && auxiliar != b)
    {
        printf("\nError  solo las letras [%c/%c] ! Ingrese nuevamente: ",a,b);
        fflush(stdin);
        scanf("%c",&auxiliar);
        auxiliar = toupper(auxiliar);
    }
    return auxiliar;
}

void getValidStringCharacter(char requestMessage[], char input[],int maximo)
{
    int cantidadCaracteres;

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("Error solo letras!\n");
            continue;
        }
        cantidadCaracteres = strlen(input);
        if(cantidadCaracteres > maximo){
            printf("Error.Supero el caracter maximo!\n");
            continue;
        }
         fflush(stdin);
        break;
    }

}

void getValidDomicilio(char requestMessage[], char input[],int maximo)
{
    int cantidadCaracteres;

    while(1)
    {
        if (!getStringLetrasNum(requestMessage,input))
        {
            printf ("Error solo numeros y letras!\n");
            continue;
        }
        cantidadCaracteres = strlen(input);
        if(cantidadCaracteres > maximo){
            printf("Error.Supero el caracter maximo!\n");
            continue;
        }
         fflush(stdin);
        break;
    }

}

void getValidStringTelefono(char requestMessage[], char input[],int maximo)
{
    int cantidadCaracteres;

    while(1)
    {
        if (!getStringNumeros(requestMessage,input))
        {
            printf ("Error solo numeros!\n");
            continue;
        }
        cantidadCaracteres = strlen(input);
        if(cantidadCaracteres > maximo){
            printf("Error.Supero el caracter maximo!\n");
            continue;
        }
         fflush(stdin);
        break;
    }

}

/*int compararFechas( eFecha f1, eFecha f2){
    int sonIguales = 0;

    if( f1.anio == f2.anio && f1.dia == f2.dia && f1.mes == f2.mes){
        sonIguales = 1;
    }
    return sonIguales;

}*/


