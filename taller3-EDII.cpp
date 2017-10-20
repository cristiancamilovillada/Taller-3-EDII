#include <stdio.h>
#include <string.h>
#include <stdlib.h>




	
	struct Nodo
	{
		int dato;
		struct Nodo *siguiente;
	};
	
	
	
	// FUNCI�N QUE PASA UNA CADENA CON NUMEROS A ENTERO:
	int cadenaAEntero( char cadena[20] )
	{
		/*
		Precondici�n:
		Se ha de recibir una cadena de caracteres terminada en fin de linea que contenga solo un numero entero de m�ximo 20 d�gitos.
		Poscondici�n:
		Se pasa esa cadena al tipo entero y se devuelve el dato.
		*/
		
		
		int longCadena=strlen(cadena), numero=0, i;
		
		for( i=0; i<longCadena; i++ )
		{
			numero *= 10;
			numero += cadena[i]-48;
		};
		
		return numero;
	}
	
	
	
	// FUNCI�N QUE INTRODUCE UN NUMERO EN UNA PILA:
	void insertaDato(Nodo *&pila, int num )
	{
		/*
		Precondici�n:
		Se ha de recibir un doble siguiente de tipo struct Nodo para una pila, y un par�metro de tipo entero.
		Poscondici�n:
		Se introduce el numero recibido en la pila.
		*/
		
		
		Nodo *aux = (Nodo *) malloc(sizeof(struct Nodo));
		
		
		aux->dato		= num;
		aux->siguiente	= pila;
		pila			= aux;
		
	}
	
	
	
	// FUNCI�N QUE EXTRAE EL PRIMER ELEMENTO DE LA PILA Y BORRA EL Nodo VACIO:
	int extraeDato( Nodo *&pila )
	{
		/*
		Precondici�n:
		Se ha de recibir un doble siguiente de tipo struct Nodo para una pila.
		Poscondici�n:
		Se devuelve el primer par�metro de tipo entero almacenado en la pila.
		*/
		
		
		struct Nodo *siguiente;
		int resp;
		
		// Se copia el dato a la variable que va a ser retornada por la funci�n:
		resp = (pila)->dato;
		
		
		// Se elimina el primer Nodo (el vaciado):
		siguiente = (pila)->siguiente;
		free(pila);
		pila = siguiente;
		
		
		return resp;
	}
	
	

	
	
	
	
	main(){
		Nodo *pila;
		char cad[20];
		int primervalor, segundovalor;
		printf( "Ingresa una expresi�n en notaci�n postfija y  recibiras el resultado.\n\n" );
		printf( "ingresa un dato u operador y pulse ENTER para introducir el siguiente, escriba = para calcular el resultado\n \n" );
		printf( "Ingresa la expresion:\n\n" );
				
		do{
			scanf( "%s", cad );
			switch( cad[0] ){
			case '+':
				primervalor = extraeDato( pila );
				segundovalor = extraeDato( pila );
				insertaDato( pila, primervalor + segundovalor );
				break;
			case '-':
				primervalor = extraeDato( pila );
				segundovalor = extraeDato( pila );
				insertaDato( pila, primervalor - segundovalor );
				break;
			case '*':
				primervalor = extraeDato( pila );
				segundovalor = extraeDato( pila );
				insertaDato( pila, primervalor * segundovalor );
				break;
			case '/':
				primervalor = extraeDato( pila );
				segundovalor = extraeDato( pila );
				insertaDato( pila, primervalor / segundovalor );
				break;
			case '=':
				printf( "\nEl resultado es: %i\n\n", extraeDato( pila ) / pila->dato );
				break;
			default:				
				insertaDato( pila, cadenaAEntero(cad) );
				break;
			};
			
		} while( cad[0] != '=' );
		
	}

