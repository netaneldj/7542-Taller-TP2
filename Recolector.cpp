#include "Recolector.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "ColaBloqueante.h"
#include "Inventario.h"

Recolector::Recolector(ColaBloqueante &fuente,
		Inventario &stock) : fuente(fuente), stock(stock){}

Recolector::~Recolector() {}

char Recolector::recibirRecurso() {
	return this->fuente.desencolar();
}

bool Recolector::depositarRecurso(char recurso) {
	return this->stock.agregar(recurso);
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
	while(not(this->fuente.vacia() and this->fuente.cerrada())){
		char recurso = recibirRecurso();
		trabajar();
		depositarRecurso(recurso);
	}
	this->stock.suspenderTrabajador(this->trabajador());
	if (this->stock.cantidadTrabajador(this->trabajador())==0)
		this->cerrarInventario();
}
