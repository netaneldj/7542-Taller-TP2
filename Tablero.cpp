#include "Tablero.h"
#include <iostream>

Tablero::Tablero() {
	this->puntaje = 0;
}

Tablero::~Tablero() {

}

bool Tablero::sumar(int puntos) {
	bool resultado = true;

	std::unique_lock<std::mutex> bloqueo(m);
	this->puntaje+=puntos;
	cv.notify_all();
	return resultado;
}

int Tablero::consultar() {
	int resultado;

	std::unique_lock<std::mutex> bloqueo(m);
	resultado = this->puntaje;
	cv.notify_all();
	return resultado;
}

void Tablero::imprimir() {
	std::unique_lock<std::mutex> bloqueo(m);
	std::cout << "Puntos de Beneficio acumulados: " << this->puntaje << "\n";
	cv.notify_all();
}

