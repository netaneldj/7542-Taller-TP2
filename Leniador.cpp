#include "Leniador.h"
#include <iostream>

Leniador::Leniador(ColaBloqueante* fuente, Inventario* inventario):Recolector(fuente, inventario) {
	//nada
}

Leniador::~Leniador() {
	// TODO Auto-generated destructor stub
}

void Leniador::cerrarInventario() {
	Madera m;
	this->stock->cerrar(m);
}
