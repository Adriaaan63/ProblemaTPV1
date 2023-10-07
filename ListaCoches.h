#pragma once
#include "Coche.h"
#include <iostream>
using namespace std;
class ListaCoches
{
private:
	int tam = cont + 10;
	Coche* coche;
	int cont;
public:
	ListaCoches();
	ListaCoches(int tam, Coche* coche, int cont);
	int getTam() const;
	bool leerModelos();
	int buscarCoche(int codigo);
};

