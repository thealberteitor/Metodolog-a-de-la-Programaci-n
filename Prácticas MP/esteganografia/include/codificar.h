#ifndef CODIFICAR_H
#define CODIFICAR_H

char BitN(char caracter, int posicion);

void InsertaeCaracter (char caracter, unsigned char imagen[], int posicion);

bool InsertarCadena (char cadena[], unsigned char imagen[]);

char MostrarCaracter(unsigned char imagen[], int posicion);

bool Revelar(unsigned char imagen[], unsigned char frase[]);

#endif
