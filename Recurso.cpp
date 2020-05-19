#include "Recurso.h"

Recurso::Recurso() {
	id = '\0';
}

Recurso::~Recurso() {}

void Recurso::identificador(char id) {
	this->id = id;
}

char Recurso::identificador() {
	return this->id;
}
