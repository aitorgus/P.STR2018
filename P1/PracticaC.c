 /*
==========================================================================================================
 Name        : Implementación de una Calculadora Simple
 Author      : Aitor Gustavo Camacho Gutiérrez
 Version     :
 Asignatura  : SISTEMA TIEMPO REAL
 Description : En esta práctica vamos a implementar una calculadora básica de operaciones binarias. 	
El programa mostrará un menú con las operaciones disponibles y una vez seleccionada la opción deseada, 
pedirá por teclado que se introduzcan los operandos, para luego mostrar el resultado y nuevamente el menú.
 ==========================================================================================================
 */
#include <stdio.h>
#include <string.h> // Para usar string y strcpy
//PROGRAMA PRINCIPAL
int main (void) {
	//Declaración de variables
	int opcion;
	int salida = 0;
	 while(salida == 0){
		 //Se repetirá hasta que el valor de salida cambie
		 
	printf("POR FAVOR SELECCIONE UNA OPCIÓN CORRECTA: \n");
	printf ("1º OR LÓGICO:\n");
	printf ("2º AND LOGICO:\n");
	printf ("3º XOR LÓGICO:\n");
	printf ("4º << Desplazamiento a la izquierda:  \n");
	printf ("5º >> desplazamiento a la derecha: \n");
	printf("6º Cambio de formato: \n");
	printf("7º Habilitar memoria: \n");
	printf("8º Deshabilitar memoria: \n");
	printf("9º Borrar memoria: \n");
	printf("10º Mostrar el contenido de la memoria");
	printf("0º SALIR :  \n" );
							
/*/La función scanf() lee los datos de entrada en el stdin flujo de entrada estándar). Usamos el operador %d pues esperamos un entero
guardamos lo que entre por teclado en la variable "opción"
*/
	
	scanf("%d", &opcion);
        printf("\n");
	
	//ESTRUCTURA CASE, LO USAREMOS COMO NUESTRO MENÚ DE OPCIONES DE LA CALCULADORA
	        switch (opcion){
				case 0:
				salida = 1;
                printf("Ha salido con éxito\n");
				break;
				case 1: 
				printf (" HAS ELEGIDO LA OPCIÓN 'OR LÓGICO' :\n");
				//llamada a la función 
				
				break;
				
				case 2: 
				printf (" HAS ELEGIDO LA OPCIÓN 'AND LÓGICO' :\n");
				
				break;
				case 3: 
				printf (" HAS ELEGIDO LA OPCIÓN 'XOR LÓGICO' :\n");

				break;
				
				case 4:
				printf (" HAS ELEGIDO LA OPCIÓN '<< (DESPLAZAMIENTO A LA IZQUIERDA)' :\n");
				
				break;
				
				case 5: 
				
				printf (" HAS ELEGIDO LA OPCIÓN '>> (DESPLAZAMIENTO A LA DERECHA)' :\n");

				break;
				
				case 6:
				printf (" HAS ELEGIDO LA OPCIÓN 'CAMBIO DE FORMATO' :\n");
				break;
				
				case 7:
				printf (" HAS ELEGIDO LA OPCIÓN 'HABILITAR MEMORIA' :\n");
				break;
				
				case 8:
				printf (" HAS ELEGIDO LA OPCIÓN 'DESHABILITAR MEMORIA' :\n");
				break;
				
				case 9:
				printf (" HAS ELEGIDO LA OPCIÓN 'BORRAR MEMORIA' :\n");

				break;
				
				case 10:
				printf ("HAS ELEGIDO LA OPCIÓN 'MOSTRAR EL CONTENIDO DE MEMORIA' : \n");
				break;
             default:
             /* En el caso en que el usuario inserte un valor erróneo, mostraremos un menú informando del error 
			 */
                salida = 0;
                printf("El valor insertado no es correcto,\n");
                break; 
			
			}

	
	fflush(stdin); // fflush sirve para limpiar el buffer de entrada del teclado, lo usamos tras un scanf
    
    return 0;
	
}
}