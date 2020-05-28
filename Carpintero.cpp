#include "Carpintero.h"
#include <iostream>

Carpintero::Carpintero(Inventario &stock,
		Tablero &puntos):Productor(stock, puntos) {}

Carpintero::~Carpintero() {}

void Carpintero::consumir() {
	if (this->stock.hay('M',3) and this->stock.hay('H',1)) {
		this->consumirNecesario('M',3);
		this->consumirNecesario('H',1);
		trabajar();
		sumarPuntos();
	}
}

void Carpintero::sumarPuntos() {
	this->puntos.sumar(2);
}

bool Carpintero::controlarRecursos() {
	return(this->stock.hay('M',3) or not this->stock.cerrado('M'))
			and(this->stock.hay('H',1) or not this->stock.cerrado('H'));
}


