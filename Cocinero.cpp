#include "Cocinero.h"
#include "Carbon.h"
#include "Trigo.h"
#include <iostream>

Cocinero::Cocinero(Inventario* inventario, Tablero* tablero):Productor(inventario,tablero) {
	this->establecerRecursos(1,0,0,2);
}

Cocinero::~Cocinero() {
	// nada
}

void Cocinero::consumir() {
	Carbon c;
	Trigo t;

	if (this->inventario->hay(c,this->lista.falta(c)) and this->inventario->hay(t,this->lista.falta(t))) {
		this->consumirNecesario(c);
		this->consumirNecesario(t);
		this->sumarPuntos();
		this->lista.reiniciar();
	}
}

void Cocinero::sumarPuntos() {
	this->tablero->sumar(5);
}

bool Cocinero::controlarRecursos() {
	Carbon c;
	Trigo t;
	//std::cout << "Cocinero controla recursos\n";
	return (this->inventario->hay(c,this->lista.falta(c)) or not this->inventario->cerrado(c)) and (this->inventario->hay(t,this->lista.falta(t)) or not this->inventario->cerrado(t));
}

