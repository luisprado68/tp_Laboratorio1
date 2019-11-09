#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
   int cantidad;
   char id[10];
   char nombre[32];
   char horas[20];
   char sueldo[30];

   if(pFile!=NULL && pArrayListEmployee!=NULL){

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

    while(!feof(pFile)){

        cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
        if(cantidad !=4){
            printf("Error en cargar los archivos!\n");
            break;
        }
        else{
            Employee* empleado=employee_newParametros(atoi(id),nombre,atoi(horas),atoi(sueldo));
            if(empleado!=NULL){

                ll_add(pArrayListEmployee,empleado);
                todoOk=1;
            }

        }

    }


   }
   else{
    printf("Archivo vacio!\n");
   }

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int cantidad;
    if(pFile!=NULL && pArrayListEmployee!=NULL){

        while(!feof(pFile)){

            Employee* empleado=employee_new();
            if(empleado==NULL){
                break;
            }

               cantidad= fread(empleado,sizeof(Employee),1,pFile);

                if(cantidad<1){
                  break;
                }
                else{
                    ll_add(pArrayListEmployee,empleado);
                    todoOk=1;
                }


        }
    }

    return todoOk;
}
