#include "ColaBloqueante.h"
#include <iostream>
#define COLA_CERRADA '\0'

ColaBloqueante::ColaBloqueante() {
	this->estaCerrada = false;
}

ColaBloqueante::~ColaBloqueante() {}

void ColaBloqueante::encolar(char recurso) {
    std::unique_lock<std::mutex> bloqueo(m);
    cola.push(recurso);
    cv.notify_all();
}

char ColaBloqueante::desencolar() {
	std::unique_lock<std::mutex> bloqueo(m);
	char recurso = COLA_CERRADA;
    while (cola.empty()){
    	if(estaCerrada)return recurso;
    	cv.wait(bloqueo);
    }
    recurso = cola.front();
    cola.pop();
    cv.notify_all();
    return recurso;
}

bool ColaBloqueante::cerrada() {
	return this->estaCerrada;
}

bool ColaBloqueante::vacia() {
	return cola.empty();
}

void ColaBloqueante::cerrar() {
	std::unique_lock<std::mutex> bloqueo(m);
	estaCerrada = true;
	cv.notify_all();
}





