#include"Matriz.h"
#include<iostream>
#include<fstream>

using namespace std;

Matriz::Matriz(): datos(NULL), fils(0), cols(0){}

Matriz::Matriz(int fils, int cols): fils(fils), cols(cols){

	datos = new char[fils*cols];
}

Matriz::~Matriz()
{
	delete[]datos;
}



Matriz::Matriz(const Matriz &orig){

	cols = orig.cols;
	fils = orig.fils;
	if(orig.datos != 0)
	{
		datos = new char[fils*cols];
		for(int i=0; i<fils*cols; i++)
			datos[i]=orig.datos[i];
	}else
		datos=NULL;
	}

char Matriz::getfil() const
{
	return fils;
}

char Matriz::getcol() const
{
	return cols;
}

char Matriz::getm(int fil, int col) const
{
	return datos[fil*cols+col];
}

void Matriz::setfil(int n){

	fils = n;

}

void Matriz::setcol(int n){

	cols = n;

}

void Matriz::set(int fil, int col, char valor)
{
	datos[fil*cols+col] = valor;
}

Matriz & Matriz::operator=(const Matriz& orig)
{
	if(this != &orig)
	{
		delete[]datos;
		fils=orig.fils;
		cols=orig.cols;

		if(orig.datos != 0)
		{
			datos = new char[fils*cols];
			for(int i=0; i<fils*cols; i++)
				datos[i] = orig.datos[i];
		}else
			datos = NULL;
	}
	return *this;
}


ostream& operator <<(ostream& os,const Matriz& orig)
{
	 os << orig.fils << " " << orig.cols;

  for(int i=0; i< orig.fils*orig.cols; i++)
  {
  	os <<orig.datos[i]<< " ";
  }

  return os;
}


istream& operator >>(istream& is, Matriz& orig)
{
	delete[]orig.datos;

	is >> orig.fils >> orig.cols;

	int filas = orig.fils;
	int columnas = orig.cols;

	if(filas*columnas>0)
	{
			orig.datos=new char[filas*columnas];
			for(int i=0; i<filas*columnas; i++)
						is >> orig.datos[i];

	}else
			orig.datos = 0;

	return is;
}
