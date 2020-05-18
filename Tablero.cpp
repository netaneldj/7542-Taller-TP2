#include "Tablero.h"
#include <iostream>

Tablero::Tablero(std::mutex &m):m(m) {
	this->puntaje = 0;
}

Tablero::~Tablero() {

}

void Tablero::sumar(int puntos) {
	std::unique_lock<std::mutex> bloqueo(m);
	this->puntaje+=puntos;
	cv.notify_all();
}

int Tablero::consultar() {
	int resultado = 0;

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

