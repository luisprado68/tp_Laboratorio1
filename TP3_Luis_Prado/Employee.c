#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Employee* employee_new(){

Employee* nuevo;

nuevo=(Employee*)malloc(sizeof(Employee));

    if(nuevo!=NULL){

       nuevo->id=0;
       strcpy(nuevo->nombre," ");
       nuevo->horasTrabajadas=0;
       nuevo->sueldo=0;
    }

return nuevo;
}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo){

    Employee* this=employee_new();

    if(this!=NULL){

        if(employee_setId(this,id)&&
        employee_setNombre(this,nombre)&&
        employee_setHorasTrabajadas(this,horasTrabajadas)&&
        employee_setSueldo(this,sueldo)==0){

            free(this);
            this=NULL;

        }
    }

    return this;

}

int employee_setId(Employee* this,int id){

    int todoOk=0;
    if(this !=NULL && id>=1 ){
            this->id=id;
            todoOk=1;

    }
    return todoOk;
}

int employee_getId(Employee* this,int* id){

    *id=-1;
    if(this!= NULL){
        *id=this->id;

    }
    return *id;
}

int employee_setNombre(Employee* this,char* nombre){

    int todoOk=0;
    if(this !=NULL && nombre!=NULL&& strlen(nombre) >=2){
            strcpy(this->nombre,nombre);
            todoOk=1;

    }
    return todoOk;

}

int employee_getNombre(Employee* this,char* nombre){

    int todoOk=0;
    if(this !=NULL && nombre!=NULL){
            strcpy(nombre,this->nombre);
            todoOk=1;

    }
    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int todoOk=0;
    if(this !=NULL && horasTrabajadas>=1 && horasTrabajadas<=500){
            this->horasTrabajadas=horasTrabajadas;
            todoOk=1;

    }
    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

     *horasTrabajadas=-1;
    if(this!= NULL){
        *horasTrabajadas=this->horasTrabajadas;

    }
    return *horasTrabajadas;
}

int employee_setSueldo(Employee* this,int sueldo){

     int todoOk=0;
    if(this !=NULL && sueldo>=10000 && sueldo<=50000){
            this->sueldo=sueldo;
            todoOk=1;

    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo){

     *sueldo=-1;
    if(this!= NULL){
        *sueldo=this->sueldo;

    }
    return *sueldo;
}

int mostrarEmpleado(Employee* empleado)
{
    int todoOk = 0;

    if( empleado != NULL )
    {
        printf(" %d  %20s %d %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        todoOk = 1;
    }
    return todoOk;
}
