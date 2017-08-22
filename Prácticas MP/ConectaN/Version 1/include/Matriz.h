#ifndef __MATRIZ_H__
#define __MATRIZ_H__

class Matriz{

	private:

		static const int FILS=20;
		static const int COLS=20;
		char matriz[FILS][COLS];
		int fils;
		int cols;

	public:

		Matriz();

		Matriz(int fils, int cols);

		char getfil() const;

		char getcol() const;

		char getm(int fil, int col) const;

		void set(int fil, int col, char valor);

};

#endif
