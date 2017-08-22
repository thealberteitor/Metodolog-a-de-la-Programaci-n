#ifndef rectanguloH
#define rectanguloH
#include "punto.h"
struct Rectangulo{

Punto inf_izq, sup_der;

};

bool LeerRectangulo(std::istream& is, Rectangulo& p);

bool EscribirRectangulo(std::ostream& os, const Rectangulo& p);

void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);

Punto InferiorIzquierda(const Rectangulo& r);

Punto SuperiorDerecha(const Rectangulo& r);

double Area(const Rectangulo& r);

bool Interior(const Punto& p, const Rectangulo& r);

bool AmpliarRectangulo(Rectangulo& r, const Punto& p);

#endif
