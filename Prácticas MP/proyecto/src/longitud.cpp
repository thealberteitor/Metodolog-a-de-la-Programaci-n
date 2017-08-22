#include <iostream>
#include <fstream>
#include "punto.h"
using namespace std;

int main(int argc, char* argv[]){

double distancia=0;

Punto punto1, punto2;

bool comprobador;


if (argc==1) { 
	LeerPunto(cin, punto1); 
	while (cin.eof() == false){
		comprobar = LeerPunto(cin, punto2);
		if (comprobar){
			distancia += Distancia(punto1, punto2);
		}
		punto1 = punto2;
	}

  }else {
    ifstream fich(argv[1]); 
    if (!fich) {
      cout << "Error: no se abre " << endl;
      return 1;
    }
	LeerPunto(fich, punto1); 
	while (fich.eof() == false){
		comprobar = LeerPunto(fich, punto2);
		if (comprobar){
			distancia += Distancia(punto1, punto2);
		}
		punto1 = punto2;
	}
  }

cout << '\n' << "Hay " << distancia << " cm entre los puntos.\n";

}
