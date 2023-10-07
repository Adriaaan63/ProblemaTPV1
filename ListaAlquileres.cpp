#include "ListaAlquileres.h"
#include "ListaCoches.h"
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
			entrada >> listaAlquileres.Alquiler[i].codigo;
			entrada >> listaAlquileres.Alquiler[i].fecha;
			entrada >> listaAlquileres.Alquiler[i].dias;
			//cout << listaAlquileres.Alquiler[i].codigo << listaAlquileres.Alquiler[i].fecha << listaAlquileres.Alquiler[i].dias << endl;
			int indice = buscarCoche(listaCoches, listaAlquileres.Alquiler[i].codigo);
			if (indice == -1) {
				listaAlquileres.Alquiler[i].Coche = nullptr;
			}
			else {
				listaAlquileres.Alquiler[i].Coche = &listaCoches.Coche[indice];

			}
		}


		return true;
	}
}
