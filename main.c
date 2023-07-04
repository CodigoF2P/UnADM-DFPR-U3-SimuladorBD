//Directivas al procesador
#include <stdio.h>//Funciones de entrada y salida
#include <stdlib.h>//Funciones del sistema
#include <locale.h>//Funciones de formato de acuerdo a la configuraci�n regional
#include <string.h>//Funciones de cadenas

//Prototipos de las funciones
//3. Dichas opciones deber�n de ser implementadas en procedimientos fuera de la secci�n del main como funciones
// que no devuelvan valor (definidas como void en tipo de retorno) pero que si acepten par�metros si la opci�n lo requiere.
//Por ejemplo, la edici�n de un registro donde si es necesario pasar como par�metro el n�mero de cliente.
//Funci�n de consultar cliente
void consultaCliente(int idCliente);

//Funci�n de registrar cliente
void registraCliente(int idCliente);

//Funci�n de editar cliente
void editaCliente(int idCliente);

//Funci�n de eliminar cliente
void eliminaCliente(int idCliente);

int idClConsecutivo = 0;

//1. El c�digo ser� auto incremental proporcionado de forma autom�tica por el sistema de acuerdo con el orden en que haya sido registrado.
//Declaraci�n del arreglo de tipo estructura cliente
struct cliente{
	char nombre[30];
	char direccion[50];
	char telefono[20];
} clientes[];

int main(int argc, char *argv[]) 
{
    setlocale(LC_ALL, "");

	int opMenu, idClSeleccionado;

	//8. Para la realizaci�n del men� debe de hacer uso de una estructura repetitiva que solicite al usuario si desea elegir una opci�n, o bien, salir del programa.
	//Adem�s, del uso del dise�o modular como por ejemplo una estructura switch.
	do//Se ejecuta el ciclo, minimo una vez.
	{//Impresi�n del men�
	    system("cls");//Instrucci�n para borrar la pantalla

	    //Imprimir los datos del desarrollador
	    //printf("UNIVERSIDAD ABIERTA Y A DISTANCIA DE MEXICO\n");
	    //printf("ASIGNATURA: FUNDAMENTOS DE PROGRAMACION\n");
	    //printf("NOMBRE: Eduardo Dami�n Ram�rez Paniagua\n");
	    //printf("MATRICULA: ES231103942\n\n");
	    
	    //Imprimir el men�
	    //2. El programa deber� contar con un men� para poder realizar el alta, consulta, modificaci�n, eliminaci�n y salir.
	    printf("Men�\n");
		printf("1.- Consultar Clientes\n");
		printf("2.- Registrar Cliente\n");
		printf("3.- Editar Cliente\n");
		printf("4.- Eliminar Cliente\n");
		printf("5.- Salir\n");
		printf("Selecciona una opci�n\n");
		scanf("%d", &opMenu);

        switch (opMenu)
		{
			//Para la secci�n de consulta deber� de verificar que existan clientes registrados y mostrarlos en un listado.
			//En caso de que no haya clientes capturados, mostrar� el mensaje �No hay clientes registrados�.
			case 1:
				if(idClConsecutivo == 0)
				    printf("No hay clientes registrados\n");
				else
					consultaCliente(idClConsecutivo - 1);//Mandamos llamar el m�todo de Consultar Clientes

				system("pause");
				break;

			case 2:
				registraCliente(idClConsecutivo);//Mandamos llamar el m�todo de Registrar Cliente
				idClConsecutivo++;
				
				system("pause");
				break;

			case 3:
				if(idClConsecutivo == 0)
				    printf("No hay clientes registrados\n");
				else
					consultaCliente(idClConsecutivo - 1);//Mandamos llamar el m�todo de Consultar Clientes
					
                printf("Ingresa el c�digo del cliente que deseas editar\n");
                scanf("%d", &idClSeleccionado);
				editaCliente(idClSeleccionado - 1);//Mandamos llamar el m�todo de Editar Cliente
				
				system("pause");
				break;

			case 4:
                if(idClConsecutivo == 0)
				    printf("No hay clientes registrados\n");
				else
					consultaCliente(idClConsecutivo - 1);//Mandamos llamar el m�todo de Consultar Clientes
					
                printf("Ingresa el c�digo del cliente que deseas eliminar\n");
                scanf("%d", &idClSeleccionado);
				eliminaCliente(idClSeleccionado - 1);//Mandamos llamar el m�todo de Eliminar Cliente
				idClConsecutivo--;
					
				system("pause");
				break;

			case 5:
				printf("Adi�s.\n");
				break;

	 		default:
				printf("Opci�n no valida.\n");
				system("pause");
		}
	} while (opMenu != 5);//Repetimos el ciclo hasta que la opci�n del men� sea la 5, que es salir.


	system("pause");	
	return 0;
}


//M�todo de consultar cliente
void consultaCliente(int idCliente)
{
	int c;
	
    for(c=0; c<=idCliente; c++)//Se recorre la estuctura por medio del bucle for
    {
	    printf("C�digo: %d\n", (c + 1));
        printf("Nombre: %s\n", clientes[c].nombre);
	    printf("Direcci�n: %s\n", clientes[c].direccion);
	    printf("Tel�fono: %s\n", clientes[c].telefono);
	    printf("-------------\n");
	}
}

//4. Para el registro de clientes es importe que el c�digo del cliente almacene la posici�n en que dicho cliente se encuentra en la estructura,
//pero para mostrarlo al usuario hay que sumarle 1 para que el usuario en el primer registro pueda ver 1 en lugar de la posici�n 0,
//que es la real donde se almacenar� la informaci�n.
//M�todo de registrar cliente
void registraCliente(int idCliente)
{
    printf("Nombre del clinte:\n");
    fflush(stdin);
    gets(clientes[idCliente].nombre);
    printf("Direcci�n del clinte:\n");
    gets(clientes[idCliente].direccion);
    printf("Tel�fono del clinte:\n");
    gets(clientes[idCliente].telefono);

	//Mostrar los datos registrados
    printf("\nSe registro el clinte\n");
    printf("Nombre: %s\n", clientes[idCliente].nombre);
    printf("C�digo %d\n", (idCliente + 1));
    printf("Direccion: %s\n", clientes[idCliente].direccion);
    printf("Tel�fono: %s\n", clientes[idCliente].telefono);
}

//6. Para la edici�n de clientes la funci�n recibir� el n�mero de c�digo de cliente (la posici�n del arreglo donde est� almacenada)
//y solicitar� la nueva informaci�n para los campos requeridos.
//M�todo de editar cliente
void editaCliente(int idCliente)
{
    printf("Nombre del clinte:\n");
    fflush(stdin);
    gets(clientes[idCliente].nombre);
    printf("Direcci�n del clinte:\n");
    gets(clientes[idCliente].direccion);
    printf("Tel�fono del clinte:\n");
    gets(clientes[idCliente].telefono);

	//Mostrar los datos modificados
    printf("\nSe modifico el clinte\n");
    printf("Nombre: %s\n", clientes[idCliente].nombre);
    printf("C�digo %d\n", (idCliente + 1));
    printf("Direccion: %s\n", clientes[idCliente].direccion);
    printf("Tel�fono: %s\n", clientes[idCliente].telefono);
}

//7. La funci�n eliminar, deber� recorrer los registros en una posici�n a partir de la posici�n borrada.
//M�todo de eliminar cliente
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
