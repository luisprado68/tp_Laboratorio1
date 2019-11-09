#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "funcionesGenerales.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todo=0;
    FILE * pArchivo=NULL;
    pArchivo=fopen(path,"r");

    if(pArchivo== NULL && pArrayListEmployee==NULL){
        printf("Error en la apertura del archivo!\n");
        exit(EXIT_FAILURE);
        system("pause");

    }
    ll_clear(pArrayListEmployee);
    parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    todo=1;

    fclose(pArchivo);
    return todo;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* pArchivo=NULL;
    pArchivo=fopen(path,"rb");

    if(pArchivo==NULL){
        printf("Error en la apertura del Archivo!\n");
        exit(EXIT_FAILURE);
        system("Pause");
    }

    ll_clear(pArrayListEmployee);
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    todoOk=1;
    fclose(pArchivo);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* nuevo=employee_new();
    int id;
    char nombre[32];
    int horas;
    int sueldo;

    if(nuevo!=NULL && pArrayListEmployee!=NULL){


    id=controller_getMayorId(pArrayListEmployee);
    id++;
    todoOk=employee_setId(nuevo,id);
    getValidStringCharacter("ingrese un nombre:\n",nombre,32);
    todoOk=employee_setNombre(nuevo,nombre);

    horas=getIntValid("Ingrese horas trabajadas:\n");
    todoOk = employee_setHorasTrabajadas(nuevo,horas);

    sueldo=getIntValid("Ingrese sueldo:\n");
    todoOk= employee_setSueldo(nuevo,sueldo);

    ll_add(pArrayListEmployee,nuevo);
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;


    int idModificar;
    char nombre[32];
    int horas;
    int sueldo;
    int opcion;
    char respuesta;
    int encontro=0;

     Employee* empleado;

     if(pArrayListEmployee!= NULL){

     idModificar=getIntValid("\nIngrese un id a modificar:\n");

        for(int i=0;i<ll_len(pArrayListEmployee);i++){

            empleado=ll_get(pArrayListEmployee,i);


            if(idModificar== empleado->id){
                encontro=1;
                printf("Empleado encontrado:\n");
                break;

            }
        }
        if(encontro){
        mostrarEmpleado(empleado);

            do{

            opcion=getValidInt("\n----Menu  Modificar----\n\n1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n4-Salir\nIngrese una opcion a modificar:\n",1,4);
            switch(opcion){

            case 1:
                    respuesta=getCharCharacter("Desea modificar nombre?(s/n)",'S','N');
                    if(respuesta=='S'){
                        getValidStringCharacter("ingres un nombre:\n",nombre,32);
                        employee_setNombre(empleado,nombre);
                        todoOk=1;
                         break;
                    }
                break;

            case 2:
                    respuesta=getCharCharacter("Desea modificar Horas Trabajadas?(s/n)",'S','N');
                        if(respuesta=='S'){
                            horas=getIntValid("ingres horas trabajadas:\n");
                            employee_setHorasTrabajadas(empleado,horas);
                            todoOk=1;
                             break;
                        }

                break;
            case 3:
                    respuesta=getCharCharacter("Desea modificar sueldo?(s/n)",'S','N');
                        if(respuesta=='S'){
                            sueldo=getIntValid("ingres sueldo:\n");
                            employee_setSueldo(empleado,sueldo);
                            todoOk=1;
                             break;
                        }
                break;
            }
        }while(opcion!=4);


        }
        else{
            printf("no se encontro el id\n\n");
            todoOk=0;
        }

     }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int idBaja;
    char respuesta;
    int encontro=0;

     Employee* empleado;

    idBaja=getIntValid("\nIngrese un id a dar de baja:\n");

        for(int i=0;i<ll_len(pArrayListEmployee);i++){

            empleado=ll_get(pArrayListEmployee,i);


            if(idBaja== empleado->id){
                encontro=1;
                printf("Empleado encontrado: %s\n",empleado->nombre);
                respuesta=getCharCharacter("Desea dar de baja ?(s/n)",'S','N');
                    if(respuesta=='S'){

                    ll_remove(pArrayListEmployee,i);
                    todoOk=1;
                    }

                break;

            }

        }
        if(encontro!=1){
            printf("no se encontro el id\n");
            todoOk=0;
        }




    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado= employee_new();

    if(empleado!=NULL){

        for(int i=0;i<ll_len(pArrayListEmployee);i++){

            empleado= ll_get(pArrayListEmployee,i);
            mostrarEmpleado(empleado);

        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado=employee_new();
    Employee* empleado2=employee_new();
    Employee* aux=employee_new();

    int todoOk=0;

    for(int i=0;i<ll_len(pArrayListEmployee)-1;i++){

            empleado=ll_get(pArrayListEmployee,i);

        for(int j=i+1;j<ll_len(pArrayListEmployee);j++){
            empleado2=ll_get(pArrayListEmployee,j);

            if(empleado->sueldo>empleado2->sueldo){
                *aux=*empleado;
                *empleado=*empleado2;
                *empleado2=*aux;
                todoOk=1;
            }
        }

    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=-1;

    Employee* empleado;

    FILE* pArchivo;
    pArchivo=fopen(path,"w");

    if(pArchivo!=NULL && pArrayListEmployee!= NULL){

        fprintf(pArchivo,"Id,Nombre,Horas Trabajas,Sueldo\n");


        for(int i=0;i<ll_len(pArrayListEmployee);i++){

            empleado=ll_get(pArrayListEmployee,i);
            fprintf(pArchivo,"%d,%s,%d,%d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
            todoOk=0;
        }
    fclose(pArchivo);
    }
    else{
        printf("Error en la apertura del archivo\n");
        exit(EXIT_FAILURE);
        system("pause");
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    int todoOk=-1;

    FILE* pArchivo=NULL;
    Employee* empleado;

    pArchivo=fopen(path,"wb");

    if(pArchivo!=NULL && pArrayListEmployee!=NULL){

        for(int i=0;i<ll_len(pArrayListEmployee);i++){

            empleado=ll_get(pArrayListEmployee,i);
           fwrite(empleado,sizeof(Employee),1,pArchivo);


        }
        todoOk=0;
        fclose(pArchivo);

    }

    return todoOk;
}

int controller_getMayorId(LinkedList* pArrayListEmployee)
{

    int i;
    int idMayor;
    int flag=0;
    Employee* emp;

    if(ll_isEmpty(pArrayListEmployee)==0)
    {
        for( i=0; i< ll_len(pArrayListEmployee); i++)
        {
            emp=ll_get(pArrayListEmployee, i);

                if(emp->id > idMayor || flag == 0)
                {
                    idMayor = emp->id;
                    flag=1;
                }
        }
    }
    else
    {
        idMayor = -1;
    }

    return idMayor;
}
