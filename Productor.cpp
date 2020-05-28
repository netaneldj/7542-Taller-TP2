#include "Productor.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>

Productor::Productor(Inventario &stock,
		Tablero &puntos):stock(stock),puntos(puntos) {}

Productor::~Productor() {}

void Productor::run() {
	while (this->controlarRecursos())consumir();
}

void Productor::trabajar() {
	usleep(60000);
}

void Productor::consumir() {
	//nada
}

void Productor::sumarPuntos() {
	//nada
}

void Productor::consumirNecesario(char recurso, int cantidad) {
	int i=0;
	while(i<cantidad){
		if(this->stock.quitar(recurso))i++;
	}
}

bool Productor::controlarRecursos() {
	return false;
}
