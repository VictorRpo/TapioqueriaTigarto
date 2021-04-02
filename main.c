#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	//solicitud de los platos
	int contador=0;
	FILE* flujo=fopen("pedido.txt", "rd");
	if(flujo==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	char cadena[100];-+

	while(feof(flujo)==0){
		fscanf(flujo, "%s\n", cadena);

		/*Utilizaré la funcion atoi de c para convertir
		de cadena a numero*/
		if(isdigit(*cadena)){

			printf("\n %d",(atoi(cadena)+1));
			contador++;
		}
		/* El siguiente bucle lee caracteres uno a uno y los imprime en pantalla. */
	    while (!feof (flujo)) {
			c = getc (flujo);
	    	printf ("%c", c);
	   }
	}

	fclose(flujo);
	printf("\n Se ha leido el archivo correctamente!! %d\n", contador);

	return 0;
	//solicitud de los platos
	//validar que sean 2,3 o 4
	//si es 1 solo plato, solicitar al cliente que pida mas platos
	//si es mayor de 4, solicitar que divida el pedido en varios pedidos
	//validar existencia de los platos en el vector que contiene cantidad de platos disponibles
	//se envia como argumento un archivo con el formato ___
	//validar primera linea (4 enteros: 1. indica la cantidad de platos pedidos, 2. # de platos de 2, 3. # platos de 3, 4. # platos 4
	//describir cada plato
	//validar que el # de lineas del archivo == al primer # de la primer linea
	// validar que la suma de los elementos n>1 son igual a n(0)
	//validar que cada linea de platos corresponda el numero (cantidad) con la cantidad escrita de ingredientes
	//validar que cada ingrediente sea alfanumerico, minuscula, no mayor a 20 caracteres y no caracteres especiales
	//los ingredientes son separados por _
	//controlar caracter nueva linea al final de cada linea de codigo
	//validar que si  2 platos son iguales, ambos se incluyen
    //validar que si los ingredientes estan en desoren son el mismo plato
}
