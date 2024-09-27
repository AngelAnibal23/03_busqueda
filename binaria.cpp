#include <iostream> 
using namespace std; 

int busquedaBinaria(int[], int, int); 

int main(){
	int n;
	int retorno;
	int dato;   
	
	cout<<"Digite la cantidad de elementos del arreglo: "; 
	cin>>n; 
	
	int a[n]; 
	
	for(int i=0; i<n; i++){
	   cout<<"Elemento: "<<1+i<<endl;
	   cin>>a[i]; 
	}
	
	cout<<"\nDigite el elemento a buscar en el arreglo: ";
	cin>>dato; 
	
	retorno = busquedaBinaria(a, n, dato); 
	
	if(retorno >= 0){
		cout<<"El elemento existe en el arreglo y se encuentra en el indice :" << retorno<<endl; 
	}
	else{
		cout<<"No se encontro el elemento. "<<endl;
		cout<<"El elemento se deberia ubicar en: "<<-retorno<<endl; 
	}
	
	return 0; 
}

int busquedaBinaria(int a[], int n, int dato){
	int izq =0; 
	int der = n; 
	int cen = 0; 
	int m;
	int pos = -1; 
	
	while(izq <= der && cen==0){
	    m = (izq + der)/2;
	    if(a[m] == dato){
	    	cen = 1;
		pos = m;  
	    	
	    }
	    else{
	    	if(dato > a[m]){
	    		izq = m+1; 
		    }
		    else{
		    	der = m -1; 
		    }
	    }
	}
	
	if(cen == 1){
		pos = m; 
	}
	else{
		pos = -izq; 
	}
	
	return pos; 
}