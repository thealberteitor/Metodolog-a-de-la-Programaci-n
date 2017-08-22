#include"Jugador.h"
#include"Matriz.h"
#include"Tablero.h"
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;


	Tablero::Tablero(int fil, int col){

		Matriz orig(fil,col);
		m = orig;
	}

	int const Tablero::getfils()
	{
		return m.getfil();
	}

	int const Tablero::getcols()
	{
		return m.getcol();
	}

	char const Tablero::get(int fil, int col)
	{
		return m.getm(fil,col);
	}

	void Tablero::setfichas(int fich){

		fichas = fich;
	}

	void Tablero::Num_Turnos(int n){

		num_turnos = n;
	}
	
	void Tablero::Cargar(Matriz m, string j1, string j2, int p1, int p2, int pfil, int pcol){
		
		cout << "Profesor lo siento, lo hemos intentado, pero no carga";		

		ifstream fe("PartidaGuardad.txt");
		fe >> j1;
		fe >> j2;
		fe >> pfil >> pcol; 
		fe >> m;
		fe >> p1 >> p2 >> num_turnos;
		
	}

	void Tablero::Salvar(Jugador j1, Jugador j2){ 
		ofstream fs("PartidaGuardada.txt");

		fs << "nombre1"	<< endl;
		fs << "nombre2" << endl;
		fs << m;
		fs << endl;
		fs << j1.Getpuntuacion() << j2.Getpuntuacion() << endl;
		fs << getfils()-1 << getcols() << fichas << num_turnos;
		
	}


	int const Tablero::Finalizado(char valor, int fila, int columna, Jugador jugador)
	{	
		int contador = 0;
		
	
		for(int i=0; i<getfils(); i++){
			if(get(i,columna) == valor){
				contador++;
			}else{
				contador = 0;
			}
			
			if(contador >= fichas){
				i++;
				while(get(i,columna) == valor){
					contador++;
					i++;
				}				

				while(contador > fichas){
					contador -= fichas;
					return contador+1;
				}

				return 1;
			}
		}
		
		contador = 0;

		for(int j=0; j<getcols(); j++){
			if(get(fila,j) == valor){
				contador++;
			}else{
				contador = 0;
			}
			
			if(contador >= fichas){
				j++;
				while(get(fila,j) == valor){
					contador++;
					j++;
				}

				while(contador > fichas){
					cout << "Entra" << endl;
					contador -= fichas;
					return contador+1;
				}

				return 1;
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
			
			if(contador >= fichas){
				
				dfil++;
				dcol++;
				while(get(dfil,dcol) == valor){
					contador++;
					dfil++;
					dcol++;
				}

				while(contador > fichas){
					contador -= fichas;
					return contador+1;
				}

				return 1;
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
			
			if(contador >= fichas){
				dfil--;
				dcol++;
				while(get(dfil,dcol) == valor){
					contador++;
					dfil--;
					dcol++;
				}
				while(contador > fichas){
					contador -= fichas;
					return contador+1;
				}

				return true;
			}

			dfil--;
			dcol++;			

		}
	
	return 0;

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

	bool Tablero::Ganador(int turno, Jugador &p1, Jugador &p2, int finalizado)
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

		if(finalizado != 0)
		{

			if(Turno(turno))
			{
				cout << "Ganador: ";
			 	p1.Getnombre();
				cout << endl;
				p1.Setpuntuacion(finalizado);
				return true;
			}else{
				cout << "Ganador: ";
				p2.Getnombre();
				cout << endl;
				p2.Setpuntuacion(finalizado);
				return true;
			}

		}else{

			return false;
		}

	}

	int Tablero::Insert(int col, int &turno, bool pasa, Jugador jugador1, Jugador jugador2)
	{

		for(int j=0; j<getcols(); j++){

			if(col == '@'){

			srand(time(NULL));
			col = 'a' + rand()%(getcols());	
			}

			if(col < 'a'|| (col - 'a') > getfils()-2){
				char guardar;
				cout << "Error: Columna No Existente, Turno Perdido" << endl;
				cout << "¿Desea Guardar la Partida?(s/n): ";
				cin >> guardar;
				if(guardar == 's' || guardar == 'S'){
					Salvar(jugador1, jugador2);
				}	
				return 0;
			}

			if(get(0,j) == col){

				for(int i=getfils(); i>0; i--){

					if(get(i,j) == ' '){

						if(Turno(turno)){

							m.set(i,j,'O');
							PrettyPrint(cout);
							if(pasa){
								turno++;
							}
							return (Finalizado(get(i,j),i,j,jugador1));

						}else{

							m.set(i,j,'X');
							PrettyPrint(cout);
							if(pasa){
								turno++;
							}
							return (Finalizado(get(i,j),i,j,jugador1));
						}
					}
				}
				cout << "Error: Columna llena, Turno Perdido" << endl;
				return 0;
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

	void Tablero::PrettyPrint(ostream& f)
	{
		system("/usr/bin/clear");

		for(int i=0; i<getfils(); i++){

			for(int j=0; j<getcols(); j++){

				f << "|" << get(i,j);

			}

			f << "|" << endl;
		}


		for(int i=0; i<getcols(); i++){

			f << "==";
		}

		f << "\n\n";

	}
