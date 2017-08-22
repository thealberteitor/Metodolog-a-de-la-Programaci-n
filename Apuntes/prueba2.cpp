#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
//argc = argument count, cuantos argumentos se le han pasado al programa
//*argv[] vector de punteros a char

int main(int argc, char const *argv[]){
	string nombre;
	if(argc!=3){
		cerr << "EL numero de argumentos es incorrecto " << endl;
		exit(-1);
	}
	
	

	//cout << "He recibido " << argc << " argumentos" << endl;
	

	/*for(int i=0; i< argc; i++){
	cout << "EL argumento(" << i << ") = " << argv[i] << endl;
	*/
	

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



//./prueba && echo correcto    Si el primero se realiza correctamente el segundo se hace


/* Qué poner en la terminal:

	generar ejecutable
	ejecutarlo
	cat ascii0.txt
*/

