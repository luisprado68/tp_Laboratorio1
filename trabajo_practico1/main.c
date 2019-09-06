#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    int x=0;
    int y=0;
    int z;
    float zf;
    char continuar = 's';
    char dato[2];
    int opcion=0;

    while(continuar=='s'){
        system("cls");
        printf("1- Ingresar 1er operando (A=%d)\n",x);
        printf("2- Ingresar 2do operando (B=%d)\n",y);
        printf("3- Calcular La Suma (%d+%d)\n",x,y);
        printf("4- Calcular La Resta (%d-%d)\n",x,y);
        printf("5- Calcular La Multiplicacion (%d*%d)\n",x,y);
        printf("6- Calcular La Division (%d/%d)\n",x,y);
        printf("7- Calcular El Factorial (%d!)\n",x,y);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");


         scanf("%d",&opcion);

        switch(opcion){

            case 1:
         printf("ingresar valor A\n");
                fflush(stdin);
                gets(dato);
                x=atoi(dato);
                break;

            case 2:

                printf("ingresar valor B\n");
                fflush(stdin);
                gets(dato);
                y=atoi(dato);
                break;
            case 3:
                z = suma(x,y);
                printf("El resultado de A + B es: %d",z);
                system("PAUSE");
                break;
            case 4:
                 z = resta(x,y);
                printf("\nEl resultado de A - B es: %d",z);
                system("PAUSE");
                break;
            case 5:
                z = multiplicacion(x,y);
                printf("\nEl resultado de A * B es: %d",z);
                system("PAUSE");
                break;
            case 6:
                 zf = division(x,y);
                if(y==0){
                    printf("Error no se puede dividir por 0");
                    system("PAUSE");
                    break;
                }
                else{
                printf("\nEl resultado de A / B es: %.2f",zf);
                system("PAUSE");
                break;
                }


            case 7:
                 x = factorialA(x);
                y = factorialB(y);
                printf("\nEl factorial A es: %d y el factorial B es de : %d",x,y);
                system("PAUSE");
                break;
            case 8:
                 z = suma(x,y);
                printf("El resultado de A + B es: %d",z);

                 z = resta(x,y);
                printf("\nEl resultado de A - B es: %d",z);

                z = multiplicacion(x,y);
                printf("\nEl resultado de A * B es: %d",z);

                zf = division(x,y);
                if(y==0){
                    printf("Error no se puede dividir por 0");
                }else{
                     printf("\nEl resultado de A / B es: %.2f",zf);
                }

                x = factorialA(x);
                y = factorialB(y);
                printf("\nEl factorial A es: %d y el factorial B es de : %d",x,y);

                system("PAUSE");
                break;
            case 9:
                continuar='n';

                break;



        }


    };
return 0;
}
