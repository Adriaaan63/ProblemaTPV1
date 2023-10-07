#pragma once
#include <iostream>
#include <string>
using namespace std;
class Coche
{
private:
	int codigo;
	int precio;
	string nombre;
public:
	int getCodigo() const;
	int getPrecio() const;
	string getNombre()const;

};

