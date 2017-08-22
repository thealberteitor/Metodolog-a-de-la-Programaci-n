#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include<iostream>
using namespace std;

class Jugador{

	private:

		char nombre[50];
		int puntuacion;

	public:

	Jugador();

	char EscogeColumna();

	int Getpuntacion();

	void Getnombre();

	void Setpuntuacion(int punto);

	void SetNombre();

};

#endif
