#include <iostream>
#include <fstream>
#include <windows.h>
#include "Date.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Coche {
	int codigo;
	int precio;
	string nombre;
};
struct Alquiler {
	int codigo;
	Date fecha;
	int dias;
	Coche* Coche;
};
struct ListaCoches
{
	int tam = cont + 10;
	Coche* Coche;
	int cont;
	
};
struct ListaAlquileres
{
	Alquiler* Alquiler;
	int cont;
	int tam = cont + 10;;
};
bool leerModelos(ListaCoches& listaCoches)
{
	ifstream entrada;
	entrada.open("coches.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else
	{
		entrada >> listaCoches.tam;
		listaCoches.Coche = new Coche[listaCoches.tam];
		for (int i = 0; !entrada.eof() && i < listaCoches.tam; i++)
		{
			entrada >> listaCoches.Coche[i].codigo;
			entrada >> listaCoches.Coche[i].precio;
			getline(entrada, listaCoches.Coche[i].nombre);
			//cout << listaCoches.Coche[i].codigo << listaCoches.Coche[i].precio << listaCoches.Coche[i].nombre << endl;
		}
		return true;
	}
}
int buscarCoche(const ListaCoches& listaCoches, int codigo) {
	int left = 0;
	int right = listaCoches.tam -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (listaCoches.Coche[mid].codigo == codigo)
			return mid;
		else if (listaCoches.Coche[mid].codigo < codigo)
			left = mid + 1;
		else right = mid - 1;
	}
	return -1;

}

bool leerAlquileres(ListaAlquileres& listaAlquileres,const ListaCoches& listaCoches) 
{
	ifstream entrada;
	entrada.open("rent.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else {
		entrada >> listaAlquileres.tam;
		listaAlquileres.Alquiler = new Alquiler[listaAlquileres.tam];
		for (int i = 0;!entrada.eof() && i < listaAlquileres.tam; i++) {
			entrada >> listaAlquileres.Alquiler[i].codigo;
			entrada >> listaAlquileres.Alquiler[i].fecha;
			entrada >> listaAlquileres.Alquiler[i].dias;
			//cout << listaAlquileres.Alquiler[i].codigo << listaAlquileres.Alquiler[i].fecha << listaAlquileres.Alquiler[i].dias << endl;
			int indice = buscarCoche(listaCoches, listaAlquileres.Alquiler[i].codigo);
			if ( indice == -1) {
				listaAlquileres.Alquiler[i].Coche = nullptr;
			}
			else {
				listaAlquileres.Alquiler[i].Coche = &listaCoches.Coche[indice];
				
			}
		}
		
		
		return true;
	}
}

void ordenarAlquileres(Alquiler* listaAlquileres, int totalAlquileres) {
	
	sort(listaAlquileres, listaAlquileres + totalAlquileres);
	/*for (int i = 0; i < totalAlquileres; i++) {
		cout << listaAlquileres[i].Coche->nombre << " ";
	}*/
}
bool operator<(const Alquiler& izdo, const Alquiler& dcho) {
	// Definici�n del orden
	return izdo.fecha < dcho.fecha;
}
void mostrarAlquileres(const ListaAlquileres& listaAlquileres) {
	for (int i = 0; i < listaAlquileres.tam; i++) {
		if (listaAlquileres.Alquiler[i].Coche == nullptr) {
			cout << listaAlquileres.Alquiler[i].fecha << " ERROR: Modelo inexistente" << endl;
		}
		else
		{
			cout << listaAlquileres.Alquiler[i].fecha << listaAlquileres.Alquiler[i].Coche->nombre<< " " << listaAlquileres.Alquiler[i].dias << " dia(s) por " << listaAlquileres.Alquiler[i].dias * listaAlquileres.Alquiler[i].Coche->precio << " euros" << endl;
		}
		
	}
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	ListaCoches Coche;
	ListaAlquileres Alquileres;
	leerModelos(Coche);
	leerAlquileres(Alquileres, Coche);
	ordenarAlquileres(Alquileres.Alquiler, Alquileres.tam);
	mostrarAlquileres(Alquileres);
}
