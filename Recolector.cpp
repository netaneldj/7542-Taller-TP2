#include "Recolector.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Recurso.h"
#include "ColaBloqueante.h"
#include "Inventario.h"

Recolector::Recolector(ColaBloqueante* fuente, Inventario* inventario) {
	this->fuente = fuente;
	this->inventario = inventario;
}

Recolector::~Recolector() {
	// nada
}

Recurso Recolector::recibirRecurso() {
	Recurso item = this->fuente->desencolar();
	if (item.identificador()=="\0") this->inventario->cerrar(item);
	return item;
}

bool Recolector::depositarRecurso(Recurso item) {
	return this->inventario->agregar(item);
}

void Recolector::trabajar() {
	usleep(50000);
}

void Recolector::run(){
	while(not this->fuente->cerrada()){
		Recurso item = recibirRecurso();
		trabajar();
		depositarRecurso(item);
	}
}
