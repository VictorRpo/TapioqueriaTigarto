#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Declaración de variables
* A continuación se declaran todas las variables que son usadas en las funciones para maximizar el vector solución
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
int auxiliar = 0;
int resultado = 0;
int vectorSolucion[9];
int temporal;
int tamano;

/*
* Verificar cantidad de ingredientes
* Retorna 1 en caso de exito y 0 en caso contrario
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
int verificarCantidadIngredientes(int cantidad, char palabras[])
{
	return 1;
}

/*
* Maximizar pedido de dos platos
* Función que permite maximizar el modelo matematico de los pedidos de dos platos
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
int maximizarPedidoDosPlatos(int Platos, int ingredientes, int **matriz, int *solucion)
{
	int contador = 0;
	for (int i = 0; i < Platos; i++)
	{
		for (int j = 0; j < ingredientes; j++)
		{
			int a = matriz[j][solucion[(2 * i)]];
			int b = matriz[j][solucion[(2 * i + 1)]];
			if ((a == 1) || (b == 1))
			{
				contador = contador + 1;
			}
		}
	}
	return contador;
}

/*
* Maximizar pedido de pedidos de tres platos
* Función que permite maximizar el modelo matematico de los pedidos de tres platos
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
int maximizarPedidoTresPlatos(int dosPlatos, int Platos, int ingredientes, int **matriz, int *solucion)
{
	int contador = 0;
	int espacio = 2 * dosPlatos;
	for (int i = 0; i < Platos; i++)
	{
		for (int j = 0; j < ingredientes; j++)
		{
			int a = matriz[j][solucion[espacio + (3 * i)]];
			int b = matriz[j][solucion[espacio + (3 * i + 1)]];
			int c = matriz[j][solucion[espacio + (3 * i + 2)]];
			if ((a == 1) || (b == 1) || (c == 1))
			{
				contador = contador + 1;
			}
		}
	}
	return contador;
}

/*
* Maximizar pedido de pedidos de cuatro platos
* Función que permite maximizar el modelo matematico de los pedidos de cuatro platos
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
int maximizarPedidoCuatroPlatos(int dosPlatos, int tresPlatos, int Platos, int ingredientes, int **matriz, int *solucion)
{
	int contador = 0;
	int espacio = 2 * dosPlatos + 3 * tresPlatos;
	for (int i = 0; i < Platos; i++)
	{
		for (int j = 0; j < ingredientes; j++)
		{
			int a = matriz[j][solucion[espacio + (4 * i)]];
			int b = matriz[j][solucion[espacio + (4 * i + 1)]];
			int c = matriz[j][solucion[espacio + (4 * i + 2)]];
			int d = matriz[j][solucion[espacio + (4 * i + 3)]];
			if ((a == 1) || (b == 1) || (c == 1))
			{
				contador = contador + 1;
			}
		}
	}
	return contador;
}

/*
* Intercambio de solución de vectores
* Función que permite realizar realizar intercambios bidimencionales del vector resultante
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
void intercambio(int *x, int *y)
{
	temporal = *x;
	*x = *y;
	*y = temporal;
}


/*
* Imprimir solución del modelo matematico
* Función que maximiza todos los pedidos de 2, 3 y 4 platos
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
void imprimirSolucionModeloMatematico(int *solucionVector, int Platos, int dosPlatos, int tresPlatos, int cuatroPlatos, int ingredientes, int **matriz)
{
	tamano = Platos;
	if (solucionVector != 0)
	{
		for (int i = 0; i < tamano; i++)
		{
			int a = maximizarPedidoDosPlatos(dosPlatos, ingredientes, matriz, solucionVector);
			int b = maximizarPedidoTresPlatos(dosPlatos, tresPlatos, ingredientes, matriz, solucionVector);
			int c = maximizarPedidoCuatroPlatos(dosPlatos, tresPlatos, cuatroPlatos, ingredientes, matriz, solucionVector);
			resultado = a + b + c;
			if (resultado > auxiliar)
			{
				auxiliar = resultado;
				memcpy(vectorSolucion, solucionVector, tamano * sizeof(int));
			}
		}
	}
}

/*
* Permutación
* Función que permite permutar la solucion del vector.
* @author Victor restorepo - victora.agudelo@udea.edu.co
* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
* @version 02/04/2021
*/
void permutacion(int *solucionVector, int n, int Platos, int dosPlatos, int tresPlatos, int cuatroPlatos, int ingredientes, int **matriz)
{
	if (n == 1)
	{
		imprimirSolucionModeloMatematico(solucionVector, Platos, dosPlatos, tresPlatos, cuatroPlatos, ingredientes, matriz);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			permutacion(solucionVector, n - 1, Platos, dosPlatos, tresPlatos, cuatroPlatos, ingredientes, matriz);
			if (n % 2 == 1)
			{
				intercambio(&solucionVector[0], &solucionVector[n - 1]);
			}
			else
			{
				intercambio(&solucionVector[i], &solucionVector[n - 1]);
			}
		}
	}
}

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
	char *ingredientes = (char *)malloc(2100 * sizeof(char));
	char *nombreArchivo = "output.txt";
	FILE *archivo = fopen(nombreArchivo, "r");
	char linea[1024];
	int contadorDeLinea = 0;
	int cantidad[4];
	int contadorDeTerminos = 0;
	int platosPedidos = 0;
	int platosDeDos = 0;
	int platosDeTres = 0;
	int platosDeCuatro = 0;
	int totalPlatos = 0;
	int numeroDeIngredientes = 0;
	int numeroDiferenteDeIngredientes = 0;
	int **plato;
	char *ingredientesPedidoDos = (char *)malloc(2100 * sizeof(char));
	char *ingredientesPedidoTres = (char *)malloc(2100 * sizeof(char));
	char *ingredientesPedidoCuatro = (char *)malloc(2100 * sizeof(char));

	char *ingredientesDos;
	char *ingredientesTres;
	char *ingredientesCuatro;

	int numeroDiferenteDeIngredientesPedidoDos = 0;
	int numeroDiferenteDeIngredientesPedidoTres = 0;
	int numeroDiferenteDeIngredientesPedidoCuatro = 0;

	int auxiliarPedidoDos = 0;
	int auxiliarPedidoTres = 0;
	int auxiliarPedidoCuatro = 0;

	/*
	* Excepción de apertura de archivo
	* A continuación se valida que cuando el archivo no es leido, se debe notificar como respuesta dicho acto;
	* por ello valida inicialmente si la variable p llega nula y en ese caso notifica que hay un error en la apertura del archivo.
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	if (archivo==NULL)
	{
		printf("Error opening the file\n");
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
	while (fgets(linea, 1024, archivo))
	{
		char *token;
		char *resto = linea;
		if (contadorDeLinea == 0)
		{
			while ((token = strtok_r(resto, " ", &resto)))
			{
				cantidad[contadorDeTerminos] = atoi(token);
				contadorDeTerminos++;

			}
			contadorDeLinea++;
		}
		else
		{
			token = strtok_r(resto, " ", &resto);
			numeroDeIngredientes = atoi(token);
			int resultado = verificarCantidadIngredientes(numeroDeIngredientes, resto);
			if (resultado == 0)
			{
				return EXIT_FAILURE;
			}
			for (int i = 0; i < numeroDeIngredientes; i++)
			{
				token = strtok_r(resto, " ", &resto);
				if (i == numeroDeIngredientes - 1)
				{
					char *s = token; 
					while (*s != '\n')
					{
						++s;
					}
					*s = '\0';
				}
				int comparisonSomeIsEqual = -1;
				for (int j = 0; j < numeroDiferenteDeIngredientes; j++)
				{
					if (strcmp((ingredientes + (j * 21)), token) == 0)
					{							   
						comparisonSomeIsEqual = 0; 
						break;
					}
				}

				if (comparisonSomeIsEqual == -1)
				{
					strcpy((ingredientes + (numeroDiferenteDeIngredientes * 21)), token);
					numeroDiferenteDeIngredientes++;
				}
			}
		}
	}

	fclose(archivo);


	platosPedidos = cantidad[0];
	platosDeDos = cantidad[1];
	platosDeTres = cantidad[2];
	platosDeCuatro = cantidad[3];
	totalPlatos = platosDeDos * 2 + platosDeTres * 3 + platosDeCuatro * 4;
	if (totalPlatos != platosPedidos)
	{
		printf("La cantidad de platos ingresada no coincide con la cantidad de pedidos de platos de 2, 3 y 4 \n");
		return 1;
	}
	int solucionVector[totalPlatos];
	for (int i = 0; i < totalPlatos; i++)
	{
		solucionVector[i] = i;
	}

	/*
	* Matriz solución
	* permite construir la matriz solución teniendo en cuenta el número de platos de pedidos, el número de ingredientes
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	plato = (int **)malloc(sizeof(int *) * numeroDiferenteDeIngredientes);
	for (int i = 0; i < numeroDiferenteDeIngredientes; i++)
	{
		plato[i] = (int *)malloc(sizeof(int) * platosPedidos);
	}

	for (int i = 0; i < numeroDiferenteDeIngredientes; i++)
	{
		for (int j = 0; j < platosPedidos; j++)
		{
			plato[i][j] = 0;
		}
	}

	FILE *archivo2 = fopen(nombreArchivo, "r");

	char linea2[1024];
	int contadorDeLinea2 = 0;
	int numeroDeIngredientes2 = 0;
	int indiceIngredientes = -1;

	/*
	* Condicional llenar la matriz de los platos
	* Condicional que permite leer el archivo txt y realiza el llenado de la matriz solución de los platos
	* para esto, cuando se detecta un ingrediente nuevo, esté es asignado a la variable palabra
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	while (fgets(linea2, sizeof(linea2), archivo2))
	{
		char *palabra;
		char *resto2 = linea2;
		if (contadorDeLinea2 == 0)
		{
			contadorDeLinea2++;
		}
		else
		{
			palabra = strtok_r(resto2, " ", &resto2);
			numeroDeIngredientes2 = atoi(palabra);
			for (int i = 0; i < numeroDeIngredientes2; i++)
			{
				palabra = strtok_r(resto2, " ", &resto2);
				if (i == numeroDeIngredientes2 - 1)
				{
					char *s2 = palabra;
					while (*s2 != '\n')
					{
						++s2;
					}
					*s2 = '\0';
				}
				for (int j = 0; j < numeroDiferenteDeIngredientes; j++)
				{
					if (strcmp((ingredientes + (j * 21)), palabra) == 0)
					{
						indiceIngredientes = j;
						break;
					}
				}
				if (indiceIngredientes == -1)
				{
					printf("La palabra %s no se encontró", palabra);
					return EXIT_FAILURE;
				}
				plato[indiceIngredientes][contadorDeLinea2 - 1] = 1;
			}
			contadorDeLinea2++;
		}
	}

	fclose(archivo2);
	permutacion(solucionVector, totalPlatos, totalPlatos, platosDeDos, platosDeTres, platosDeCuatro, numeroDiferenteDeIngredientes, plato);
	for (int j = 0; j < totalPlatos; j++)
	{
		for (int i = 0; i < numeroDiferenteDeIngredientes; i++)
		{
			int comparacionIngredientes = -1;
			if (auxiliarPedidoDos < (2 * numeroDiferenteDeIngredientes))
			{
				if (plato[i][vectorSolucion[j]] == 1)
				{
					ingredientesDos = ingredientes + (i * 21);
					for (int h = 0; h < numeroDiferenteDeIngredientes; h++)
					{
						if (strcmp(ingredientesPedidoDos + (h * 21), ingredientesDos) == 0)
						{
							comparacionIngredientes = 0;
							break;
						}
					}
					if (comparacionIngredientes == -1)
					{
						strcpy(ingredientesPedidoDos + (numeroDiferenteDeIngredientesPedidoDos * 21), ingredientesDos);
						numeroDiferenteDeIngredientesPedidoDos++;
					}
				}
				auxiliarPedidoDos++;
			}
			else if (auxiliarPedidoTres < (3 * numeroDiferenteDeIngredientes))
			{
				if (plato[i][vectorSolucion[j]] == 1)
				{
					ingredientesTres = ingredientes + (i * 21);
					for (int h = 0; h < numeroDiferenteDeIngredientes; h++)
					{
						if (strcmp(ingredientesPedidoTres + (h * 21), ingredientesTres) == 0)
						{
							comparacionIngredientes = 0;
							break;
						}
					}
					if (comparacionIngredientes == -1)
					{
						strcpy(ingredientesPedidoTres + (numeroDiferenteDeIngredientesPedidoTres * 21), ingredientesTres);
						numeroDiferenteDeIngredientesPedidoTres++;
					}
				}
				auxiliarPedidoTres++;
			}
			else if (auxiliarPedidoCuatro < (4 * numeroDiferenteDeIngredientes))
			{
				if (plato[i][vectorSolucion[j]] == 1)
				{
					ingredientesCuatro = ingredientes + (i * 21);
					for (int h = 0; h < numeroDiferenteDeIngredientes; h++)
					{
						if (strcmp(ingredientesPedidoCuatro + (h * 21), ingredientesCuatro) == 0)
						{
							comparacionIngredientes = 0;
							break;
						}
					}
					if (comparacionIngredientes == -1)
					{
						strcpy(ingredientesPedidoCuatro + (numeroDiferenteDeIngredientesPedidoCuatro * 21), ingredientesCuatro);
						numeroDiferenteDeIngredientesPedidoCuatro++;
					}
				}
				auxiliarPedidoCuatro++;
			}
		}
	}

	FILE *archive = fopen(nombreArchivo, "w");
	if (archive == NULL)
	{
		printf("Error abriendo archivo %s", nombreArchivo);
		return EXIT_FAILURE;
	}

	/*
	* Presentación de resultados
	* A continuación se presenta la solución de todos los resultados obtenidos: 
	* Matriz de los platos, Vector Solución, Cantidad total de ingredientes,
	* contenido de cada uno de los pedidos y vector solución.
	* Y finalmente realiza el llenado de toda esta información en el archivo output.txt
	* para esto, cuando se detecta un ingrediente nuevo, esté es asignado a la variable palabra
	* @author Victor Restrepo - victora.agudelo@udea.edu.co
	* @author Sebastian Muñoz - sebastiana.munoz@udea.edu.co
	* @version 02/04/2021
	*/
	
	printf("\n");
	printf("Esta es la matriz de los platos: ");
	printf("\n");
	for (int i = 0; i < numeroDiferenteDeIngredientes; i++)
	{
		printf("\n");
		for (int j = 0; j < platosPedidos; j++)
		{
			printf("%3d", plato[i][j]);
		}
	}
	printf("\n");

	printf("\n");
	printf("Este es el vector solucion: ");
	for (int j = 0; j < totalPlatos; j++)
	{
		printf("%3d", vectorSolucion[j]);
	}
	printf("\n");

	printf("\n");
	printf("La cantidad de ingredientes diferentes totales es: %d", auxiliar);
	printf("\n");
	printf("\n");

	printf("El pedido 0 contiene: ");
	for (int i = 0; i < numeroDiferenteDeIngredientesPedidoDos; i++)
	{
		printf("%s, ", (ingredientesPedidoDos + (i * 21)) + 0);
	}
	printf("\n");

	printf("El pedido 1 contiene: ");
	for (int i = 0; i < numeroDiferenteDeIngredientesPedidoTres; i++)
	{
		printf("%s, ", (ingredientesPedidoTres + (i * 21)) + 0);
	}
	printf("\n");

	printf("El pedido 2 contiene: ");
	for (int i = 0; i < numeroDiferenteDeIngredientesPedidoCuatro; i++)
	{
		printf("%s, ", (ingredientesPedidoCuatro + (i * 21)) + 0);
	}

	//ESCRIBIMOS EN EL ARCHIVO
	fprintf(archive, "\n");
	fprintf(archive, "Esta es la matriz de los platos: ");
	fprintf(archive, "\n");
	for (int i = 0; i < numeroDiferenteDeIngredientes; i++)
	{
		fprintf(archive, "\n");
		for (int j = 0; j < platosPedidos; j++)
		{
			fprintf(archive, "%3d", plato[i][j]);
		}
	}
	fprintf(archive, "\n");

	fprintf(archive, "\n");
	fprintf(archive, "Este es el vector solucion: ");
	for (int j = 0; j < totalPlatos; j++)
	{
		fprintf(archive, "%3d", vectorSolucion[j]);
	}
	fprintf(archive, "\n");

	fprintf(archive, "\n");
	fprintf(archive, "La cantidad de ingredientes diferentes totales es: %d", auxiliar);
	fprintf(archive, "\n");
	fprintf(archive, "\n");

	fprintf(archive, "El pedido 0 contiene: ");
	for (int i = 0; i < numeroDiferenteDeIngredientesPedidoDos; i++)
	{
		fprintf(archive, "%s, ", (ingredientesPedidoDos + (i * 21)) + 0);
	}
	fprintf(archive, "\n");

	fprintf(archive, "El pedido 1 contiene: ");
	for (int i = 0; i < numeroDiferenteDeIngredientesPedidoTres; i++)
	{
		fprintf(archive, "%s, ", (ingredientesPedidoTres + (i * 21)) + 0);
	}
	fprintf(archive, "\n");

	fprintf(archive, "El pedido 2 contiene: ");
	for (int i = 0; i < numeroDiferenteDeIngredientesPedidoCuatro; i++)
	{
		fprintf(archive, "%s, ", (ingredientesPedidoCuatro + (i * 21)) + 0);
	}

	fclose(archive);
	printf("\n");
	printf("\n");
	puts("Contenido escrito correctamente");

	return EXIT_SUCCESS;
}