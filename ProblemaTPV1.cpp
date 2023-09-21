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
		delete[]listaCoches.Coche;
		return true;
	}
}
int buscarCoche(ListaCoches listaCoches, int codigo) {
	return 10;
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
		
		//delete[]listaAlquileres.Alquiler;
		return true;
	}
}
//bool operator<(const Alquiler& izdo, const Alquiler& dcho) {
//	// Definición del orden
//}
void ordenarAlquileres(const ListaAlquileres& listaAlquileres) {
	vector<Date> fechas(listaAlquileres.tam);
	for (int i = 0; i < fechas.size(); i++)
	{
		fechas[i] = listaAlquileres.Alquiler[i].fecha;
	}
	sort(fechas.begin(), fechas.end());
	for (auto& elem: fechas) {
		cout << elem << " ";
	}
	
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	ListaCoches Coche;
	ListaAlquileres Alquileres;
	leerModelos(Coche);
	leerAlquileres(Alquileres, Coche);
	ordenarAlquileres(Alquileres);
}
