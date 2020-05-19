#include "Recurso.h"
#include "ColaBloqueante.h"
#include <iostream>

ColaBloqueante::ColaBloqueante() {
	this->estaCerrada = false;
}

ColaBloqueante::~ColaBloqueante() {}

void ColaBloqueante::encolar(Recurso item) {
    std::unique_lock<std::mutex> bloqueo(m);
    cola.push(item);
    cv.notify_all();
}

Recurso ColaBloqueante::desencolar() {
	Recurso item;
	item.identificador('\0');
	std::unique_lock<std::mutex> bloqueo(m);
    while (cola.empty()){
    	if(estaCerrada)return item;
    	cv.wait(bloqueo);
    }
    item = cola.front();
    cola.pop();
    cv.notify_all();
    return item;
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





