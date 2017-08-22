#include<iostream>
#include<string>
#include<fstream>
#include"matriz_bit.h"


bool Inicializar(MatrizBit& m, int fils, int cols)
{	
	bool inic = true;

	m.fils = fils;
	m.cols = cols;
	
	if(fils > 10 || cols > 10){
		inic = false;
	}else{
		
		for(int i = 0; i < fils; i++){
			for(int j = 0; j < cols; j++){
				m.matriz[i][j] = 0;
			}
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
		return m.matriz[f][c];
	else
		return 0;
}

void Set(MatrizBit& m, int f, int c, bool v)
{
	if(f < m.fils && c < m.cols){
		 m.matriz[f][c]=v;
	}
}
	





















	
	


