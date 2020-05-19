#include "Cocinero.h"
#include "Carbon.h"
#include "Trigo.h"
#include <iostream>

Cocinero::Cocinero(Inventario* stock,
		Tablero* puntos):Productor(stock,puntos) {}

Cocinero::~Cocinero() {}

void Cocinero::consumir() {
	Carbon c;
	Trigo t;

	if (this->stock->hay(c,1) and this->stock->hay(t,2)) {
		this->consumirNecesario(c,1);
		this->consumirNecesario(t,2);
		trabajar();
		sumarPuntos();
	}
}

void Cocinero::sumarPuntos() {
	this->puntos->sumar(5);
}

bool Cocinero::controlarRecursos() {
	Carbon c;
	Trigo t;

	return(this->stock->hay(c,1) or not this->stock->cerrado(c))
			and(this->stock->hay(t,2) or not this->stock->cerrado(t));
}

