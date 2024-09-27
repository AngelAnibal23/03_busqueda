#include <iostream>
using namespace std; 

int secuencialDes(int[], int, int); 

int main(){
	//elementos desordenados. 
	int a[]={3,5,7,9,3,1,2,32,5,75,34}; 
	int dato; 
	int encuentra; 

	for(int i=0; i<11; i++){
		cout<<a[i]<<" "; 
	}
	
	int n = 11; 
	
	cout<<"\nDigite el dato que quiere buscar: "; 
	cin>>dato;
	 
	encuentra = secuencialDes(a, n, dato); 
	
	if(encuentra > 0){
		cout<<"El elemento existe en el arreglo. "<<endl; 
	}
	else{
		cout<<"El elemento no existe en el arreglo. "<<endl; 
	}
	
	return 0; 
}
int secuencialDes(int a[], int cant, int dat){
	int pos = 0; 
	int i = 0;
	
	while(i<= cant && a[i] != dat){
		i++; 
	}
	
	if(i<=cant){
	   pos = i; 
	   return pos; 	 
	}
	else{
	   return pos; 
	}
 }