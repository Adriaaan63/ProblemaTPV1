#include "ListaCoches.h"
#include "Coche.h"
#include <iostream>
#include <fstream>
#include <windows.h>
ListaCoches::ListaCoches() : tam(), coche(), cont() {}
ListaCoches::ListaCoches(int tam, Coche* coche, int cont) : tam(tam), coche(coche), cont(cont) {}

//int ListaCoches::getTam() const{
//	return tam;
//}
Coche* ListaCoches::getCoche() const {
	return coche;
}
bool ListaCoches::leerModelos()
{
	ifstream entrada;
	entrada.open("coches.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else
	{
		entrada >> tam;
		coche = new Coche[tam];
		for (int i = 0; !entrada.eof() && i < tam; i++)
		{
			entrada >> coche[i];
			getline(entrada, coche[i]);
			//cout << listaCoches.Coche[i].codigo << listaCoches.Coche[i].precio << listaCoches.Coche[i].nombre << endl;
		}
		return true;
	}
}
int ListaCoches::buscarCoche(int codigo) const {
	int left = 0;
	int right = tam - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (coche[mid].getCodigo() == codigo)
			return mid;
		else if (coche[mid].getCodigo() < codigo)
			left = mid + 1;
		else right = mid - 1;
	}
	return -1;

}
