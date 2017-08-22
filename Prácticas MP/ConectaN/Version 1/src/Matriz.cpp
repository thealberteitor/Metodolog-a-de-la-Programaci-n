#include"Matriz.h"
#include<iostream>
using namespace std;

Matriz::Matriz(): fils(0), cols(0){}

Matriz::Matriz(int fils, int cols): fils(fils), cols(cols){}

char Matriz::getfil() const
{
	return fils;
}

char  Matriz::getcol() const
{
	return cols;
}

char Matriz::getm(int fil, int col) const
{
	return matriz[fil][col];
}

void Matriz::set(int fil, int col, char valor)
{
	matriz[fil][col] = valor;
}
