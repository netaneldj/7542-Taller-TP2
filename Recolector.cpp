#include "Recolector.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "Recurso.h"
#include "ColaBloqueante.h"
#include "Inventario.h"

Recolector::Recolector(ColaBloqueante* fuente, Inventario* stock) {
	this->stock = stock;
	this->fuente = fuente;
}

Recolector::~Recolector() {}

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

std::string Recolector::trabajador() {
	return "";
}

void Recolector::run(){
	while(not(this->fuente->vacia() and this->fuente->cerrada())){
		Recurso item = recibirRecurso();
		trabajar();
		depositarRecurso(item);
	}
	this->stock->suspenderTrabajador(this->trabajador());
	if (this->stock->cantidadTrabajador(this->trabajador())==0)
		this->cerrarInventario();
}
