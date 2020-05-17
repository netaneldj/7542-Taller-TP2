#include "Recurso.h"

Recurso::Recurso() {
	//nada
}

Recurso::~Recurso() {
	// nada
}

void Recurso::identificador(char id) {
	this->id = id;
}

std::string Recurso::identificador() {
	return this->id;
}
