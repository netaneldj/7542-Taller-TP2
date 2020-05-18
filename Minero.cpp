#include "Minero.h"
#include "Carbon.h"
#include "Hierro.h"
#include <iostream>

Minero::Minero(ColaBloqueante* fuente, Inventario* inventario):Recolector(fuente, inventario) {
	//nada
}

Minero::~Minero(){
	// TODO Auto-generated destructor stub
}

void Minero::cerrarInventario() {
	Carbon c;
	Hierro h;
	this->stock->cerrar(c);
	this->stock->cerrar(h);
}
