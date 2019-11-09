/**
*\brief Solicita un numero al usuario y devuelve el resultado.
*\param mensaje es el mensaje al ser mostrado.
*\return El numero ingresado por el usuario.
*
*/


int getInt(char mensaje[]);
/**
*\brief Solicita un numero al usuario y devuelve el resultado.
*\param mensaje es el mensaje al ser mostrado.
*\return El numero ingresado por el usuario.
*
*/
float getFloat(char mensaje[]);

/**
*\brief Solicita una letra al usuario y devuelve el resultado.
*\param mensaje es el mensaje al ser mostrado.
*\return El numero ingresado por el usuario.
*
*/
char getChar(char mensaje[]);

/**
*\brief Verifica si el valor recibido es numerico.
*\param stra array con la cadena a ser analizada.
*\return 1 si es numerico 0 si no lo es.
*
*/
int esNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
*\brief Verifica si el valor recibido es Telefono.
*\param stra array con la cadena a ser analizada.
*\return 1 si contiene numeros y un guion 0 si no lo es.
*
*/
int esTelefono(char str[]);

/**
*\brief Verifica si el valor recibido es alfanumerico.
*\param stra array con la cadena a ser analizada.
*\return 1 si es numerico 0 si no lo es.
*
*/
int esAlfanumerico(char str[]);

/**
*\brief Verifica si el valor recibido es solo letra.
*\param stra array con la cadena a ser analizada.
*\return 1 si es numerico 0 si no lo es.
*
*/
int esSoloLetras(char str[]);

/**
*\brief Solicita un texto al usuario y lo devuelve.
*\param mensaje, es el mensaje a ser mostrado.
*\param input, array , donde se cargar el texto ingresado.
*\return void.
*
*/

void getString(char mensaje[], char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[], char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

int getValidInt(char respustaMensaje[],int limitaBajo, int limiteAlto);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char respuestaMensaje[],char mensajeError[],char input[]);
/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param a Es el caracter a ingresar
* \param b Es el caracter a ingresar
 * \return El caracter ingresado por el usuario
 *
 */

char getCharCharacter(char mensaje[],char a,char b);
/**
 * \brief Solicita un texto numérico y letras al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números y letras
 */
int getStringLetrasNum(char mensaje[], char input[]);
/**
 * \brief Solicita numeros y letras y cuenta los cantidad de caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param maximo es la cantidad de caracteres maxima a ingresar
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidDomicilio(char requestMessage[], char input[],int maximo);
/**
 * \brief Solicita un string y cuenta los cantidad de caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param maximo es la cantidad de caracteres maxima a ingresar
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidStringCharacter(char requestMessage[], char input[],int maximo);
/**
 * \brief Solicita un string de numeros y cuenta los cantidad de caracteres
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param maximo es la cantidad de caracteres maxima a ingresar
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidStringTelefono(char requestMessage[], char input[],int maximo);
/**
 * \brief compara fechas
 * \param F1 Es la fecha a comparar
 * \param F2 Es la fecha a comparar
 * \return 1 si son iguales y 0 si no lo son-
 *
 */
//int compararFechas( eFecha f1, eFecha f2);

int getIntValid(char respuestaMensaje[]);
