#include "Leniador.h"
#include <iostream>
#include <string>

Leniador::Leniador(ColaBloqueante* fuente,
		Inventario* inventario):Recolector(fuente, inventario) {}

Leniador::~Leniador() {}

void Leniador::cerrarInventario() {
	Madera m;
	this->stock->cerrar(m);
}

std::string Leniador::trabajador() {
	return "Leniador";
}
