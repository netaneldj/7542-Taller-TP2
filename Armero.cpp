#include "Armero.h"
#include <iostream>

Armero::Armero(Inventario &stock, Tablero &puntos):Productor(stock, puntos) {}

Armero::~Armero() {}

void Armero::consumir(){
	if (this->stock.hay('C',2) and this->stock.hay('H',2)) {
		this->consumirNecesario('C',2);
		this->consumirNecesario('H',2);
		trabajar();
		sumarPuntos();
	}
}

void Armero::sumarPuntos(){
	this->puntos.sumar(3);
}

bool Armero::controlarRecursos() {
	return(this->stock.hay('C',2) or not this->stock.cerrado('C'))
			and(this->stock.hay('H',2) or not this->stock.cerrado('H'));
}
