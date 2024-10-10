/*
1.Se tiene un polinomio almacenado en un arreglo. Se pide leer un monomio y buscar si forma parte del polinomio. 
Usa búsqueda secuencial
*/

#include <iostream>
#include <string>

using namespace std;

struct Polinomio{
	int coeficiente; 
	int exponente; 
};

void mostrarPolinomio(int n, Polinomio a[]){
	cout<<"\nP(x)=";
	for(int i=0; i<n; i++){
		cout<<a[i].coeficiente<<"x^"<<a[i].exponente;
		if (i < n-1) {
            cout<<"+";  
        }
	}  
	cout<<endl; 
}

int busquedaSecuencial(int n, Polinomio pol[], int coef, int exp) {
    int i = 0;
    int pos = -1; 

    while (i < n) {
        if (pol[i].coeficiente == coef && pol[i].exponente == exp) {
            pos = i;  
        }
        i++;
    }
    
    return pos;  
}

int main(){
	int coef, exp; 
	int R; 
	
	Polinomio pol[4]={{3,5},{2,4},{1,3},{4,2}}; 
	
	int n = 4; 
	
	mostrarPolinomio(n, pol);	
	
	cout<<"Digite un monomio para saber si existe en el arreglo: "<<endl; 
	cout<<"Coeficiente: "; 
	cin>>coef; 
	cout<<"Exponente: "; 
	cin>>exp; 
	
	R = busquedaSecuencial(n, pol, coef, exp); 
	
	cout<<endl; 
	if (R >= 0) {
        cout << "El monomio " << coef << "x^" << exp << " existe en el polinomio." << endl;
    } 
	else {
        cout << "El monomio " << coef << "x^" << exp << " no existe en el polinomio." << endl;
    }
	
	
	return 0; 
}