#include "Productor.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Carbon.h"
#include "Hierro.h"
#include "Madera.h"
#include "Trigo.h"

Productor::Productor(Inventario* stock, Tablero* puntos):stock(stock),puntos(puntos) {
	//nada
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

	if (this->stock->hay(c,this->lista.falta(c)) && this->stock->hay(h,this->lista.falta(h)) && this->stock->hay(m,this->lista.falta(m)) && this->stock->hay(t,this->lista.falta(t))) {
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
		if(this->stock->quitar(item)) this->lista.consumir(item);
	}
}

bool Productor::controlarRecursos() {
	return false;
}
