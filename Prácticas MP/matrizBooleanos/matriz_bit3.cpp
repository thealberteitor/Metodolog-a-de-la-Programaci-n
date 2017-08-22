#include<iostream>
#include<string>
#include<fstream>
#include"matriz_bit.h"

bool Inicializar(MatrizBit& m, int fils, int cols)
{	
	bool inic = true;
	unsigned int dimension, aux;

	dimension = 0;
	aux = 0;	

	m.fils = fils;
	m.cols = cols;
	
	if(fils * cols > 100){
		inic = false;
	else{
		
		for(int i = 0; i < fils; i++){
			for(int j = 0; j < cols; j++){
				m.matriz[i*cols + j] = 0
			}
		}
	}
	
	dimension = (dimension | cols);
	aux = (fils << 16); 
	dimension += aux;
	m.dimension = dimension;

	return inic;
}


int Filas (const MatrizBit& m)
{
	int fils = (m.dimension >> 16);
	return fils;
}

int Columnas( const MatrizBit& m)
{
	int cols = ((m.dimension << 16) >> 16)
	return cols;
}

bool Get(const MatrizBit& m, int f, int c)
{
	char caracter;
	bool pos;
	
	if ( (f<Filas(m) && (c<Columnas(m)) ){
		caracter = m.matriz[f*Columnas(m)+c]
	}
	if(caracter == 1){
		pos = true;
	}else{
		pos = false;
	}
	
	return pos;
}

void Set(MatrizBit& m, int f, int c, bool v)
{
	if ( (f<Filas(m) && (c<Columnas(m)) ){
		 m.matriz[f*Columnas(m) + c] = v;
}
