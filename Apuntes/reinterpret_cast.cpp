#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main(int argc, char const *argv[]){

	int numeros[7];
	
	ifstream fichero("datos.txt", ios::binary);
	if(fichero){
		fichero.ignore();
		fichero.read(reinterpret_cast<char*>(numeros), sizeof(int)*7);
	
		for(int i=0; i<7; i++)
			cout << "Leido: " << numeros[i] << endl;
		
	}
	else{
		cerr << "No se puede abrir" << endl;
		return 1;
	}
	return 0;

	
}
