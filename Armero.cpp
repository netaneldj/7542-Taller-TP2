#include "Armero.h"
#include "Carbon.h"
#include "Hierro.h"
#include <iostream>

Armero::Armero(Inventario* stock, Tablero* puntos):Productor(stock, puntos) {
	this->establecerRecursos(2,2,0,0);
}

Armero::~Armero() {
	// nada
}

void Armero::consumir(){
	Carbon c;
	Hierro h;

	if (this->stock->hay(c,this->lista.falta(c)) and this->stock->hay(h,this->lista.falta(h))) {
		this->consumirNecesario(c);
		this->consumirNecesario(h);
		this->sumarPuntos();
		this->lista.reiniciar();
	}
}

void Armero::sumarPuntos(){
	this->puntos->sumar(3);
}

bool Armero::controlarRecursos() {
	Carbon c;
	Hierro h;

	return (this->stock->hay(c,this->lista.falta(c)) or not this->stock->cerrado(c)) and (this->stock->hay(h,this->lista.falta(h)) or not this->stock->cerrado(h));
}
