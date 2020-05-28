#include "Cocinero.h"
#include <iostream>

Cocinero::Cocinero(Inventario &stock,
		Tablero &puntos):Productor(stock,puntos) {}

Cocinero::~Cocinero() {}

void Cocinero::consumir() {
	if (this->stock.hay('C',1) and this->stock.hay('T',2)) {
		this->consumirNecesario('C',1);
		this->consumirNecesario('T',2);
		trabajar();
		sumarPuntos();
	}
}

void Cocinero::sumarPuntos() {
	this->puntos.sumar(5);
}

bool Cocinero::controlarRecursos() {
	return(this->stock.hay('C',1) or not this->stock.cerrado('C'))
			and(this->stock.hay('T',2) or not this->stock.cerrado('T'));
}

