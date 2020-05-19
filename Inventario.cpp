#include "Inventario.h"
#include <iostream>

Inventario::Inventario(std::mutex &m):m(m){
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

bool Inventario::cerrado(Recurso item){
	return this->estaCerrado[item.identificador()];
}

int Inventario::cantidad(Recurso item){
	return this->inventario[item.identificador()];
}

bool Inventario::hay(Recurso item, int cantidad) {
	return this->cantidad(item)>=cantidad;
}

bool Inventario::agregar(Recurso item){
	std::unique_lock<std::mutex> bloqueo(m);
	this->inventario[item.identificador()]++;
	cv.notify_all();
	return true;
}

bool Inventario::quitar(Recurso item){
	std::unique_lock<std::mutex> bloqueo(m);
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
	cv.notify_all();
}

void Inventario::suspenderTrabajador(std::string trabajador) {
	std::unique_lock<std::mutex> bloqueo(m);
	this->trabajadores[trabajador]--;
	cv.notify_all();
}

int Inventario::cantidadTrabajador(std::string trabajador) {
	return this->trabajadores[trabajador];
}

