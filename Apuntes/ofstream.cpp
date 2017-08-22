#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main(int argc, char const *argv[]){

	ofstream fichero("polla.txt", ios::binary);
	
	if(fichero)
	{
		int numero= 10;
		fichero.write(reinterpret_cast<char*>(&numero), sizeof(int));
		
		char *cadena = "Hola amigo" ;
		fichero.write(cadena, strlen(cadena, strlen(cadena)*sizeof(char)));
		int numeros[7]={1,2,3,4,5,6,7};

		fichero.write(reinterpret_cast<char*>(numeros), sizeof(int)*7);
	}
	return 0;
		


}
