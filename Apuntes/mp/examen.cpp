#include<iostream>

using namespace std;

struct Vector{
	
	int *datos;
	int n;
	
};

void Lectura(Vector &v){
	
	for(int i=0; i<v.n; i++){
		cout << "Introduce datos: " << i;
		cin >> v.datos[i];
	}
	
}

void Cuenta(Vector &v, int &pares, int &impares){
	
	for(int i=0; i<v.n; i++){
		if(v.datos[i]%2==0){
			pares++;
		}else{
			impares++;	
		}
	}
}

Vector Par(Vector &v, int &pares){
	
	int *par=new int[pares];
	int contador=0;
	
	for(int i=0; i<v.n; i++){
		if(v.datos[i]%2==0){
			par[contador] = v.datos[i];
			contador++;
		}
	}
}
	
	
	
	
	
int Impar(Vector &v, int &impares){
	
	int *par=new int[impares];
	int contador=0;
	
	for(int i=0; i<v.n; i++){
		if(v.datos[i]%2==1){
			par[contador] = v.datos[i];
			contador++;
		}
	}
	
}

int main(){
	
	Vector v;
	v.datos=new int[v.n];
	int pares=0;
	int impares=0;
	
	
	cout << "Introduce tamaño del vector original: ";
	cin >> v.n;
	
	Lectura(v);
	
	Cuenta(v, pares, impares);
	
	Par(v, pares);
	
	Impar(v, impares);
	
	

	
	
	for(int i=0; i<v.n; i++){
		cout << pares[i] << "  " ;
		cout << impares[i] << "  ";
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
