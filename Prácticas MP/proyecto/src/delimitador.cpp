#include <iostream>
#include <cmath>
#include <fstream>

#include "rectangulo.h"
#include "punto.h"
using namespace std;

int main(int argc, char* argv[]){
	Rectangulo rectangulo;
	Punto punto, otro_punto;
	cout << "Introducir puntos:";

  if (argc==1) {

	LeerPunto(cin, punto);
	otro_punto= punto;
	InicializarRectangulo(rectangulo, punto, otro_punto);

	while (! cin.eof()){
		LeerPunto(cin, punto);
		AmpliarRectangulo(rectangulo, punto);	
	}

  }else {

    ifstream fich(argv[1]); 

    if (!fich) {
      cout << "Error: no se abre " << endl;
      return 1;

    }
	LeerPunto(fich, punto);
	otro_punto= punto;
	InicializarRectangulo(rectangulo, punto, otro_punto);

	while (! fich.eof()){

		LeerPunto(fich, punto);
		AmpliarRectangulo(rectangulo, punto);	

	}

  }

cout << "El rectangulo delimitador es :";
EscribirRectangulo(cout, rectangulo);

}
