#include "Coche.h"
#include <iostream>
#include <fstream>
#include <windows.h>


int Coche::getCodigo() const {
	return codigo;
}
int Coche::getPrecio() const {
	return precio;
}
string Coche::getNombre()const {
	return nombre;
}
