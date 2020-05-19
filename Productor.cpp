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

void Productor::consumirNecesario(Recurso item, int cantidad) {
	int i=0;

	while(i<cantidad){
		if(this->stock->quitar(item))i++;
	}
}

bool Productor::controlarRecursos() {
	return false;
}
