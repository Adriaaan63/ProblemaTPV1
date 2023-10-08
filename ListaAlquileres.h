#pragma once
#include "Alquiler.h"
#include "ListaCoches.h"
#include "checkML.h"
using namespace std;
class ListaAlquileres
{
private:
	Alquiler* alquiler;
	int cont;
	int tam = cont + 10;
public:
	ListaAlquileres();
	ListaAlquileres(Alquiler* alquiler, int cont, int tam);
	bool leerAlquileres(const ListaCoches& listaCoches);
	void ordenarAlquileres(int totalAlquileres);
	void mostrarAlquileres();
	void agregarAlquiler(const ListaCoches& listaCoches);
	void agregarAlquiler2(const Alquiler& nuevoAlquiler, const ListaCoches& listaCoches);
};

