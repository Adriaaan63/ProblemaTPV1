#include <iostream>
#include <fstream>
#include <windows.h>
#include "Date.h"
#include <string>

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
};
struct ListaCoches
{
	Coche* Coche;
	int cont;
	int tam = cont + 10;
};
struct ListaAlquileres
{
	Alquiler* Alquiler;
	int cont;
	int tam = cont + 10;;
};
int main() {
	SetConsoleOutputCP(CP_UTF8);
}
bool leerModelos(ListaCoches listaCoches)
{
	ifstream entrada("coches.txt");
	entrada.open("coches.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else
	{
		entrada >> listaCoches.tam;
		listaCoches.Coche = new Coche[listaCoches.tam];
		for (int i = 0; !entrada.eof(); i++)
		{
			entrada >> listaCoches.Coche[i].codigo;
			entrada >> listaCoches.Coche[i].precio;
			getline(entrada, listaCoches.Coche[i].nombre);
		}
		return true;
	}
}

