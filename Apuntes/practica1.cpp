#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char const *argv[]){
	string nombre;

// nombre.c_str() -> devuelve const char* interno




//genero 10 ficheros de forma que el primero se llame ascii0.txt.. 1...2..n

	for(int i=0; i<10; i++){
		string nombre;
	}
	
	for(int i=0; i<10; i++){
		nombre = "ascii" + to_string(i) + ".txt";
		cout << nombre << endl;

		ofstream fichero(nombre);
		//ofstream fichero
		// fichero.open(nombre);
		
			
		if(fichero){ //fichero.is_open()
		fichero << "El contenido es:" << nombre << ":)" ;
		fichero.close();
		}

	}


}

//g++ --std=c++11 practicas.cpp -o practicas

/////////////////////////////////////////////////////////////////////////////


/*
stream = flujo
f = file
i=input
o=output
*/





/* Qué poner en la terminal:

	generar ejecutable
	ejecutarlo
	cat ascii0.txt
*/

