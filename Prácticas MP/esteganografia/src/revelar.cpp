#include <iostream>
#include <string.h>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int main(){
	const int MAX_NOMBRE= 250;
	const int MAX_TAM= 1000000;
	char nombre_imagen[MAX_NOMBRE];
	unsigned char imagen[MAX_TAM];
	unsigned char mensaje[MAX_TAM/8];
	TipoImagen i;
	int filas;
	int columnas;	
	int contador = 0;
	
	cout << "Intoduzca nombre de la imagen que quiere revelar:" << endl;
	cin.getline(nombre_imagen, 100);

	i = LeerTipoImagen (nombre_imagen, filas, columnas);

	if (i == IMG_DESCONOCIDO){
	
		cout << "Desconocido" << endl;

	}else if (i == IMG_PPM){ 			
		LeerImagenPPM (nombre_imagen, filas, columnas, imagen);	
	}

	else if (i == IMG_PGM){ 			
		LeerImagenPGM (nombre_imagen, filas, columnas, imagen);
	}

	Revelar (imagen, mensaje);	
	
	cout << endl << endl;	
	
	cout << "Revelando..." << endl;
	while(mensaje[contador] != '\0'){
		
		cout << mensaje[contador];
		contador++;
	
	}	
	cout << endl << endl;
}
