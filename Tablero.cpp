#include "Tablero.h"
#include <iostream>

Tablero::Tablero() {
	this->puntaje = 0;
}

Tablero::~Tablero() {}

void Tablero::sumar(int puntos) {
	std::unique_lock<std::mutex> bloqueo(m);
	this->puntaje+=puntos;
}

int Tablero::consultar() {
	return this->puntaje;
}

void Tablero::imprimir() {
	std::cout << "Puntos de Beneficio acumulados: " << this->puntaje << "\n";
}

