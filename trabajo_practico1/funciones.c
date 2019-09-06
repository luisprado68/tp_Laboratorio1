#include <stdio.h>
#include <stdlib.h>

/**
*\brief la funcion suma los numeros ingresados de a y b
*\param numero entero 1
*\param numero entero 2
*\return el resultado de la suma.
*
*/
int suma(int a , int b){

    int total;
    total = a + b;
    return total;

}
/**
*\brief la funcion resta los numeros ingresados de a y b
*\param numero entero 1
*\param numero entero 2
*\return el resultado de la resta.
*
*/
int resta( int a, int b){
    int total;
    total = a - b;
    return total;
}
/**
*\brief la funcion multiplica los numeros ingresados de a y b
*\param numero entero 1
*\param numero entero 2
*\return el resultado de la multiplicacion.
*
*/
int multiplicacion(int a , int b){
    int total;
    total = a * b;
    return total;

}
/**
*\brief la funcion divide los numeros ingresados de a y b
*\param numero entero 1
*\param numero entero 2
*\return retorna el resultado en numero flotante como resultado de la division.
*
*/
float division(int a, int b){
    float total;
    total = (float) a/b;
        return total;
    }


/**
*\brief la funcion factorial para el numero ingresado de a.
*\param numero entero 1
*\return retorna el resultado del factorial.
*
*/

int factorialA( int a){
    int respuesta;
    if(a==1)
        return 1;
    respuesta = a* factorialA(a-1);
    return(respuesta);


}
/**
*\brief la funcion factorial para el numero ingresado de b.
*\param numero entero 2
*\return retorna el resultado del factorial.
*
*/
int factorialB( int b){
    int respuesta;
    if(b==1)
        return 1;
    respuesta = b* factorialB(b-1);
    return(respuesta);


}


