#include <fstream>
#include <iostream>
using namespace std;

void Siguiente(std::istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); 
    else is.ignore();
  }
}

double Sumatoria(istream& is) 
{
  double s=0, dato;
  
  Siguiente(is);
  while (is >> dato) {
    s+=dato;
    Siguiente(is);
  }
  return s;
}

int main(int argc, char* argv[])
{

double sumatoria= 0;

bool fin_entrada;

if (argc==1) {
 
    sumatoria= Sumatoria(cin);
    fin_entrada=cin.eof();

  }else {

    ifstream f(argv[1]); 

if (!f) {

      cout << "Error: no se abre " << endl;
      return 1;

    }

    sumatoria=Sumatoria(f);
    fin_entrada=f.eof();

  }
  
if (!fin_entrada) {
     cout << "Error inesperado. No se ha leído toda la entrada" << endl;

     return 1;
  }

  cout << "Sumatoria de la entrada: " << sumatoria << endl; 

}
