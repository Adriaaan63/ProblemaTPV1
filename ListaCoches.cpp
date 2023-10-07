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
			entrada >> coche[i].getCodigo();
			entrada >> coche[i].getPrecio();
			getline(entrada, coche[i].getNombre());
			//cout << listaCoches.Coche[i].codigo << listaCoches.Coche[i].precio << listaCoches.Coche[i].nombre << endl;
		}
		return true;
	}
}
