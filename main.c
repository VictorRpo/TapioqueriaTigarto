#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Función principal
* Función que realiza todos los procesos para buscar la maximización de la función planteada en la practica
* @author Victor Restrepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
int main(void)
{

	/*
	* Declaración de variables
	* A continuación se declaran todas las variables que son usadas en todo el código
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	int contador=0;
	char* palabra = (char*)malloc(2100*sizeof(char));
	FILE* fp=fopen("pedido.txt", "r");
	char line[1024];
	int linecount = 0;
	int termscount = 0;
	int quantities[4];
	int numingredients = 0;
	int numOfDifferentIngredients = 0;
	char *nullchar = '\0';

	/*
	* Excepción de apertura de archivo
	* A continuación se valida que cuando el archivo no es leido, se debe notificar como respuesta dicho acto;
	* por ello valida inicialmente si la variable p llega nula y en ese caso notifica que hay un error en la apertura del archivo.
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	if(fp==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	
	/*
	* Condicional para controlar la lectura de caracteres del archivo pedido.txt
	* Inicialmente se usa la funcción atoi para convertir de cadena a número 
	* para la primer linea se recupera cada uno de los números relacionados con las cantidades de platos
	* y son asignados a la variable quatities, variable que contendra dicha información.
	* posteriormente se buscan cada uno de los ingredientes encontrados en el archivo pedido.txt
	* y se hace una comparación de todos ellos para obtener todos los ingredientes;
	* para esto, cuando se detecta un ingrediente nuevo, esté es asignado a la variable palabra
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	while (fgets(line,1024,fp))
	{
		char* token;
		char* rest = line;
		if(linecount == 0){
			while((token = strtok_r(rest," ", &rest))){
				quantities[termscount] = atoi(token);
				termscount++;
			}
			linecount++;
		}else{
			token = strtok_r(rest," ", &rest);
			numingredients = atoi(token);
			for(int i=0; i<numingredients; i++){
				token = strtok_r(rest, " ", &rest);
				if(i == numingredients -1){
					char *s =token;
					while(*s != '\n') {
						++s;
					}
					*s = '\0';
				}
				int comparisonSomeIsEqual = -1;
				for(int j=0; j<numOfDifferentIngredients; j++){
					if(strcmp((palabra+(j*21)), token) == 0){
						comparisonSomeIsEqual = 0;
						break;
					}
				}
				if(comparisonSomeIsEqual == -1){
					strcpy((palabra+(numOfDifferentIngredients*21)), token);
					numOfDifferentIngredients++;
				}
			}
		}
	}
	fclose(fp);
	
	
	for(int i=0; i<4; i++){
		printf("%d\n", quantities[i]);
	}

	if (quantities[0] == ((quantities[1]*2)+(quantities[2]*3)+(quantities[3]*4)))
	{
		printf("La cantidad de platos si corresponde a la catidad individual de platos \n");
	}else{
		printf("La cantidad de platos no corresponde a la catidad individual de platos \n");
	}
	
	for(int i=0; i<numOfDifferentIngredients; i++){
		printf("ingredients: %s\n", (palabra+(i*21)) +0);
	}
	return EXIT_SUCCESS;
	//solicitud de los platos
	//validar que sean 2,3 o 4
	//si es 1 solo plato, solicitar al cliente que pida mas platos
	//si es mayor de 4, solicitar que divida el pedido en varios pedidos
	//validar existencia de los platos en el vector que contiene cantidad de platos disponibles
	//se envia como argumento un archivo con el formato _
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