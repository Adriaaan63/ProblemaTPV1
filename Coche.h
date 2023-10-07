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
	Coche();
	Coche(int codigo, int precio, string nombre);
	int getCodigo() const;
	int getPrecio() const;
	string getNombre()const;
	friend istream& operator>>(std::istream& in, Coche& d);
	friend istream& getline(std::istream& in, Coche& coche);
};

