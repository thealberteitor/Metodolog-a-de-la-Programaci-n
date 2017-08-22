#include"circulo.h"
#include<iostream>
#include<cmath>

using namespace std;

Circulo LeerCirculo()
{
Circulo circulo1;
char c;
cin >> circulo1.radio >> c;
circulo1.centro = LeerPunto();
return circulo1;

}

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(Circulo c)
{
cout << c.radio << "-";
EscribirPunto(c.centro);
}

// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, Punto centro, double radio)
{
c.radio = radio;
c.centro.x = centro.x;
c.centro.y = centro.y;
}

// Devuelve del centro de c
Punto Centro (Circulo c)
{
return c.centro;
}

// Devuelve el radio de c
double Radio (Circulo c)
{
return c.radio;
}

// Devuelve el área del círculo c
double Area (Circulo c)
{
return (M_PI * pow(c.radio, 2));

}

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (Circulo c1, Circulo c2)
{
   return (Distancia(c1.centro, c2.centro) - c1.radio - c2.radio);
}

// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (Punto p, Circulo c)
{
if (Distancia(p, c.centro) < c.radio )
   return true;
else
   return false;

}
