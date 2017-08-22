#include"Matriz.h"
#include"Jugador.h"
#include"Tablero.h"
#include<iostream>

using namespace std;

int main(){

	Jugador j1,j2;
	Matriz m;
	int fila,columna,fichas;
	int salir = 0;
	int turno = 0;
	bool ganador = false;

	cout << "Introduce nombre de J1 :";
	j1.SetNombre();
	cout << "Introduce nombre de J2 : ";
	j2.SetNombre();
	cout << "Introduce el tama�o de la matriz" << endl;
	cout << "Fila: ";
	cin >> fila;
	cout << "Columnas: ";
	cin >> columna;

	cout << "Introduce el numero de fichas con las quieres jugar: ";
	cin >> fichas;

	Tablero tablero(fila +1,columna);
	tablero.setfichas(fichas);

	while(salir != -1){

		turno = 0;
		ganador = false;
		tablero.VaciarTablero();
		tablero.PrettyPrint();

		while(ganador == false){

			cout  << "Turno de " ;
			j1.Getnombre();
			cout << endl;
			ganador = tablero.Ganador(turno,j1,j2,tablero.Insert(j1.EscogeColumna(),turno));

			if(ganador == false){

				cout  << "Turno de ";
				j2.Getnombre();
				cout << endl;
				ganador = tablero.Ganador(turno,j1,j2,tablero.Insert(j2.EscogeColumna(),turno));

			}
		}

		cout << "Puntuaciones : " << endl;
		j1.Getnombre();;
		cout << ": " << j1.Getpuntacion() << endl;
		j2.Getnombre();
		cout << ": " << j2.Getpuntacion() << endl;
		cout << "Seguir Jugando? (SI(0)/NO(-1)) :";
		cin >> salir;
	}

}
