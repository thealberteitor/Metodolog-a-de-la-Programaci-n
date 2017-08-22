#ifndef __TABLERO_H__
#define __TABLERO_H__

#include<iostream>
using namespace std;

class Tablero{

	private:

		Matriz m;
		int fichas;

	public:

	Tablero(int fil, int col);

	int getfils() const;

	int getcols() const;

	char  get(int fil, int col) const;

	void setfichas(int fich);

	bool Finalizado(char valor, int fila, int columna) const;

	bool Ganador(int turno, Jugador &p1, Jugador &p2, bool finalizado);

	bool Insert(int col, int &turno);

	bool Turno(int turno);

	void VaciarTablero();

	void PrettyPrint();

};

#endif
