#include "ListaAlquileres.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "checkML.h"
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
		tam += 10;
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
			cont++;
		}
		return true;
	}
}
void ListaAlquileres::ordenarAlquileres(int totalAlquileres) {

	sort(alquiler, alquiler + totalAlquileres);
}
bool operator<(const Alquiler& izdo, const Alquiler& dcho) {
	// Definición del orden
	return izdo.getFecha() < dcho.getFecha();
}
void ListaAlquileres::mostrarAlquileres() {
	ordenarAlquileres(cont);
	for (int i = 0; i < tam; i++) {
		if (alquiler[i].getCoche() == nullptr) {
			cout << alquiler[i].getFecha() << " ERROR: Modelo inexistente" << endl;
		}
		else
		{
			cout << alquiler[i].getFecha() << alquiler[i].getCoche()->getNombre() << " " << alquiler[i].getDias() << " dia(s) por " << alquiler[i].getDias() * alquiler[i].getCoche()->getPrecio() << " euros" << endl;
		}

	}
}
void ListaAlquileres::agregarAlquiler(const ListaCoches& listaCoches) {
	Alquiler nuevoAlquiler;
	cout << "Ingrese los datos del nuevo alquiler: ";
	cin >> nuevoAlquiler;
	agregarAlquiler2(nuevoAlquiler, listaCoches);

}
void ListaAlquileres::agregarAlquiler2(const Alquiler& nuevoAlquiler, const ListaCoches& listaCoches) {
	if (cont < tam) {
		alquiler[cont] = nuevoAlquiler;
		int indice = listaCoches.buscarCoche(alquiler[cont].getCodigo());
		if (indice == -1) {
			alquiler[cont].setCoche(nullptr);
		}
		else {
			alquiler[cont].setCoche(&listaCoches.getCoche()[indice]);

		}
		cont++;
		cout << "Alquiler agregado exitosamente." << endl;
	}
	else
	{
		cout << "La lista de alquileres esta llena. No se puede agregar mas." << endl;
	}
}


