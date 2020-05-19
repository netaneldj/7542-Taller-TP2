#include "Armero.h"
#include "Carbon.h"
#include "Hierro.h"
#include <iostream>

Armero::Armero(Inventario* stock, Tablero* puntos):Productor(stock, puntos) {
	//nada
}

Armero::~Armero() {
	// nada
}

void Armero::consumir(){
	Carbon c;
	Hierro h;
	if (this->stock->hay(c,2) and this->stock->hay(h,2)) {
		this->consumirNecesario(c,2);
		this->consumirNecesario(h,2);
	}
}

void Armero::sumarPuntos(){
	this->puntos->sumar(3);
}

bool Armero::controlarRecursos() {
	Carbon c;
	Hierro h;

	return (this->stock->hay(c,2) or not this->stock->cerrado(c)) and (this->stock->hay(h,2) or not this->stock->cerrado(h));
}
