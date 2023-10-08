#include "ListaCoches.h"
#include "Coche.h"
#include <iostream>
#include <fstream>
#include "checkML.h"
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
		tam += 10;
		coche = new Coche[tam];
		for (int i = 0; !entrada.eof() && i < tam; i++)
		{
			entrada >> coche[i];
			getline(entrada, coche[i]);
			cont++;
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
void ListaCoches::mostrarCoches() {
	if (cont == 0) {
		cout << "No hay coches disponibles en la lista." << endl;
	}

	cout << "Lista de Coches:" << endl;
	for (int i = 0; i < cont -1; i++) {
		cout << "Codigo: " << coche[i].getCodigo() << endl;
		cout << "Nombre: " << coche[i].getNombre() << endl;
		cout << "Precio: " << coche[i].getPrecio() << endl;
		//esto es para espaciar los coches entre si 
		cout << "-------------------------" << endl;
	}


}
void ListaCoches::agregarCoche2() {
	Coche nuevoCoche;
	
	cout << "Ingrese datos del coche: ";
	cin >> nuevoCoche;
	agregarCoche(nuevoCoche);
}
void ListaCoches::agregarCoche(const Coche& nuevoCoche) {
	if (cont < tam) {
		coche[cont] = nuevoCoche;
		cont++;
		cout << "Coche agregado exitosamente." << endl;
	}
	else {
		cout << "La lista de coches esta llena. No se puede agregar mas coches." << endl;
	}

}



