#include "Inventario.h"
#include <iostream>

Inventario::Inventario(){
	this->inventario['C'] = 0;
	this->inventario['H'] = 0;
	this->inventario['M'] = 0;
	this->inventario['T'] = 0;

	this->estaCerrado['C'] = false;
	this->estaCerrado['H'] = false;
	this->estaCerrado['M'] = false;
	this->estaCerrado['T'] = false;

	this->trabajadores["Agricultores"] = 0;
	this->trabajadores["Leniadores"] = 0;
	this->trabajadores["Mineros"] = 0;
}

Inventario::~Inventario() {}

bool Inventario::cerrado(char recurso){
	return this->estaCerrado[recurso];
}

int Inventario::cantidad(char recurso){
	return this->inventario[recurso];
}

bool Inventario::hay(char recurso, int cantidad) {
	return this->cantidad(recurso)>=cantidad;
}

bool Inventario::agregar(char recurso){
	std::unique_lock<std::mutex> bloqueo(m);
	this->inventario[recurso]++;
	cv.notify_all();
	return true;
}

bool Inventario::quitar(char recurso){
	std::unique_lock<std::mutex> bloqueo(m);
	while (this->inventario[recurso]==0) {
		if (this->estaCerrado[recurso]) return false;
		cv.wait(bloqueo);
	}
	this ->inventario[recurso]--;
	cv.notify_all();
	return true;
}

void Inventario::cerrar(char recurso) {
	std::unique_lock<std::mutex> bloqueo(m);
	estaCerrado[recurso] = true;
	cv.notify_all();
}

void Inventario::imprimir() {
	std::cout << "Recursos restantes:\n";
	std::cout << "  - Trigo: " << inventario['T'] << "\n";
	std::cout << "  - Madera: " << inventario['M'] << "\n";
	std::cout << "  - Carbon: " << inventario['C'] << "\n";
	std::cout << "  - Hierro: " << inventario['H'] << "\n";
	std::cout << "\n";
}

void Inventario::incorporarTrabajador(std::string trabajador) {
	std::unique_lock<std::mutex> bloqueo(m);
	this->trabajadores[trabajador]++;
}

void Inventario::suspenderTrabajador(std::string trabajador) {
	std::unique_lock<std::mutex> bloqueo(m);
	this->trabajadores[trabajador]--;
}

int Inventario::cantidadTrabajador(std::string trabajador) {
	return this->trabajadores[trabajador];
}

