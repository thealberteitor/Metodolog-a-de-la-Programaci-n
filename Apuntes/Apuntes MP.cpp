//MATRICES PRIMER TIPO

///////////////////////////////////////////////////////////////////////////////

class Matriz{

  private:
    int *datos;
    int fils, cols;
  public:

  ...

}

Matriz::Matriz(){

  datos=NULL;
  fils = cols = 0;
 }

Matriz::~Matriz(){

  delete[]datos;
}

Matriz::Matriz(const Matriz &orig){

  fils=orig.fils;
  cols=orig.cols;

  if(orig.datos!=NULL)
  {
    datos=new int[fils*cols];
    for(int i=0; i=fils*cols; i++)
      datos[i]=orig.datos[i];
  }
  else
    datos=NULL;
}

Matriz::operator=(const Matriz &orig){

  if(this!=&orig){

    delete[]datos;

    fils=orig.fils;
    cols=orig.cols;
    if(orig.datos!=NULL){

      datos=new int[fils*cols];
      for(int i=0; i<fils*cols; i++)
        datos[i]=orig.datos[i];

    }
    else
      datos=NULL;
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////

//MATRICES SEGUNDO TIPO

class Matriz{

  private:
    int **datos;
    int fils, cols;

  public:
    ...

}

Matriz::Matriz(){

  datos=NULL;
  fils=cols=0;

}

Matriz::~Matriz(){

    if(datos!=0){

      for(int i=0; i< fils; i++)
        delete[]datos[i];
      delete[]datos;
    }
}

Matriz::Matriz(const Matriz &orig){

  fils=orig.fils;
  cols=orig.cols;

  if(orig.datos!=NULL)
  {
    datos=new int*[fils];
    for(int i=0; i<fils; i++)
      datos[i]=new int[cols];

    for(int i=0; i<fils; i++){
      for(int j=0; j<cols; j++)
        datos[i][j]=orig.datos[i][j];
    }
  }
}


Matriz:operator=(const Matriz &orig){

  if(this!=&orig){

    for(int i=0; i< fils; i++)
      delete[]datos[i];
    delete[]datos;

    fils=orig.fils;
    cols=orig.cols,;

    if(orig.datos!=NULL)
    {
      datos=new int*[fils];
      for(int i=0; i<fils; i++)
        datos[i]=new int[cols];

      for(int i=0; i<fils; i++)
      {
        for(int j=0; j<cols; j++)
          datos[i][j]=orig.datos[i][j];
      }

    }
    else
      datos=NULL;
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////

//Matriz Dentada

class MatrizDentada{

  private:
    int **datos;
    int *cols;
    int fils;
  public:

  ....
}

Matriz::MatrizDentada(){
  datos=NULL;
  cols=NULL;
  fils=0;
}

Matriz::~MatrizDentada(){

  if(datos!=NULL){

    for(int i=0; i<fils; i++)
      delete[]datos[i];
    delete[]datos;
    delete[]cols;

  }


Matriz:Matriz(const Matriz &orig){

  fils=orig.fils;

  if(orig.datos!=0){

    datos=new int*[fils];
    cols=new int [fils];

    for(int i=0; i<fils; i++)
      datos=new int[orig.cols(i)];
        cols[i]=orig.cols[i];

    for(int i=0; i<fils; i++){
      for(int j=0; j<cols[i] j++)
        datos[i][j]=orig.datos[i][j];
    }
  }
  else
    datos=NULL;
    cols=NULL;
}


///////////////////////////////////////////////////////////////////////////////

//OPERADORES

class Vector{

  private:

    float *datos;
    int n;

    friend ostream& operator<<(ostream &os, const vector &v);

    friend istream& operator>>(istream &is, const vector &v);

  public:

  ...

}


bool Vector::operator!=(const Vector &v) const{

  return!(*this==orig);
}

bool Vector::operator+(const Vector &orig) const{

  Vector suma;
  suma.n = n+orig.n;
  suma.datos = new float[suma.n];
  for(int i=0; i<n; i++)
    suma.datos[i]=datos[i];
  for(int i=n; i< suma.n; i++)
    suma.datos[i]=orig.datos[i-n];

  return suma;

}

bool Vector::operator==(const Vector &orig){

  bool iguales = (n==orig.n);

  for(int i=0; i<n && iguales; i++)
    iguales = (datos[i]==orig.datos[i]);

  return iguales;
}


Vector Vector operator*(int num) const{

  Vector res;
  res.n = n*num;
  res.datos = new float[res.n];
  for(int i=0; i<num; i++){
    for(int j=0; j<n; j++)
      res.datos[i*n+j]=datos[j];
  }
  return res;
}



ostream &operator<<(ostream &os, const Vector &v){

  os << v.n << " " ;

  for(int i=0; i<v.n; i++){
    os << v.datos[i] << " ";
  }

  return os;
}

istream &operator>>(istream &is, Vector &v){

  delete[]v.datos;
  is >> v.n;

  if(n>0){
  v.datos=new float[v.n];

  for(int i=0; i<v.n; i++)
    is >> datos[i];
  }
  else
    v.datos=NULL;
  return is;
}


///////////////////////////////////////////////////////////////////////////////

//OPERADORES EN MATRICES

class Matriz{

  private:

    int **datos;
    int fils, cols;

  public:

  ...
}



ostream &operator<<(ostream &os, const Matriz &m){

  os << m.fils << " " << m.cols;

  for(int i=0; i<m.fils; i++){
    for(int j=0; j<m.cols; j++)
      os << m.datos[i][j] << " ";
  }

  return os;
}

istream &operator>>(istream& is, Matriz &m){

  for(int i=0; i<m.fils; i++)
    delete[]m.fils[i];
  delete[]m.datos;

  is >> m.fils >> m.cols;

  if(m.fils*m.cols > 0){

    m.datos=new int*[m.fils];
    for(int i=0; i<m.fils; i++)
      m.datos[i]=new int[cols];

    for(int i=0; i<m.fils; i++){
      for(int j=0; j<m.cols; j++)
        is >> m.datos[i][j];
    }
  }
  else
    m.datos=0;
  return is;
}

















}








}
























}
