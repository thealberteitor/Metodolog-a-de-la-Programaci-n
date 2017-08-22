#include<iostream>

using namespace std;

struct Vector{
	
	int *datos;
	int n;
	
};



void Ampliar(Vector &v,  int valor){
	
	int *aux = new int[v.n+1];
	
	for(int i=0; i<v.n+1; i++){
			aux[i]=v.datos[i];
	}
	
	delete[]v.datos;
	v.datos=aux;
	v.datos[v.n]=valor;
	v.n++;
	
}

int main(){
	
	Vector v;
	
	v.n = 5;
	v.datos = new int[v.n];
	
	for(int i=0; i<v.n; i++){
		cout << "Introduce término: " << i;
		cin >> v.datos[i];
	}
	
	Ampliar(v, 5);
	
	for(int i=0; i<v.n; i++){
		
		cout << v.datos[i];	
	}
}
	
	
	
	
