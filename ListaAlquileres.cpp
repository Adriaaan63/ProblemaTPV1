#include "ListaAlquileres.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include <iostream>
#include <fstream>
#include <windows.h>
ListaAlquileres::ListaAlquileres() : alquiler(), cont(), tam() {}
ListaAlquileres::ListaAlquileres(Alquiler* alquiler, int cont, int tam) : alquiler(alquiler), cont(cont), tam(tam) {}
bool ListaAlquileres::leerAlquileres(const ListaCoches& listaCoches)
{
	ifstream entrada;
	entrada.open("rent.txt");
	if (!entrada.is_open()) {
		return false;
	}
	
	else {
		entrada >> tam;
		alquiler = new Alquiler[tam];
		for (int i = 0;!entrada.eof() && i < tam; i++) {
			entrada >> alquiler[i];
			//cout << listaAlquileres.Alquiler[i].codigo << listaAlquileres.Alquiler[i].fecha << listaAlquileres.Alquiler[i].dias << endl;
			int indice = listaCoches.buscarCoche(alquiler[i].getCodigo());
			if (indice == -1) {
				alquiler[i].setCoche(nullptr);
			}
			else {
				alquiler[i].setCoche(&listaCoches.getCoche()[indice]);

			}
		}
		return true;
	}
}
void ListaAlquileres::ordenarAlquileres(int totalAlquileres) {

	sort(alquiler, alquiler + totalAlquileres);
}
bool operator<(const Alquiler& izdo, const Alquiler& dcho) {
	// Definición del orden
	return izdo.fecha < dcho.fecha;
}
