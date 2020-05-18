#include "Carpintero.h"
#include "Madera.h"
#include "Hierro.h"
#include <iostream>

Carpintero::Carpintero(Inventario* stock, Tablero* puntos):Productor(stock, puntos) {
	this->establecerRecursos(0,1,3,0);
}

Carpintero::~Carpintero() {
	// nada
}

void Carpintero::consumir() {
	Madera n;
	Hierro h;

	if (this->stock->hay(n,this->lista.falta(n)) and this->stock->hay(h,this->lista.falta(h))) {
		this->consumirNecesario(n);
		this->consumirNecesario(h);
		this->lista.reiniciar();
	}
}

void Carpintero::sumarPuntos() {
	this->puntos->sumar(2);
}

bool Carpintero::controlarRecursos() {
	Madera n;
	Hierro h;

	return (this->stock->hay(n,this->lista.falta(n)) or not this->stock->cerrado(n)) and (this->stock->hay(h,this->lista.falta(h)) or not this->stock->cerrado(h));
}


