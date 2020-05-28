#include "Leniador.h"
#include <iostream>
#include <string>

Leniador::Leniador(ColaBloqueante &fuente,
		Inventario &inventario):Recolector(fuente, inventario) {}

Leniador::~Leniador() {}

void Leniador::cerrarInventario() {
	this->stock.cerrar('M');
}

std::string Leniador::trabajador() {
	return "Leniador";
}
