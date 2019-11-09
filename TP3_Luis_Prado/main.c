#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funcionesGenerales.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    option=getValidInt("Ingrese una opcion del menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
     "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
     "3. Alta de empleado\n"
     "4. Modificar datos de empleado\n"
     "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
    "10. Salir\n ",1,10);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)){
                    printf("Empleado cargado con exito!\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados)){
                    printf("Empleado cargado con exito!\n");
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)){
                    printf("Alta exitosa!!\n");
                }
                break;
            case 4:
                    if(ll_isEmpty(listaEmpleados)){
                       printf("No hay elementos cargados!\n");
                        break;
                       }
                    if(controller_editEmployee(listaEmpleados)){
                        printf("Modificacion exitosa!\n");
                    }
                break;
            case 5:
                if(ll_isEmpty(listaEmpleados)){
                       printf("No hay elementos cargados!\n");
                        break;
                       }
                       if(controller_removeEmployee(listaEmpleados)){
                        printf("Baja Exitosa!\n");
                       }

                break;
            case 6:
                    if(ll_isEmpty(listaEmpleados)){
                       printf("No hay elementos cargados!\n");
                        break;
                       }
                        controller_ListEmployee(listaEmpleados);
                    system("pause");
                break;
            case 7:
                if(ll_isEmpty(listaEmpleados)){
                       printf("No hay elementos cargados!\n");
                        break;
                       }
                       if(controller_sortEmployee(listaEmpleados)){
                        printf("Empleado ordenados por sueldo\n");
                       }

                break;
            case 8:
                    if(controller_saveAsText("data.csv",listaEmpleados)!=-1){
                        printf("Empleados guardados con exito!\n");
                    }
                break;
            case 9:
                if(ll_isEmpty(listaEmpleados)){
                    printf("No se cargado la lista!!\n");
                    break;
                }
                    if(controller_saveAsBinary("data.bin",listaEmpleados)!=-1){
                        printf("Empleados guardados en el archivo binario!\n");
                    }
                break;


        }
    }while(option != 10);
    return 0;
}

