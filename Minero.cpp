#include "Minero.h"
#include <iostream>
#include <string>

Minero::Minero(ColaBloqueante &fuente,
		Inventario &inventario):Recolector(fuente, inventario) {}

Minero::~Minero(){}

void Minero::cerrarInventario() {
	this->stock.cerrar('C');
	this->stock.cerrar('H');
}

std::string Minero::trabajador() {
	return "Minero";
}
