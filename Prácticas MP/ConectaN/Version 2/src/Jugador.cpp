#include"Jugador.h"
#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


	Jugador::Jugador()
	{
		tamano = 0;
		nombre = NULL;
		puntuacion = 0;
	}

	Jugador::Jugador(const Jugador &orig)
	{
		nombre = orig.nombre;

		if(orig.nombre != 0)
		{
			int aux = strlen(nombre);
			nombre = new char[aux];
			for(int i=0; i<aux; i++)
				nombre[i] = orig.nombre[i];
		}else
			nombre = NULL;
	}

	char Jugador::EscogeColumna()
	{
		char col;
		cout << "Introduce letra de columna: ";
		cin >> col;

		return col;
	}

	int Jugador::Getpuntuacion(){

		return puntuacion;

	}

	void Jugador::Setpuntuacion(int punto){

		puntuacion += punto;
	}

	

	void Jugador::Getnombre(){

		for(int i=0; i<tamano; i++){
			cout << nombre[i];
		}
		
	}

	void Jugador::SetNombre(char nombre2[]){
		
		tamano = strlen(nombre2);
		
		char* aux = new char [tamano];
		for(int i=0; i<tamano; i++){
			 aux[i] = nombre2[i];
		}
		delete[]nombre;
		nombre = aux;

	}
	
		
	void Jugador::SetNombre(){

		tamano = 1000;
		nombre = new char[tamano];
		
		cin.getline(nombre,tamano,'\n');
		
		tamano = strlen(nombre);
		 
		char* aux = new char [tamano];
		for(int i=0; i<tamano; i++){
			 aux[i] = nombre[i];
		}
		delete[]nombre;
		nombre = aux;
	
	}
