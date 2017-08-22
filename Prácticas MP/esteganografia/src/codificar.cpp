#include <iostream>
#include <string.h>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

char BitN(char caracter, int pos){  
   int numero = 7-pos;
   return ( (caracter >> numero) & 1);	
}

void InsertarCaracter (char caracter, unsigned char imagen[], int pos){
	for (int i=0; i<8; i++)
		imagen[pos+i] = ((imagen[pos+i] >> 1) << 1) + BitN(caracter, i);

}

bool InsertarCadena (char cadena[],unsigned char imagen[]){
	bool error = true;
	int i=0;
	if (strlen(cadena) < 125000){
		error=false;
		while (cadena[i] != '\0'){
			InsertarCaracter (cadena[i], imagen, (i*8));
			i++;
		}
		InsertarCaracter (cadena[i], imagen, (i*8));
	}
	return error;
}

char MostrarCaracter(unsigned char imagen[], int pos){
	unsigned char caracter='\0', aux='\0';

	for (int i=7; i>-1; i--){
		aux = (imagen[pos+7-i] & 1) << i;
		caracter += aux;	
	}	
	return caracter;
}


bool Revelar(unsigned char imagen[],unsigned char frase[]){
	bool quedan_letras= true, hay_espacio= true;	
	
	int i=0;
	while (quedan_letras && hay_espacio){
		frase[i] = MostrarCaracter(imagen, i*8);
		if (frase[i] == '\0')
			quedan_letras = false;
		i++;

		if(i == 1000000/8)
			hay_espacio= false;

	}
	if (! hay_espacio)
		quedan_letras= true;

	return quedan_letras; // Devuelve error si no encuentra el carácter '\0'.
}


