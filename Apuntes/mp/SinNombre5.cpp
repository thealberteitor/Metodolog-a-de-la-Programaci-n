#include <iostream> 
#include <stdio.h> 
#include <string.h> 
using namespace std; 
int main() { 
char *cadena1 = {"mach"}, cadena2[30]; 
cout<<"Ingrese una cadena: "; 
gets(cadena2); 
if(strcmp(cadena1, cadena2) == 0){ 
cout<<"\nLas cadenas son iguales\n"; 
}else{ 
cout<<"\nLas cadenas son diferentes\n";	
if(strcmp(cadena1, cadena2) > 0){ 
cout<<cadena1<<" es mayor a "<<cadena2<<endl;	
}else{ 
cout<<cadena2<<" es mayor a "<<cadena1<<endl; 
} 
} 
cin.get(); 
return 0; 
}
