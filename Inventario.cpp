#include "Inventario.h"
#include <iostream>

Inventario::Inventario(std::mutex &m):m(m) {
	this->inventario["C"] = 0;
	this->inventario["H"] = 0;
	this->inventario["M"] = 0;
	this->inventario["T"] = 0;

	this->estaCerrado["C"] = false;
	this->estaCerrado["H"] = false;
	this->estaCerrado["M"] = false;
	this->estaCerrado["T"] = false;

}

Inventario::~Inventario() {
	// TODO Auto-generated destructor stub
}

bool Inventario::encuentra(Recurso item){
	return this->inventario.find(item.identificador())!=this->inventario.end();
}

bool Inventario::cerrado(Recurso item){
	if(!this->encuentra(item)) return false;
	return this->estaCerrado[item.identificador()];
}

int Inventario::cantidad(Recurso item){
	int resultado = 0;

	if (not this->encuentra(item)) {
		if (this->estaCerrado[item.identificador()]) {
			resultado = -1; //No va a haber más
		} else {
			resultado = 0;
		}
	} else {
		resultado = this->inventario[item.identificador()];
	}
	return resultado;
}

bool Inventario::hay(Recurso item, int cantidad) {
	return this->cantidad(item)>=cantidad;
}

bool Inventario::agregar(Recurso item){
	std::unique_lock<std::mutex> bloqueo(m);
	if (not this->encuentra(item)) {
		this->inventario[item.identificador()] = 1;
	} else {
		this->inventario[item.identificador()]++;
	}
	return true;
}

bool Inventario::quitar(Recurso item){
	std::unique_lock<std::mutex> bloqueo(m);
	while(this->cantidad(item)==0){
		if (this->estaCerrado[item.identificador()]) {
			return false;
		}
		cv.wait(bloqueo);
	}
	this ->inventario[item.identificador()]--;
	return true;
}

void Inventario::cerrar(Recurso item) {
	std::unique_lock<std::mutex> bloqueo(m);
	estaCerrado[item.identificador()] = true;
	cv.notify_all();
}

void Inventario::imprimir() {
	std::cout << "Recursos restantes:\n";
	std::cout << "  - Trigo: " << inventario["T"] << "\n";
	std::cout << "  - Madera: " << inventario["M"] << "\n";
	std::cout << "  - Carbon: " << inventario["C"] << "\n";
	std::cout << "  - Hierro: " << inventario["H"] << "\n";
	std::cout << "\n";
}

