#include"Jugador.h"
#include<iostream>
using namespace std;


Jugador::Jugador()
{
	puntuacion = 0;
}

char Jugador::EscogeColumna()
{
	char col;
	cout << "Introduce letra de columna: ";
	cin >> col;
	return col;
}

int Jugador::Getpuntacion(){

	return puntuacion;
}

void Jugador::Getnombre(){

	for(int i=0; i< 50 ; i++){
		cout << nombre[i];
	}
}

void Jugador::Setpuntuacion(int punto){

	puntuacion += punto;
}

void Jugador::SetNombre(){

	for(int i=0; i<50; i++)
		nombre[i]=0;

	cin.getline(nombre,50,'\n');

}
