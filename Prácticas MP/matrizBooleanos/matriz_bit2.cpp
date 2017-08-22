#include<iostream>
#include<string>
#include<fstream>
#include"matriz_bit.h"


bool Inicializar(MatrizBit& m, int fils, int cols)
{	
	bool inic = true;

	m.fils = fils;
	m.cols = cols;
	
	if(fils * cols > 100){
		inic = false;
	else{
		
		for(int i = 0; i < fils*cols; i++){
			m.matriz[i] = 0;
			
		}
	}
	return inic;
}

int Filas (const MatrizBit& m)
{
	return m.fils;
}

int Columnas( const MatrizBit& m)
{
	return m.cols;
}

bool Get(const MatrizBit& m, int f, int c)
{
	if(f < m.fils && c < m.cols)
		return m.matriz[f*m.columnas+c];
	else
		return 0;
}

void Set(MatrizBit& m, int f, int c, bool v)
{
	if(f < m.fils && c < m.cols)
		return m.matriz[f*m.columnas+c] = v;
}
