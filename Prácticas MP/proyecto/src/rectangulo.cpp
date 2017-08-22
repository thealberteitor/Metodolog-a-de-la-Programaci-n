#include <iostream>
#include <fstream>
#include <cmath> 

#include "punto.h"
#include "rectangulo.h"
using namespace std;

bool LeerRectangulo(std::istream& is, Rectangulo& p){
	bool leer = false;
	Punto aux;
	char guion;
	if (! ( cin.fail() )){
		leer= true;
		LeerPunto(is, aux);
		p.inf_izq.x = aux.x;	
		p.inf_izq.y = aux.y;		
		is >> guion;		
		LeerPunto(is, aux);
		p.sup_der.x = aux.x;
		p.sup_der.y = aux.y;	

		if(cin.fail())
			leer=false;
	}
	return leer;
}
bool EscribirRectangulo(std::ostream& os, const Rectangulo& p){
	bool escribir=true;
	EscribirPunto(os, p.inf_izq);
	os << "-";
	EscribirPunto(os, p.sup_der);
	return escribir;
}
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2){

	if ( (p1.x <= p2.x) && (p1.y <= p2.y) ){
		r.inf_izq.x = p1.x;
		r.inf_izq.y = p1.y;
		r.sup_der.x = p2.x;
		r.sup_der.y = p2.y;
	}
	if ( (p1.x >= p2.x) && (p1.y >= p2.y) ){
		r.inf_izq.x = p2.x;
		r.inf_izq.y = p2.y;
		r.sup_der.x = p1.x;
		r.sup_der.y = p1.y;
	}


	if ( (p1.x <= p2.x) && (p1.y >= p2.y) ){
		r.inf_izq.x = p1.x;
		r.inf_izq.y = p2.y;
		r.sup_der.x = p2.x;
		r.sup_der.y = p1.y;
	}



	if ( (p1.x >= p2.x) && (p1.y <= p2.y) ){
		r.inf_izq.x = p2.x;
		r.inf_izq.y = p1.y;
		r.sup_der.x = p1.x;
		r.sup_der.y = p2.y;
	}
}


Punto InferiorIzquierda(const Rectangulo& r){
	return r.inf_izq;
}
Punto SuperiorDerecha(const Rectangulo& r){
	return r.sup_der;
}
double Area(const Rectangulo& r){
	double lado1, lado2;
	lado1= r.sup_der.x - r.inf_izq.x; 
	lado2= r.sup_der.y - r.inf_izq.y; 
	return lado1 * lado2;
}
bool Interior(const Punto& p, const Rectangulo& r){
	bool interior;
	if ( (p.x >= r.inf_izq.x && p.y >= r.inf_izq.y) &&
	     (p.x <= r.sup_der.x && p.y <= r.sup_der.y) )
		interior=true;
	else
		interior=false;
	return interior;

}

bool AmpliarRectangulo(Rectangulo& r, const Punto& p){
	bool verificacion = false;	
	if (r.inf_izq.x > p.x){
		r.inf_izq.x = p.x;
		verificacion = true;
	} 
	else if (r.sup_der.x < p.x){
		r.sup_der.x = p.x;
		verificacion = true;
	} 
	if (r.inf_izq.y > p.y){
		r.inf_izq.y = p.y;
		verificacion = true;
	} 
	else if (r.sup_der.y < p.y){
		r.sup_der.y = p.y;
		verificacion = true;
	} 
	return verificacion;
}


