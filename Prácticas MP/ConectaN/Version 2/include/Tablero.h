#ifndef __TABLERO_H__
#define __TABLERO_H__

#include<iostream>
using namespace std;

class Tablero{

	private:

		Matriz m;
		int fichas, num_turnos;

	public:

	Tablero(int fil, int col);

	int const getfils();

	int const getcols();

	char const get(int fil, int col);

	void setfichas(int fich);
	
	void Salvar(Jugador j1, Jugador j2);
		
	void Cargar(Matriz m, string j1, string j2, int p1, int p2, int pfil, int pcol);

	void Num_Turnos(int n);

	int const Finalizado(char valor, int fila, int columna, Jugador jugador);

	bool Ganador(int turno, Jugador &p1, Jugador &p2, int finalizado);

	int Insert(int col, int &turno, bool pasa, Jugador jugador1, Jugador jugador2);

	bool Turno(int turno);

	void VaciarTablero();

	void PrettyPrint(ostream& f);

};

#endif
