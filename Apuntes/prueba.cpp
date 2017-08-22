#include<iostream>
#include<fstream>

using namespace std;


void es_par(int numero){

	if(numero % 2 == 0)
		cout << "SIUUUU" << endl;	
	else
		cout << "NOUUUU" << endl;

}


int main(int argc , char const *argv[]){

	if(argc == 1)
	{
		int numero;
		do{
			cout << "Introduzca números: " << endl;
			cin >> numero;
		}while(numero != -1);



	}

	else if(argc == 2){
		
		int numero;

		ifstream f(argv[1]);
		f >> numero;
		es_par(numero);
	}

	else
		cerr << "Número de parámetros incorrecto ";	



}
