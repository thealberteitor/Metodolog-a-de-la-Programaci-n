#include"punto.h"

struct Circulo {
    Punto centro;
    double radio;
};


Circulo LeerCirculo();

void EscribirCirculo(Circulo c);

void InicializarCirculo (Circulo& c, Punto centro, double radio);

Punto Centro (Circulo c);

double Radio (Circulo c);

double Area (Circulo c);

double Distancia (Circulo c1, Circulo c2);

bool Interior (Punto p, Circulo c);
