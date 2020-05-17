#include "Carpintero.h"
#include "Madera.h"
#include "Hierro.h"
#include <iostream>

Carpintero::Carpintero(Inventario* inventario, Tablero* tablero):Productor(inventario, tablero) {
	this->establecerRecursos(0,1,3,0);
}

Carpintero::~Carpintero() {
	// nada
}

void Carpintero::consumir() {
	Madera n;
	Hierro h;

	if (this->inventario->hay(n,this->lista.falta(n)) and this->inventario->hay(h,this->lista.falta(h))) {
		this->consumirNecesario(n);
		this->consumirNecesario(h);
		this->sumarPuntos();
		this->lista.reiniciar();
	}
}

void Carpintero::sumarPuntos() {
	this->tablero->sumar(2);
}

bool Carpintero::controlarRecursos() {
	Madera n;
	Hierro h;
	//std::cout << "Carpintero controla recursos\n";
	return (this->inventario->hay(n,this->lista.falta(n)) or not this->inventario->cerrado(n)) and (this->inventario->hay(h,this->lista.falta(h)) or not this->inventario->cerrado(h));
}


