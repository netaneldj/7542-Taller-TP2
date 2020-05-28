#include "Agricultor.h"
#include "Recolector.h"
#include "ColaBloqueante.h"
#include "Inventario.h"
#include <iostream>
#include <string>

Agricultor::Agricultor(ColaBloqueante &fuente,
		Inventario &inventario):Recolector(fuente,inventario) {}

Agricultor::~Agricultor() {}

void Agricultor::cerrarInventario() {
	this->stock.cerrar('T');
}

std::string Agricultor::trabajador() {
	return "Agricultor";
}

