#include<iostream>
#include<fstream>
#include<string.h>
#include"matriz_bit.h"
#include"matriz_operaciones.h"
using namespace std;

int main(int argc, char* argv[]){

MatrizBit res, matriz1, matriz2;

if(argc == 4){

	if(strcmp(argv[1],"AND") == 0){
	
		ifstream f(argv[2]);
		ifstream g(argv[3]);
		Leer(f, matriz1);
		Leer(g, matriz2);
		And(res,matriz1,matriz2);
	}

	if(strcmp(argv[1],"OR") == 0){

		ifstream f(argv[2]);
		ifstream g(argv[3]);
		Leer(f, matriz1);
		Leer(g, matriz2);
		Or(res,matriz1,matriz2);
	}

	Escribir(cout, res);

}

if(argc == 3){

	if(strcmp(argv[1],"NOT") == 0){
	
		ifstream f(argv[2]);
		Leer(f, matriz1);
		Not(res,matriz1);
	}
	if(strcmp(argv[1],"TRS") == 0){
	
		ifstream f(argv[2]);
		Leer(f, matriz1);
		Traspuesta(res,matriz1);
	}

	Escribir(cout, res);

}/*else{

	cout << "Escritura incorrenta" << endl;
}*/

}

	
