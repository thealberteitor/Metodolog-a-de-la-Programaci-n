#include<iostream>
#include<fstream>
#include<string>
#include"matriz_bit.h"
#include"matriz_operaciones.h"

bool Leer(std::istream& is, MatrizBit& m){	
	bool booleano = true;

	if( (is.peek() != 'X') && (is.peek() != '.')){
		int f, c;
		char aux;
		bool booleano = true;	

		is >> f;
		is >> c;

		if(Inicializar(m,f,c)){
			for(int i=0; i < f; i++){
				for(int j=0; j < c; j++){
					is >> aux;
					Set(m,i,j,aux=='1');
				}
			}
		}else{
			booleano = false;
			return booleano;
		}
	}
	
	if (is.peek() == 'X' || is.peek() == '.'){

		int i=0;
		int j=0;
		int d=0;
		int columnas;
		char caracter;
        	bool buffer[128];
       		while ((is.peek() == 'X' || is.peek() == '.') && (d < 128)){
          		j=0; 
           		while(is.peek() != '\n'){
              			is >> caracter;

             			if (caracter == 'X'){
                			buffer[d] = true;
              			}else{
              				buffer[d] = false;
              			}
             			 j++;
             			 d++;
           		 }
            
         		if (i == 0){
           			columnas = j;
          		}else{
            			if (columnas != j){
               				booleano = false;
				}
          		}
          		i++;

          		while ( (is.peek() == '\n') || (is.peek() == '\t') || (is.peek() == ' ') ){
            			is.get(caracter);
			} 
       		}
        
        	if (d == 128){
          		booleano = false;
        	}else{

          		if (Inicializar(m, i, columnas)){
          			for (int i2=0; i2< Filas(m); i2++){
              				for (int j2=0; j2< Columnas(m); j2++){
                				Set(m, i2, j2, buffer[i2*Columnas(m) + j2]);
              				}
            			}
          		}else{
           			booleano = false;
			}
        	}
      }else
	booleano = false;
     	
  return booleano;
	
}


bool Escribir(std::ostream& os, const MatrizBit& m){
		
	bool booleano = true;

	os << Filas(m) << "  " << Columnas(m) << endl;

	for(int i=0; i<Filas(m); i++){	
		for(int j=0 ; j<Columnas(m); j++){
			os << Get(m,i,j) << "  " ;
		}
		os << endl;
	}

	return booleano;

}

bool Leer(const char nombre[], MatrizBit& m){
	ifstream is(nombre);
	return Leer(is,m);
}	

bool Escribir(const char nombre[], const MatrizBit& m){
	ofstream os(nombre);
	return Escribir(os,m);
}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){

	Inicializar(res,Filas(m1),Columnas(m1));

	if(Filas(m1)==Filas(m2) && Columnas(m1)==Columnas(m2)){
		for(int i=0; i<Filas(m1) ; i++){
			for(int j=0; j<Columnas(m1); j++){ 				
				Set(res,i,j,(Get(m1,i,j) && Get(m2,i,j)));
			}
		}
	}else{

	cout << "Dimensiones diferentes" << endl;

	}
}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
	
	Inicializar(res,Filas(m1),Columnas(m1));

	if(Filas(m1)==Filas(m2) && Columnas(m1)==Columnas(m2)){
		for(int i=0; i<Filas(m1) ; i++){
			for(int j=0; j<Columnas(m1); j++){
				Set(res,i,j,(Get(m1,i,j) || Get(m2,i,j)));
			}
		}
	}else{

	cout << "Dimensiones diferentes" << endl;

	}
}

void Not(MatrizBit& res, const MatrizBit& m){

	Inicializar(res,Filas(m),Columnas(m));

	for(int i=0; i<Filas(m) ; i++){
			for(int j=0; j<Columnas(m); j++){
				Set(res,i,j,!Get(m,i,j));
			}
	}

}


void Traspuesta(MatrizBit& res, const MatrizBit& m){

	Inicializar(res,Columnas(m),Filas(m));

	for(int i = 0; i<Filas(m); i++){
		for(int j = 0; j<Columnas(m); j++){
			Set(res,j,i,Get(m,i,j));

		}
	}
}


















































