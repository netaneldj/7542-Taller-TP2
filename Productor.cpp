#include "Productor.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Carbon.h"
#include "Hierro.h"
#include "Madera.h"
#include "Trigo.h"

Productor::Productor(Inventario* Inventario, Tablero* tablero) {
	this->tablero = tablero;
	this->inventario = inventario;
}

Productor::~Productor() {
	// nada
}

void Productor::run() {
	while (this->controlarRecursos()) {
		consumir();
		trabajar();
		sumarPuntos();
	}
}

void Productor::trabajar() {
	usleep(60000);
}

bool Productor::establecerRecursos(int carbon, int hierro, int madera, int trigo) {
	this->lista.asignarRecursos(carbon,hierro,madera,trigo);
	return true;
}

void Productor::consumir() {
	Carbon c;
	Hierro h;
	Madera m;
	Trigo t;

	if (this->inventario->hay(c,this->lista.falta(c)) && this->inventario->hay(h,this->lista.falta(h)) && this->inventario->hay(m,this->lista.falta(m)) && this->inventario->hay(t,this->lista.falta(t))) {
		this->consumirNecesario(c);
		this->consumirNecesario(h);
		this->consumirNecesario(m);
		this->consumirNecesario(t);
		this->lista.reiniciar();
	}
}

void Productor::sumarPuntos() {

}

void Productor::consumirNecesario(Recurso item) {
	while(this->lista.falta(item)){
		if(this->inventario->quitar(item)) this->lista.consumir(item);
	}
}

bool Productor::controlarRecursos() {
	return false;
}
