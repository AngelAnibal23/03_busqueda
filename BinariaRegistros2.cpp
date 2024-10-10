#include <iostream>
#include <string>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anho;
};

struct Personal {
    string dni;
    string nombres;
};

int compararFechas(Fecha fa, Fecha fb) {
    if (fa.anho < fb.anho){
    	return -1;
	} 
    else if (fa.anho > fb.anho){
    	return 1;
	} 
    else if (fa.mes < fb.mes){
    	return -1;
	} 
    else if (fa.mes > fb.mes){
    	return 1;
	}
    else if (fa.dia < fb.dia){
    	return -1;
	} 
    else if (fa.dia > fb.dia){
    	return 1;
	}
    return 0;  
}

void ordenarPorFecha(Personal per[], Fecha fec[], int n) {
    Personal aux2; 
    Fecha aux3; 
	
	for (int i = 1; i < n; i++) {
        aux2 = per[i];
        aux3 = fec[i];
        int k = i - 1;
		
        while (k >= 0 &&  compararFechas(fec[k], aux3) >0) {
            fec[k + 1] = fec[k];
            per[k + 1] = per[k];
            k--;
        }
        fec[k + 1] = aux3;
        per[k + 1] = aux2;
    }
}

int busquedaBinaria(Fecha fec[], int n,  Fecha aux) {
    int izq = 0;
    int der = n - 1;

    while (izq <= der) {
        int m = (izq + der) / 2;
        int A = compararFechas(fec[m], aux);

        if (A == 0)
            return m; 
        else if (A < 0)
            izq = m + 1;
        else
            der = m - 1;
    }

    return -1; 
}

void mostrarPersonal(int n, Personal per[], Fecha fe[]) {
    for (int i = 0; i < n; i++) {
        cout << "DNI: " << per[i].dni << ", Nombre: " << per[i].nombres
             << ", Fecha de nacimiento: " << fe[i].dia << "/" << fe[i].mes << "/" << fe[i].anho << endl;
    }
}

int main() {
    int n;
    cout << "Digite la cantidad de personas: ";
    cin >> n;

    Personal per[n];
    Fecha fec[n];

    for (int i = 0; i < n; i++) {
        cout << "\nDatos del personal " << i + 1 << endl;
        cout << "DNI: ";
        cin >> per[i].dni;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, per[i].nombres);
        cout << "Dia de nacimiento: ";
        cin >> fec[i].dia;
        cout << "Mes de nacimiento: ";
        cin >> fec[i].mes;
        cout << "Anho de nacimiento: ";
        cin >> fec[i].anho;
    }

    ordenarPorFecha(per, fec, n);

    cout << "\nLista de personal ordenada por fecha de nacimiento:\n";
    mostrarPersonal(n, per, fec);

    Fecha aux;
    cout << "\nIngrese la fecha de nacimiento a buscar:\n";
    cout << "Dia: ";
    cin >> aux.dia;
    cout << "Mes: ";
    cin >> aux.mes;
    cout << "Anho: ";
    cin >> aux.anho;

    int R = busquedaBinaria(fec, n, aux);

    if (R != -1) {
        cout << "\nEl personal con la fecha de nacimiento ingresada es:\n";
        cout << "DNI: " << per[R].dni << ", Nombre: " << per[R].nombres << endl;
    } else {
        cout << "\nNo se encontro a ninguna persona con esa fecha de nacimiento.\n";
    }

    return 0;
}
