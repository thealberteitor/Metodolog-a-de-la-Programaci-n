#include <iostream>
#include <string.h>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int main(){
	
	const int MAX_NOMBRE= 250;
	const int MAX_TAM= 1000000;
	
	char nombre_imagen[MAX_NOMBRE], nombre_imagen_2[MAX_NOMBRE]="Codificada";
	TipoImagen i;
	unsigned char imagen[MAX_TAM];
	int filas, columnas;
	char mensaje_codificado[MAX_TAM/8];

	cout << "Introduzca nombre de la imagen: " << endl ;
	cin.getline (nombre_imagen, 100);

	cout << "Introduzca el mensaje: " << endl;
	cin.getline (mensaje_codificado, 1000);
	

	i= LeerTipoImagen (nombre_imagen, filas, columnas);

	if (i==IMG_DESCONOCIDO){ 	
		cout << "Desconocido " << endl << endl;
	}
	
	else if (i==IMG_PPM){ 		
		LeerImagenPPM (nombre_imagen, filas, columnas, imagen);
		InsertarCadena (mensaje_codificado, imagen);
		cout << "Compilando: " << endl << endl;
		EscribirImagenPPM (nombre_imagen_2, imagen, filas, columnas);	
	}

	else if (i==IMG_PGM){ 		
		LeerImagenPGM (nombre_imagen, filas, columnas, imagen);
		InsertarCadena (mensaje_codificado, imagen);
		cout << "Compilando: " << endl;
		EscribirImagenPGM (nombre_imagen_2, imagen, filas, columnas);	
	}



cout << endl << endl;	
}
