
typedef struct{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;

}eEmpleados;

void ponerEstado(eEmpleados empleado[],int cantidadElementos,int valor);
void inicializar(eEmpleados empleado[],int cantidadElementos,int valor);
int encontrarLugarVacio(eEmpleados empleado[],int cantidadElementos);
int encontrarEmpleadoCodigo(eEmpleados empleado[],int cantidadElementos,int code);
float promedioSalario(eEmpleados empleado[],int cantidadElementos);
void ordenamiento(eEmpleados empleado[],int cantidadElementos);
