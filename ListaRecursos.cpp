#include "ListaRecursos.h"

ListaRecursos::ListaRecursos() {
	this->carbon = 0;
	this->hierro = 0;
	this->madera = 0;
	this->trigo = 0;
	this->lista["C"] = 0;
	this->lista["H"] = 0;
	this->lista["M"] = 0;
	this->lista["T"] = 0;
}

ListaRecursos::~ListaRecursos() {
	//nada
}

void ListaRecursos::asignarRecursos(int carbon, int hierro, int madera, int trigo) {
	this->carbon = carbon;
	this->hierro = hierro;
	this->madera = madera;
	this->trigo = trigo;
	this->lista["C"] = carbon;
	this->lista["H"] = hierro;
	this->lista["M"] = madera;
	this->lista["T"] = trigo;
}

void ListaRecursos::reiniciar() {
	this->lista["C"] = this->carbon;
	this->lista["H"] = this->hierro;
	this->lista["M"] = this->madera;
	this->lista["T"] = this->trigo;
}

bool ListaRecursos::estaVacia() {
	std::map<std::string, int>::iterator iterador = this->lista.begin();
	while(iterador!=this->lista.end()){
		if(iterador->second>0){
			return false;
		}
		iterador++;
	}
	return true;
}

bool ListaRecursos::falta(Recurso item) {
	return this->lista[item.identificador()]>0;
}

int ListaRecursos::cantidad(Recurso item) {
	return this->lista[item.identificador()];
}

void ListaRecursos::consumir(Recurso item) {
	this->lista[item.identificador()]--;
}
