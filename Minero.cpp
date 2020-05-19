#include "Minero.h"
#include "Carbon.h"
#include "Hierro.h"
#include <iostream>
#include <string>

Minero::Minero(ColaBloqueante* fuente,
		Inventario* inventario):Recolector(fuente, inventario) {}

Minero::~Minero(){}

void Minero::cerrarInventario() {
	Carbon c;
	Hierro h;
	this->stock->cerrar(c);
	this->stock->cerrar(h);
}

std::string Minero::trabajador() {
	return "Minero";
}
