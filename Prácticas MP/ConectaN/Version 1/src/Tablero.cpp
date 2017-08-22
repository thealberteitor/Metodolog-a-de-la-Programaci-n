#include"Jugador.h"
#include"Matriz.h"
#include"Tablero.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

Tablero::Tablero(int fil, int col): m(fil, col){}

	int Tablero::getfils() const
	{
		return m.getfil();
	}

	int Tablero::getcols() const
	{
		return m.getcol();
	}

	char Tablero::get(int fil, int col) const
	{
		return m.getm(fil,col);
	}

	void Tablero::setfichas(int fich){

		fichas = fich;
	}

	bool Tablero::Finalizado(char valor, int fila, int columna) const
	{
		int contador = 0;


		for(int i=0; i<getfils(); i++){
			if(get(i,columna) == valor){
				contador++;
			}else{
				contador = 0;
			}

			if(contador == fichas){
				return true;
			}
		}

		contador = 0;

		for(int j=0; j<getcols(); j++){
			if(get(fila,j) == valor){
				contador++;
			}else{
				contador = 0;
			}

			if(contador == fichas){
				return true;
			}
		}

		int dfil = fila;
		int dcol = columna;

		while(dfil > 0 && dcol > 0){

			dfil--;
			dcol--;
 		}

		while(dfil < getfils() && dcol < getcols()){

			if(get(dfil,dcol) == valor){
					contador++;
			}else{
				contador = 0;
			}

			if(contador == fichas){
				return true;
			}

			dfil++;
			dcol++;

		}

		contador = 0;
		dfil = fila;
		dcol = columna;

		while(dfil < getfils() && dcol > 0){

			dfil++;
			dcol--;
 		}

		while(dfil > 0 && dcol < getcols()){

			if(get(dfil,dcol) == valor){
				contador++;
			}else{
				contador = 0;
			}

			if(contador == fichas){
				return true;
			}

			dfil--;
			dcol++;

		}

	return false;

	}


	bool Tablero::Turno(int turno)
	{
		if(turno%2 == 0)
		{
			return false;
		}else{
			return true;
		}


	}


bool Tablero::Ganador(int turno, Jugador &p1, Jugador &p2, bool finalizado)
{

	bool empate = true;

	for(int f=0; f<getfils(); f++){

		for(int c=0; c<getcols(); c++){

			if(get(f,c) == ' '){

				empate = false;
			}

		}
	}

		if(empate == true){

			cout << "Empate" << endl;
			return true;
		}

		if(finalizado == true)
		{

			if(Turno(turno))
			{
				cout << "Ganador: ";
				p1.Getnombre();
				cout << endl;

				p1.Setpuntuacion(1);
				return true;
			}else{

				cout << "Ganador: ";
				p2.Getnombre();
				cout << endl;

				p2.Setpuntuacion(1);
				return true;
			}

		}else{

			return false;
		}

	}

	bool Tablero::Insert(int col, int &turno)
	{

		for(int j=0; j<getcols(); j++){

			if(col < 'a'|| (col - 'a') > getfils()-2){

				cout << "Error: Columna No Existente, Turno Perdido" << endl;
				return false;
			}

			if(get(0,j) == col){

				for(int i=getfils(); i>0; i--){

					if(get(i,j) == ' '){

						if(Turno(turno)){

							m.set(i,j,'O');
							PrettyPrint();
								turno++;

							return (Finalizado(get(i,j),i,j));

						}else{

							m.set(i,j,'X');
							PrettyPrint();
								turno++;

							return (Finalizado(get(i,j),i,j));
						}
					}
				}
				cout << "Error: Columna llena, Turno Perdido" << endl;
				return false;
			}
		}
	}


	void Tablero::VaciarTablero()
	{
		int n = 0;

			for(int i=0; i<getfils(); i++){

				for(int j=0; j<getcols(); j++){

					if(i == 0){

						char letra;
						letra = 'a' + n;
						n++;
						m.set(i,j,letra);

					}else{

						m.set(i,j,' ');


					}

				}
			}
	}

void Tablero::PrettyPrint()
{
	system("/usr/bin/clear");

	for(int i=0; i<getfils(); i++){

		for(int j=0; j<getcols(); j++){

			cout << "|" << get(i,j);

		}

		cout << "|" << endl;
	}


	for(int i=0; i<getcols(); i++){

		cout << "==";
	}

	cout << "\n\n";

}
