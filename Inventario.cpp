#include "Inventario.h"
#include <iostream>

Inventario::Inventario(std::mutex &m):m(m) {
	this->inventario['C'] = 0;
	this->inventario['H'] = 0;
	this->inventario['M'] = 0;
	this->inventario['T'] = 0;

	this->estaCerrado['C'] = false;
	this->estaCerrado['H'] = false;
	this->estaCerrado['M'] = false;
	this->estaCerrado['T'] = false;

}

Inventario::~Inventario() {
	// TODO Auto-generated destructor stub
}

bool Inventario::cerrado(Recurso item){
	return this->estaCerrado[item.identificador()];
}

int Inventario::cantidad(Recurso item){
	int resultado = 0;

	if (this->estaCerrado[item.identificador()]) {
		resultado = -1; //No va a haber más
	} else {
	resultado = this->inventario[item.identificador()];
	}
	return resultado;
}

bool Inventario::hay(Recurso item, int cantidad) {
	bool resultado = false;

	std::unique_lock<std::mutex> bloqueo(m);
	resultado = this->cantidad(item)>=cantidad;
	cv.notify_all();
	return resultado;
}

bool Inventario::agregar(Recurso item){
	std::unique_lock<std::mutex> bloqueo(m);
	this->inventario[item.identificador()]++;
	cv.notify_all();
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
	cv.notify_all();
	return true;
}

void Inventario::cerrar(Recurso item) {
	std::unique_lock<std::mutex> bloqueo(m);
	estaCerrado[item.identificador()] = true;
	cv.notify_all();
}

void Inventario::imprimir() {
	std::unique_lock<std::mutex> bloqueo(m);
	std::cout << "Recursos restantes:\n";
	std::cout << "  - Trigo: " << inventario['T'] << "\n";
	std::cout << "  - Madera: " << inventario['M'] << "\n";
	std::cout << "  - Carbon: " << inventario['C'] << "\n";
	std::cout << "  - Hierro: " << inventario['H'] << "\n";
	std::cout << "\n";
	cv.notify_all();
}

