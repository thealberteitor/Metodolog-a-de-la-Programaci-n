/*
 * Programa: triangulo.cpp
 *
 * Este programa crea un triángulo de pascal para consultar valores de "n sobre m".
 * Un ejemplo de ejecución es:
 *
 *   prompt> ./triangulo 5
 *   Triángulo creado: 
 *   1 
 *   1 1 
 *   1 2 1 
 *   1 3 3 1 
 *   1 4 6 4 1 
 * 
 * Observe que los enteros se calculan como suma de dos de la fila anterior.
 *
 * Para almacenar los números, deberá crear y destruir una estructura de 
 * almacenamiento compatible con el resto de funciones ya implementadas.
 * El programa está terminado a falta de las funciones "Crear" y "Destruir", 
 * que se encargan respectivamente, de reservar espacio en memoria dinámica 
 * y de liberarlo.
 *
 * Escriba las funciones que faltan y someta todo el archivo triangulo.cpp como solución al examen.
 *
*/

/*
   En la solución, cada fila del triángulo se almacena en un vector independiente. 
   Todas las filas se controlan con un vector de punteros a las filas. 
   
        n  datos
        ___ ___    
       | 6 | * |
       ¯¯¯¯ ¯\¯¯
              |
              | 
              v
             |*-|----------------->| 1 |               (Fila 0)
             |*-|------------->  | 1 | 1 |             (Fila 1) 
             |*-|------------> | 1 | 2 | 1 |           (Fila 2)  
             |*-|---------> | 1 | 3 | 3 | 1 |          (Fila 3)
             |*-|-------->| 1 | 4 | 6 | 4 | 1 |        (Fila 4)
             |*-|------>| 1 | 5 |10 | 10| 5 | 1 |      (Fila 5) 
             
       donde datos[i][j]=1 si j=0 o j=i y datos[i][j]=datos[i-1][j-1]+datos[i-1][j]  
*/                 


#include <iostream>
#include <cstdlib> // atoi
using namespace std;

struct TrianguloPascal {
  int **datos; 
  int n;        // número de filas del triángulo
};          


/*______________ RELLENAR CON FUNCIONES Crear, Destruir _____________________

*/
void Crear(TrianguloPascal &t, int filas){
    t.n = filas;
    t.datos = new int*[filas];
    int contador=1;
    
    for (int i=0; i< filas; i++){
      t.datos[i] = new int[contador];
      t.datos[i][0]=1;
      contador++;
    }

    if (filas > 1){
      for (int i=1; i< filas; i++){
	for (int j=1; j<=i; j++){
          if (i == j)
	     t.datos[i][j] = 1;
	  else{
	     t.datos[i][j] = t.datos[i-1][j-1] + t.datos[i-1][j];
          }
        }
      }
    }
}


void Destruir(TrianguloPascal &t){
   for (int i=0; i< t.n; i++)
      delete [] t.datos[i];
   delete [] t.datos;
}




void Imprimir(ostream& os, const TrianguloPascal& t)
{
  for (int f=0;f<t.n;++f) {
    for (int c=0;c<f+1;++c)
      os << t.datos[f][c] << ' ';
    os << endl;
  }
}

int main(int argc, char *argv[])
{
  if (argc==1) {
    cerr << "Error, uso: " << argv[0] << " <número filas>" << endl;
    return 1;
  }
  else {
    int filas=0;
    filas=atoi(argv[1]);
    if (filas==0) {
      cerr << "Número de filas debe ser al menos 1" << endl;
      return 1;
    }
    else {
      TrianguloPascal t;
      
      Crear(t,filas);
      cout << "Triángulo creado: " << endl;
      Imprimir(cout,t);

      Destruir(t);
    } 
  }
}
