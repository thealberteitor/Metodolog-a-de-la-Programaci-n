#include<iostream> 

using namespace std;

class Vector{
		
	double *datos;
	int n;
	int reservados;
	
public:
	
	Vector(): datos(0),n(0),reservados(0){}
	
	~Vector(){ delete[]datos{}
	
	Vector(const Vector& v);
	
	vector& operator=(const vector& v);
	
	void set(int i, double d);
	
	double get(int i) const;
	
	int size() const {return n;}  //función inline ya que es muy corta
	
	void resize(int nuevo)
	
	
	//assert(i>=0 && i<n)
	
	//cpp
	
	Vector::Vector(const Vector& v)
	{
		datos = new double[v.n];
		n=v.n;
		reservados=v.n  //reservados tiene el mismo tamaño que n
		
		for(int i=0; i<n; i++)
			datos[i]=v.datos[i];
	}
	
	void Vector::set(int i, double d){
		datos[i]=d;
	}
	
	double Vector::get(int i) const;
		return datos[i];
	}
//////////////////////////////////////////////////////////////////////

	class Vector{
		
		void swap(vector& v);
		
		void push_back(double d);
		
		void reserve(int tam);
		
		int capacity() const{
			return reservados;
		}
		
		
		void Vector::swap(Vector& v)
		{
				double *p=datos;
				datos=v.datos;
				v.datos=p;
				int i=n;
				n=v.n
				v.n=i;
				i=v.reservados;
				v.reservados=reservados;
				reservados=i;
			}
			
			
		Vector& Vector::operator=(const Vector& v)
		{
			Vector aux(v);
			this->swap(aux);
			return *this;
		}
		
		void Vector::reserve(int tam)
		{	
			if(tam>reservados)
			{	
				double *aux= new double[tam];
				
				for(int i=0; i<n; i++)
				{
					aux[i]=datos[i];
				}
				delete[]datos;
				datos=aux;
				reservados=tam;
			}
		}
		
		void Vector::push_back(double d)
		{
			if(n==reservados)
			{
				reserve(1);
			}else{
				reserve(2*n);
			}
			datos[n]=d;
			n++;
		}
		
		void Vector::resize(int t)
		{
			if(t>reservados)
				reserve(t);
			n=t;
		}
		
		
		Vector::Vector(int t, double d)         //en el .h se pone d=0
		{
			datos=new double[t];
			
			for(int i=0; i<n; i++)
				datos[i]=d;
				n=reservados=t;
			}
	
	

class Matriz{
//no necesitas ni constructor de copias, ni constructor ni destructor,
// ni operador de asignación porque tienes un vector dentro
	
	int fils, cols;
	Vector datos;
	
public:
	
	Matriz(int f, int c, double d=0):datos(f*c, d)
	{
		fils=f;
		cols=c;
	}
		
		
		
		
		
}

/////////////////////////////

SOBRECARGA DE OPERADOR

Sobrecarga del operador +

función miembro: -> m1.operator+(m2);
función externa: -> operator+(m1, m2);

Matriz operator+(const Matriz& m1, const Matriz& m2)
{
	assert(m1.fils()==m2.fils && m1.cols()==m2.cols());
	
	Matrix aux(m1.fils(), m1.cols());
	
	for(int f=0; f<m1.fils(); f++)
		for(int c=0; c<m1.cols(); c++)
			aux.set(f,c,m1.get(f,c)+m2.get(f,c);
			
	return aux;
}
	
	
	
//funcion inline, asser, friend
	
			
	
	
	ifstream fi("datosin.txt")
	
	ofstream fo("datosout.txt")
	
	if(fi && fo){
			
		char buffer[1024];
		while(fi.read(buffer[1024]))
			fo.write(buffer,1024);
		fo.write(buffer, fi.gcount());
		
		






	<fstream>
	
	int main(){
		
		int v[100];
		for(int i=0; i<100; i++)
			cin >> v[i];
			
		ofstreamf("numero.txt" ; ios::cout|ios::binary);
		f.write((const char *)V, 100*sizeof(int);
		f.clase();
	}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
			
			
			
			
			
			
			
			
			
			
			
			
				
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
