#include <iostream>
#include <string>
#include <fstream>
#include "matriz_bit.h"

using namespace std;


bool Inicializar (MatrizBit& m, int fils, int cols){
 
  bool inicializar = true;
  if (fils * cols > 128){
    inicializar = false;
  }
  if (inicializar){
    for (int i=0; i<4; i++){
      m.matriz[i]=0;
    }
    m.dimension = (fils << 8) + cols;
  }
  return inicializar;
}


int Columnas (const MatrizBit& m){
  int cols = m.dimension & 255;
  return cols;
}


int Filas (const MatrizBit& m){
  int fils = (m.dimension >> 8);
  return fils;
}


bool Get(const MatrizBit& m, int f, int c){
  bool casilla;
  int pos, a, k, booleano;
  if ((f < Filas(m)) && (c < Columnas(m))){
    pos = f*Columnas(m) + c;
    a = pos / 32;
    k = pos % 32;
    casilla = (m.matriz[a] >> k) & 1; /
    booleano = (m.matriz[a] >> k) & 1; 
      if (booleano == 1)
        casilla = true;
      else if (booleano == 0)
        casilla = false;
  }
	return casilla; 
}

void Set(MatrizBit& m, int f, int c, bool v){
  unsigned int aux;
  int pos, a, k;
  
  if ( (f < Filas(m)) && (c < Columnas(m) )){
    pos = f*Columnas(m) + c;
    a = pos / 32;
    k = pos % 32;
    aux = 1 << k;
    
    //aux = ~aux;
    m.matriz[a] = m.matriz[a] & aux
    if (v){
      //aux = ~ aux;
      m.matriz[a] = m.matriz[a] | aux;
    }
  }
}
