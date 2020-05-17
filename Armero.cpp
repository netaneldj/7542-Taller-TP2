#include "Armero.h"
#include "Carbon.h"
#include "Hierro.h"
#include <iostream>

Armero::Armero(Inventario* inventario, Tablero* tablero):Productor(inventario, tablero) {
	this->establecerRecursos(2,2,0,0);
}

Armero::~Armero() {
	// nada
}

void Armero::consumir(){
	Carbon c;
	Hierro h;

	if (this->inventario->hay(c,this->lista.falta(c)) and this->inventario->hay(h,this->lista.falta(h))) {
		this->consumirNecesario(c);
		this->consumirNecesario(h);
		this->sumarPuntos();
		this->lista.reiniciar();
	}
}

void Armero::sumarPuntos(){
	this->tablero->sumar(5);
}

bool Armero::controlarRecursos() {
	Carbon c;
	Hierro h;
	//std::cout << "Armero controla recursos\n";
	return (this->inventario->hay(c,this->lista.falta(c)) or not this->inventario->cerrado(c)) and (this->inventario->hay(h,this->lista.falta(h)) or not this->inventario->cerrado(h));
}
