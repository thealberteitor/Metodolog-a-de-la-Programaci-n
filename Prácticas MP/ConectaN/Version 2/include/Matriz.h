#ifndef __MATRIZ_H__
#define __MATRIZ_H__
#include<fstream>
#include<iostream>

using namespace std;

class Matriz{

		char *datos;
		int fils,cols;

	public:
		Matriz();

		~Matriz();

		Matriz(const Matriz &orig);

		Matriz(int fils, int cols);

		char getfil() const;

		char getcol() const;

		char getm(int fil, int col) const;

		void setcol(int n);
		
		void setfil(int n);

		void set(int fil, int col, char valor);


		Matriz &operator=(const Matriz& orig);

		friend ostream& operator <<(ostream& os,const Matriz& orig);

		friend istream& operator >>(istream& is,Matriz& orig);


};


#endif
