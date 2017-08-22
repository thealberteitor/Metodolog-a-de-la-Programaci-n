#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include<iostream>
using namespace std;

class Jugador{

	private:

	char *nombre;
	int tamano;
	int puntuacion;

	public:

	Jugador();

	Jugador(const Jugador &orig);

	char EscogeColumna();

	int Getpuntuacion();
	
	void Getnombre();

	void Setpuntuacion(int punto);

	void SetNombre();

	void SetNombre(char nombre2[]);

};

#endif
