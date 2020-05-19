#include "Agricultor.h"
#include "Recolector.h"
#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Trigo.h"
#include <iostream>
#include <string>

Agricultor::Agricultor(ColaBloqueante* fuente,
		Inventario* inventario):Recolector(fuente,inventario) {}

Agricultor::~Agricultor() {}

void Agricultor::cerrarInventario() {
	Trigo t;
	this->stock->cerrar(t);
}

std::string Agricultor::trabajador() {
	return "Agricultor";
}

