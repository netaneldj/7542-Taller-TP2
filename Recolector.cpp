#include "Recolector.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Recurso.h"
#include "ColaBloqueante.h"
#include "Inventario.h"

Recolector::Recolector(ColaBloqueante* fuente, Inventario* stock) {
	this->stock = stock;
	this->fuente = fuente;
}

Recolector::~Recolector() {
	// nada
}

Recurso Recolector::recibirRecurso() {
	return this->fuente->desencolar();
}

bool Recolector::depositarRecurso(Recurso item) {
	return this->stock->agregar(item);
}

void Recolector::trabajar() {
	usleep(50000);
}

void Recolector::cerrarInventario() {
	//nada
}

void Recolector::run(){
	while(not (this->fuente->vacia() and this->fuente->cerrada())){
		Recurso item = recibirRecurso();
		trabajar();
		depositarRecurso(item);
	}
	this->cerrarInventario();
}
