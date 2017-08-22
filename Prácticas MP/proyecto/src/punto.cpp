#include"punto.h"
#include<iostream>
#include<cmath>

using namespace std;

// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto()
{
   Punto p;
   char c;
   cin >> c >> p.x >> c >> p.y >> c;
  return p;
}

// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (Punto p)
{
   cout << "(" << p.x << "," << p.y << ")";
}

// Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy)
{
   p.x = cx;
   p.y = cy;
}

// Devuelve la coordenada X del punto p
double GetX (Punto p)
{
   return p.x;
}

// Devuelve la coordenada Y del punto p
double GetY (Punto p)
{
   return p.y;
}

// Devuelve la distancia euclídea entre p1 y p2
double Distancia (Punto p1, Punto p2)
{
   return sqrt((pow(p1.x - p2.x, 2) + (pow(p1.y - p2.y, 2) )));
}

// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (Punto p1, Punto p2)
{
   Punto pmedio;
   pmedio.x = ( p1.x + p2.x ) / 2;
   pmedio.y = ( p1.y + p2.y ) / 2;
  return pmedio;
}
