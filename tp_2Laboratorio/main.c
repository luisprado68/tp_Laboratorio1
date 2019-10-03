#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcionesGenerales.h"
#include "empleados.h"

#define CANT 5



int main()
{
    // arrays de eEmpleadosos
    eEmpleados empleado[CANT];
    //________________________________________________
    int idAuxiliar;
    char nombreAuxiliar[51];
    char apellidoAuxiliar[51];
    float salarioAuxiliar;
    int sectorAuxiliar;

   char idAuxStr[51];
    char salarioAuxStr[51];
   char sectorAuxiStr[51];


    int indiceLugarLibre;
    int indiceEncontrado;
    int option = 0;

    int i;

    ponerEstado(empleado,CANT,0);

    while(option != 6)
    {
         option = getInt("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - MOSTRAR\n5 - INFORMAR SOBRE EL PROMEDIO\n6 - SALIR\n");
         switch(option)
         {
            case 1:

                indiceLugarLibre = encontrarLugarLibre(empleado,CANT);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                printf("\nALTA\n");

                if (!getStringNumeros("Ingrese el id: ",idAuxStr))
                {
                    printf ("El id debe ser numerico\n");
                    break;
                }
                idAuxiliar = atoi(idAuxStr);

                if(encontrarEmpleadoCodigo(empleado,CANT,idAuxiliar) != -1)
                {
                    printf("\n\nEL ID YA EXISTE!!!\n");
                    break;
                }


                if (!getStringLetras("Ingrese el nombre: ",nombreAuxiliar))
                {
                    printf ("El nombre  debe estar compuesto solo por letras\n");
                    break;
                }
                if (!getStringLetras("Ingrese el apellido: ",apellidoAuxiliar))
                {
                    printf ("El apellido  debe estar compuesto solo por letras\n");
                    break;
                }
                  if (!getStringNumerosFlotantes("Ingrese el salario: ",salarioAuxStr))
                {
                    printf ("El salario  debe ser numerico\n");
                    break;
                }
                salarioAuxiliar = atof(salarioAuxStr);

                if (!getStringNumeros("Ingrese el sector: ",sectorAuxiStr))
                {
                    printf ("El sector  debe ser numerico\n");
                    break;
                }
                sectorAuxiliar = atof(sectorAuxiStr);

                empleado[indiceLugarLibre].id = idAuxiliar;
                strcpy(empleado[indiceLugarLibre].nombre,nombreAuxiliar);
                 strcpy(empleado[indiceLugarLibre].apellido,apellidoAuxiliar);
                empleado[indiceLugarLibre].salario = salarioAuxiliar;
                empleado[indiceLugarLibre].sector = sectorAuxiliar;
                empleado[indiceLugarLibre].isEmpty = 1;

                break;

            case 2:
                if (!getStringNumeros("Ingrese el id del empleado a dar de baja: ",idAuxStr))
                {
                    printf ("El el id de empleado debe ser numerico\n");
                    break;
                }
                idAuxiliar = atoi(idAuxStr);
                indiceEncontrado = encontrarEmpleadoCodigo(empleado,CANT,idAuxiliar);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID");
                    break;
                }
                empleado[indiceEncontrado].isEmpty = 0;
                break;

            case 3:
                if (!getStringNumeros("Ingrese el ID a modificar: ",idAuxStr))
                {
                    printf ("El id de empleado debe ser numerico\n");
                    break;
                }
                idAuxiliar = atoi(idAuxStr);
                indiceEncontrado = encontrarEmpleadoCodigo(empleado,CANT,idAuxiliar);
                if(indiceEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }



               if (!getStringLetras("Ingrese el nombre: ",nombreAuxiliar))
                {
                    printf ("EL nombre  debe estar compuesto solo por letras\n");
                    break;
                }
                if (!getStringLetras("Ingrese el apellido: ",apellidoAuxiliar))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }
                  if (!getStringNumerosFlotantes("Ingrese el salario: ",salarioAuxStr))
                {
                    printf ("El salario  debe ser numerico\n");
                    break;
                }
                salarioAuxiliar = atof(salarioAuxStr);

                if (!getStringNumeros("Ingrese el sector: ",sectorAuxiStr))
                {
                    printf ("El sector debe ser numerico\n");
                    break;
                }
                sectorAuxiliar = atoi(sectorAuxiStr);



                strcpy(empleado[indiceEncontrado].nombre,nombreAuxiliar);

                strcpy(empleado[indiceEncontrado].apellido,apellidoAuxiliar);
                empleado[indiceEncontrado].salario = salarioAuxiliar;
                empleado[indiceEncontrado].sector = sectorAuxiliar;
                empleado[indiceEncontrado].isEmpty = 1;
                break;

            case 4:
                printf("\nLISTAR y ORDENAR\n");

                ordenamiento(empleado,CANT);
                for(i=0;i < CANT; i++)
                {
                    if(empleado[i].isEmpty != 0)
                    {
                        printf("\n%d - %s  - %s - %.2f - %d",empleado[i].id,empleado[i].nombre,empleado[i].apellido,empleado[i].salario,empleado[i].sector);
                    }
                }
                break;

            case 5:
                printf("\nINFORMAR PRODUCTOS POR ENCIMA DEL PROMEDIO\n");
                salarioAuxiliar = promedioSalario(empleado,CANT);
                if(salarioAuxiliar == -1)
                {
                     printf("\nNO HAY PRODUCTOS\n");
                     break;
                }
                printf("\nEl promedio total es de: %f\n\n Los empleados que superan el promedio son: \n\n",salarioAuxiliar);

                for(i=0;i < CANT; i++)
                {
                    if(empleado[i].salario > salarioAuxiliar && empleado[i].isEmpty == 1)
                    {
                        printf("\n%d - %s  - %s - %.2f - %d",empleado[i].id,empleado[i].nombre,empleado[i].apellido,empleado[i].salario,empleado[i].sector);
                    }
                }
                break;

         }
    }


    return 0;
}


