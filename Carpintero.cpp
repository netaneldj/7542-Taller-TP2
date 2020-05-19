#include "Carpintero.h"
#include "Madera.h"
#include "Hierro.h"
#include <iostream>

Carpintero::Carpintero(Inventario* stock, Tablero* puntos):Productor(stock, puntos) {
	//nada
}

Carpintero::~Carpintero() {
	// nada
}

void Carpintero::consumir() {
	Madera n;
	Hierro h;

	if (this->stock->hay(n,3) and this->stock->hay(h,1)) {
		this->consumirNecesario(n,3);
		this->consumirNecesario(h,1);
		trabajar();
		sumarPuntos();
	}
}

void Carpintero::sumarPuntos() {
	this->puntos->sumar(2);
}

bool Carpintero::controlarRecursos() {
	Madera n;
	Hierro h;

	return (this->stock->hay(n,3) or not this->stock->cerrado(n)) and (this->stock->hay(h,1) or not this->stock->cerrado(h));
}


