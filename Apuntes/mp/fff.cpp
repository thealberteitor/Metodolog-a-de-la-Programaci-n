#include<iostream>

using namespace std;

void InsertarPrincipio(int *&vector, int &n, int valor)
{
	int *aux = new int[n+1];
	
	for(int i=0 ; i<n ; i++)
		aux[i+1] = vector[i];
		
	aux[0] = valor;

	delete[]vector;

	vector = aux;
	
	n++;	
		
}

void EliminaUltimo(int *&vector , int &n)
{
	int *aux = new int[n-1];
	
	for(int i=0 ; i<n-1 ; i++)
		aux[i]=vector[i];
		
	delete[]vector;
	vector = aux;
	
	n--;
	
}
	
	


int main()
{
	int *vector;
	
	int n;
	
	cin >> n;
	
	vector = new int[n];
	
	EliminaUltimo(vector, n);
	
	
	

}
