#include<iostream>

using namespace std;

void InsertarPosicion(int *&vector, int &n, int posicion, int valor)
{
	int *aux;
	aux = new int[n+1];
	
	for(int i=0 ; i<posicion; i++)
	{
		if(i==posicion)
		{
			aux[i] = valor;
		}
		else
			aux[i] = vector[i];
	}
			
		delete[]vector;
		vector=aux;
		n++;
		
}

/*
void InsertarPrincipio(int *&vector, int &n, int valor) //compila bien
{
	int *aux= new int[n+1];
	
	for(int i =0; i<n ; i++)
		aux[i+1]=vector[i];
	
	aux[0]=valor;
	delete[]vector;
	vector=aux;
	n++;
}
	

	
void EliminaUltimo(int *&vector , int &n) //compila bien
{
	
	int *aux = new int[n-1];
	
	for(int i =0 ; i<n-1 ; i++)
		aux[i] = vector[i];
		
	
	delete[]vector;
	vector=aux;
	n--;
}
	
*/





int main()
{
	int *vector;
	int n;
	int posicion;
	int valor;
	
	cout << "Introduzca tamaño del vector " << endl;
	cin >> n;
	
	cout << "Introduzca el valor a introducir " << endl;
	cin >> valor;
	
	cout << "Introduzca posicion en la que desea introducir el valor " << endl;
	cin >> posicion;
	
	
	vector = new int[n];
	
	for(int i=0 ; i<n ; i++)
	{
		cout << "Introduzca valor: " << i << endl;;
		cin >> vector[i];
	}
		
	InsertarPosicion(vector, n, posicion, valor);
	
	//InsertarPrincipio(vector, n, valor);
	//EliminaUltimo(vector, n);
	
	for(int i=0; i<n; i++)
		cout << vector[i] << "  " ;
	
}
