#include <iostream>
using namespace std; 

int secuencialDes(int[], int, int); 
int secuencialOrd(int[], int, int); 

int main(){
	int n = 11; 
	//elementos desordenados. 
	int a[]={3,5,7,9,3,1,2,32,5,75,34}; 
	int dato; 
	int encuentraDes;
	int encuentraOrd;  

	cout<<"Busqueda con elementos desordenados: "<<endl; 
	for(int i=0; i<n; i++){
		cout<<a[i]<<" "; 
	}
	cout<<endl; 
	
	cout<<"\nDigite el dato que quiere buscar: "; 
	cin>>dato;
	 
	encuentraDes = secuencialDes(a, n, dato); 
	
	cout<<endl; 
	if(encuentraDes >= 0){
		cout<<"El elemento existe en el arreglo. "<<endl; 
	}
	else{
		cout<<"El elemento no existe en el arreglo. "<<endl; 
	}
	
	//elementos ordenados. 
	int e[]={1,2,3,4,5,6,7,8,9,10,11};
	
	cout<<"\nBusqueda con elementos ordenados: "<<endl; 
	for(int i=0; i<n; i++){
		cout<<e[i]<<" "; 
	}
	cout<<endl; 
	
	cout<<"\nDigite el dato que quiere buscar: "; 
	cin>>dato;
	
	encuentraOrd = secuencialOrd(e, n ,dato); 
	
	if(encuentraOrd < 0){
		cout<<"El elemento no existe en el arreglo. "<<endl; 
	}
	else{
		cout<<"El elemento existe en el arreglo. "<<endl; 
	}
	
	return 0; 
}
int secuencialDes(int a[], int cant, int dato){
	int pos = 0; 
	int i = 0;
	
	while(i<= cant && a[i] != dato){
		i++; 
	}
	
	if(i<=cant){
	   pos = i; 
	}
	
	return pos; 
 }
 
int secuencialOrd(int a[], int cant, int dato){
	int pos; 
	int i=0; 
	
	while(i <= cant && a[i] < dato){
		i++;
	}
	
	if(i > cant ||  a[i] > dato){
		pos = -i; 
	}
	else{
		pos = i; 
	}
	
	return pos; 
}
