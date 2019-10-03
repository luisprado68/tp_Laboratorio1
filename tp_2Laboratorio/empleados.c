#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcionesGenerales.h"
#include "empleados.h"

#define CANT 5


/**
 * \brief Inicializa el status en un array de Empleados
 * \param empleado Es el array en el cual buscar
 * \param cantidadElementos  Indica la logitud del array
 * \param value Es el valor que se asignara a estatus
 * \return -
 *
 */
void ponerEstado(eEmpleados empleado[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        empleado[i].isEmpty = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un empleado mediante su id
 * \param empleado Es el array en el cual buscar
 * \param cantidadElemento  Indica la logitud del array
 * \param id Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int encontrarEmpleadoCodigo(eEmpleados empleado[],int cantidadElementos,int id)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(empleado[i].id == id && empleado[i].isEmpty == 1)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param empleado Es el array en el cual buscar
 * \param cantidadEmpleado Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int encontrarLugarLibre(eEmpleados empleado[],int cantidadElementos)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Busca el  promedio del salario
 * \param empleado Es el array en el cual buscar
 * \param cantidadEmpleado Indica la logitud del array
 * \return Si no hay productos activos (-1) y si lo hay el salario  de ese empleado.
 *
 */

float promedioSalario(eEmpleados empleado[],int cantidadElementos)
{
    int i;
    float salarioTotal = 0;
    int empleadosActivos = 0;
    float promedioTotal;

    for(i=0;i < cantidadElementos; i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            salarioTotal = salarioTotal + empleado[i].salario;
            empleadosActivos++;
        }
    }
    if(empleadosActivos == 0)
        return -1;

    promedioTotal = salarioTotal / (float)empleadosActivos;
    return promedioTotal;
}

/**
 * \brief Busca el precio promedio
 * \param empleado Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay productos activos (-1) y si lo hay el precio de ese producto
 *
 */
void ordenamiento(eEmpleados empleado[],int cantidadElementos)
{
    eEmpleados empleadoAux;
    int i,j;

    for(i=0; i < CANT - 1; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            continue;
        }
        for(j=i+1; j < CANT; j++)
        {
            if(empleado[j].isEmpty == 0)
            {
                continue;
            }
            if(strcmp(empleado[j].apellido,empleado[i].apellido))
            {
                empleadoAux = empleado[j];
                empleado[j] = empleado[i];
                empleado[i] = empleadoAux;
            }
            else if(empleado[j].sector > empleado[i].sector)
            {

                    empleadoAux = empleado[j];
                    empleado[j] = empleado[i];
                    empleado[i] = empleadoAux;
                }
            }
        }
    }

