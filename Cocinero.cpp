#include "Cocinero.h"
#include "Carbon.h"
#include "Trigo.h"
#include <iostream>

Cocinero::Cocinero(Inventario* stock, Tablero* puntos):Productor(stock,puntos) {
	this->establecerRecursos(1,0,0,2);
}

Cocinero::~Cocinero() {
	// nada
}

void Cocinero::consumir() {
	Carbon c;
	Trigo t;

	if (this->stock->hay(c,this->lista.falta(c)) and this->stock->hay(t,this->lista.falta(t))) {
		this->consumirNecesario(c);
		this->consumirNecesario(t);
		this->lista.reiniciar();
	}
}

void Cocinero::sumarPuntos() {
	this->puntos->sumar(5);
}

bool Cocinero::controlarRecursos() {
	Carbon c;
	Trigo t;

	return (this->stock->hay(c,this->lista.falta(c)) or not this->stock->cerrado(c)) and (this->stock->hay(t,this->lista.falta(t)) or not this->stock->cerrado(t));
}

