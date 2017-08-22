#include"Matriz.h"
#include"Jugador.h"
#include"Tablero.h"
#include<string.h>
#include<iostream>

using namespace std;

int main(int argc, char *argv[]){

if(argc > 2){
	cerr << "Numero de parametros incorrecto";
}

	Jugador j1,j2;
	Matriz m;
	int fila,columna,fichas,num_turnos;
	int salir = 0;
	int turno = 0;
	bool ganador = false;
	bool pasa;
	bool primero = false;

if(argc == 2){

	string jug1, jug2;
	int n1, n2, p1, p2, pfil, pcol;
	primero = true;
	Tablero tablero(fila+1,columna);
	tablero.Cargar(m, jug1, jug2, p1, p2, pfil, pcol);
	j1.Setpuntuacion(p1);
	j2.Setpuntuacion(p2);
	n1 = strlen(jug1.c_str());
	n2 = strlen(jug2.c_str());
	char jugador1[n1];
	char jugador2[n2];
	j1.SetNombre(jugador1);
	j2.SetNombre(jugador2);
	tablero.setfichas(fichas);
	tablero.Num_Turnos(num_turnos);
	m.setcol(pcol);
	m.setfil(pfil);

	while(salir != -1){

		turno = 0;
		ganador = false;
		tablero.VaciarTablero();
		tablero.PrettyPrint(cout);

		while(ganador == false){
			int contador;
			contador = 0;
			while( contador != num_turnos){

				if(contador == num_turnos-1){
					pasa = true;
				}else{
					pasa = false;
				}
				cout  << "Turno de ";
				j1.Getnombre();
				cout << endl;
				ganador = tablero.Ganador(turno,j1,j2,tablero.Insert(j1.EscogeColumna(),turno, pasa, j1,j2));
				contador++;

			}
			if(ganador == false){
				contador = 0;
				while( contador != num_turnos){

					if(contador == num_turnos-1){
					pasa = true;
					}else{
					pasa = false;
					}
					cout  << "Turno de ";
					j2.Getnombre();;
					cout << endl;
					ganador = tablero.Ganador(turno,j1,j2,tablero.Insert(j2.EscogeColumna(),turno, pasa, j2, j1));
					contador++;
				}
			}
		}

		cout << "Puntuaciones : " << endl;
		j1.Getnombre();;
		cout << ": " << j1.Getpuntuacion() << endl;
		j2.Getnombre();
		cout << ": " << j2.Getpuntuacion() << endl;
		cout << "Seguir Jugando? (SI(0)/NO(-1)) :";
		cin >> salir;

	}

}

if(argc == 1){

	if(primero == false){
	cout << "Introduce nombre de J1 :";
	j1.SetNombre();
	cout << "Introduce nombre de J2 : ";
	j2.SetNombre();

	cout << "Introduce el tamano de la matriz" << endl;
	cout << "Fila: ";
	cin >> fila;
	cout << "Columnas: ";
	cin >> columna;

	cout << "Introduce el numero de fichas con las quieres jugar: ";
	cin >> fichas;

	cout << "Introduce el numero de turnos con los que jugar: ";
	cin >> num_turnos;

	Tablero tablero(fila+1,columna);

	tablero.setfichas(fichas);

	tablero.Num_Turnos(num_turnos);
	

	while(salir != -1){

		turno = 0;
		ganador = false;
		tablero.VaciarTablero();
		tablero.PrettyPrint(cout);

		while(ganador == false){
			int contador;
			contador = 0;
			while( contador != num_turnos){

				if(contador == num_turnos-1){
					pasa = true;
				}else{
					pasa = false;
				}
				cout  << "Turno de ";
				j1.Getnombre();
				cout << endl;
				ganador = tablero.Ganador(turno,j1,j2,tablero.Insert(j1.EscogeColumna(),turno, pasa, j1,j2));
				contador++;

			}
			if(ganador == false){
				contador = 0;
				while( contador != num_turnos){

					if(contador == num_turnos-1){
					pasa = true;
					}else{
					pasa = false;
					}
					cout  << "Turno de ";
					j2.Getnombre();;
					cout << endl;
					ganador = tablero.Ganador(turno,j1,j2,tablero.Insert(j2.EscogeColumna(),turno, pasa, j2,j1));
					contador++;
				}
			}
		}

		cout << "Puntuaciones : " << endl;
		j1.Getnombre();;
		cout << ": " << j1.Getpuntuacion() << endl;
		j2.Getnombre();
		cout << ": " << j2.Getpuntuacion() << endl;
		cout << "Seguir Jugando? (SI(0)/NO(-1)) :";
		cin >> salir;

	}
}


}

}

