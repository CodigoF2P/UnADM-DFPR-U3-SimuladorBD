//Directivas al procesador
#include <stdio.h>//Funciones de entrada y salida
#include <stdlib.h>//Funciones del sistema
#include <locale.h>//Funciones de formato de acuerdo a la configuración regional
#include <string.h>//Funciones de cadenas

//Prototipos de las funciones
//3. Dichas opciones deberán de ser implementadas en procedimientos fuera de la sección del main como funciones
// que no devuelvan valor (definidas como void en tipo de retorno) pero que si acepten parámetros si la opción lo requiere.
//Por ejemplo, la edición de un registro donde si es necesario pasar como parámetro el número de cliente.
//Función de consultar cliente
void consultaCliente(int idCliente);

//Función de registrar cliente
void registraCliente(int idCliente);

//Función de editar cliente
void editaCliente(int idCliente);

//Función de eliminar cliente
void eliminaCliente(int idCliente);

int idClConsecutivo = 0;

//1. El código será auto incremental proporcionado de forma automática por el sistema de acuerdo con el orden en que haya sido registrado.
//Declaración del arreglo de tipo estructura cliente
struct cliente{
	char nombre[30];
	char direccion[50];
	char telefono[20];
} clientes[];

int main(int argc, char *argv[]) 
{
    setlocale(LC_ALL, "");

	int opMenu, idClSeleccionado;

	//8. Para la realización del menú debe de hacer uso de una estructura repetitiva que solicite al usuario si desea elegir una opción, o bien, salir del programa.
	//Además, del uso del diseño modular como por ejemplo una estructura switch.
	do//Se ejecuta el ciclo, minimo una vez.
	{//Impresión del menú
	    system("cls");//Instrucción para borrar la pantalla

	    //Imprimir los datos del desarrollador
	    //printf("UNIVERSIDAD ABIERTA Y A DISTANCIA DE MEXICO\n");
	    //printf("ASIGNATURA: FUNDAMENTOS DE PROGRAMACION\n");
	    //printf("NOMBRE: Eduardo Damián Ramírez Paniagua\n");
	    //printf("MATRICULA: ES231103942\n\n");
	    
	    //Imprimir el menú
	    //2. El programa deberá contar con un menú para poder realizar el alta, consulta, modificación, eliminación y salir.
	    printf("Menú\n");
		printf("1.- Consultar Clientes\n");
		printf("2.- Registrar Cliente\n");
		printf("3.- Editar Cliente\n");
		printf("4.- Eliminar Cliente\n");
		printf("5.- Salir\n");
		printf("Selecciona una opción\n");
		scanf("%d", &opMenu);

        switch (opMenu)
		{
			//Para la sección de consulta deberá de verificar que existan clientes registrados y mostrarlos en un listado.
			//En caso de que no haya clientes capturados, mostrará el mensaje “No hay clientes registrados”.
			case 1:
				if(idClConsecutivo == 0)
				    printf("No hay clientes registrados\n");
				else
					consultaCliente(idClConsecutivo - 1);//Mandamos llamar el método de Consultar Clientes

				system("pause");
				break;

			case 2:
				registraCliente(idClConsecutivo);//Mandamos llamar el método de Registrar Cliente
				idClConsecutivo++;
				
				system("pause");
				break;

			case 3:
				if(idClConsecutivo == 0)
				    printf("No hay clientes registrados\n");
				else
					consultaCliente(idClConsecutivo - 1);//Mandamos llamar el método de Consultar Clientes
					
                printf("Ingresa el código del cliente que deseas editar\n");
                scanf("%d", &idClSeleccionado);
				editaCliente(idClSeleccionado - 1);//Mandamos llamar el método de Editar Cliente
				
				system("pause");
				break;

			case 4:
                if(idClConsecutivo == 0)
				    printf("No hay clientes registrados\n");
				else
					consultaCliente(idClConsecutivo - 1);//Mandamos llamar el método de Consultar Clientes
					
                printf("Ingresa el código del cliente que deseas eliminar\n");
                scanf("%d", &idClSeleccionado);
				eliminaCliente(idClSeleccionado - 1);//Mandamos llamar el método de Eliminar Cliente
				idClConsecutivo--;
					
				system("pause");
				break;

			case 5:
				printf("Adiós.\n");
				break;

	 		default:
				printf("Opción no valida.\n");
				system("pause");
		}
	} while (opMenu != 5);//Repetimos el ciclo hasta que la opción del menú sea la 5, que es salir.


	system("pause");	
	return 0;
}


//Método de consultar cliente
void consultaCliente(int idCliente)
{
	int c;
	
    for(c=0; c<=idCliente; c++)//Se recorre la estuctura por medio del bucle for
    {
	    printf("Código: %d\n", (c + 1));
        printf("Nombre: %s\n", clientes[c].nombre);
	    printf("Dirección: %s\n", clientes[c].direccion);
	    printf("Teléfono: %s\n", clientes[c].telefono);
	    printf("-------------\n");
	}
}

//4. Para el registro de clientes es importe que el código del cliente almacene la posición en que dicho cliente se encuentra en la estructura,
//pero para mostrarlo al usuario hay que sumarle 1 para que el usuario en el primer registro pueda ver 1 en lugar de la posición 0,
//que es la real donde se almacenará la información.
//Método de registrar cliente
void registraCliente(int idCliente)
{
    printf("Nombre del clinte:\n");
    fflush(stdin);
    gets(clientes[idCliente].nombre);
    printf("Dirección del clinte:\n");
    gets(clientes[idCliente].direccion);
    printf("Teléfono del clinte:\n");
    gets(clientes[idCliente].telefono);

	//Mostrar los datos registrados
    printf("\nSe registro el clinte\n");
    printf("Nombre: %s\n", clientes[idCliente].nombre);
    printf("Código %d\n", (idCliente + 1));
    printf("Direccion: %s\n", clientes[idCliente].direccion);
    printf("Teléfono: %s\n", clientes[idCliente].telefono);
}

//6. Para la edición de clientes la función recibirá el número de código de cliente (la posición del arreglo donde está almacenada)
//y solicitará la nueva información para los campos requeridos.
//Método de editar cliente
void editaCliente(int idCliente)
{
    printf("Nombre del clinte:\n");
    fflush(stdin);
    gets(clientes[idCliente].nombre);
    printf("Dirección del clinte:\n");
    gets(clientes[idCliente].direccion);
    printf("Teléfono del clinte:\n");
    gets(clientes[idCliente].telefono);

	//Mostrar los datos modificados
    printf("\nSe modifico el clinte\n");
    printf("Nombre: %s\n", clientes[idCliente].nombre);
    printf("Código %d\n", (idCliente + 1));
    printf("Direccion: %s\n", clientes[idCliente].direccion);
    printf("Teléfono: %s\n", clientes[idCliente].telefono);
}

//7. La función eliminar, deberá recorrer los registros en una posición a partir de la posición borrada.
//Método de eliminar cliente
void eliminaCliente(int idCliente)
{
    int c = 0;
	
	//Se recorre la estuctura por medio del bucle for
	//Del id a borrar al penultimo registro
    for(c=idCliente; c<idClConsecutivo; c++)
    {
        strcpy(clientes[c].nombre, clientes[c + 1].nombre);
        strcpy(clientes[c].direccion, clientes[c + 1].direccion);
        strcpy(clientes[c].telefono, clientes[c + 1].telefono);
	}
}
