#include "Poblado.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"
#include "Carbon.h"
#include "Hierro.h"
#include "Madera.h"
#include "Trigo.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

Poblado::Poblado(std::mutex &m):stock(m),m(m) {
	//nada
}

Poblado::~Poblado() {
	//nada
}

void Poblado::ingresarRecursos(std::string ruta){
	std::ifstream Mapa(ruta);
	std::string line;

	while(not Mapa.eof()){
		getline (Mapa, line, '\n');
		for (char& c : line) {
		    switch((int)c) {
		      case (int)'C':
		      {
		    	  Carbon carbon;
		    	  colaMinero.encolar(carbon);
		      }
		      break;
		      case (int)'H':
		      {
		    	  Hierro hierro;
		    	  colaMinero.encolar(hierro);
		      }
		      break;
		      case (int)'M':
		      {
		    	  Madera madera;
		    	  colaLeniador.encolar(madera);
		      }
		      break;
		      case (int)'T':
		      {
		    	  Trigo trigo;
		    	  colaAgricultor.encolar(trigo);
		      }
		      break;
		    }
		}
	}
}

void Poblado::ingresarTrabajadores(std::string ruta){
	std::ifstream Trabajadores(ruta);
	std::string line, tipo;
	int cantidad;

	while(not Trabajadores.eof()){
		getline (Trabajadores, line, '\n');
		std::vector<std::string> tupla;
		split(line,tupla,'=');
		tipo = tupla.front();
		cantidad = (int)tupla.back().at(0)-48;
		crearTrabajadores(tipo,cantidad);
	}
}

void Poblado::crearTrabajadores(std::string tipo, int cantidad){
	if(tipo.compare("Agricultores")==0) {
		for(int i=0; i<cantidad; i++){
			Thread* t = new Agricultor(&colaAgricultor,&stock);
			//std::cout << "Creo agricultor\n";
			t->start();
			this->trabajadores.push_back(t);
		}
	} else if(tipo.compare("Leniadores")==0) {
		for(int i=0; i<cantidad; i++){
			Thread* t = new Leniador(&colaLeniador,&stock);
			//std::cout << "Creo leniador\n";
			t->start();
			this->trabajadores.push_back(t);
		}
	} else if(tipo.compare("Mineros")==0) {
		for(int i=0; i<cantidad; i++){
			Thread* t = new Minero(&colaMinero,&stock);
			//std::cout << "Creo Minero\n";
			t->start();
			this->trabajadores.push_back(t);
		}
	} else if(tipo.compare("Cocineros")==0) {
		for(int i=0; i<cantidad; i++){
			Thread* t = new Cocinero(&stock,&puntos);
			//std::cout << "Creo cocinero\n";
			t->start();
			this->trabajadores.push_back(t);
		}
	} else if(tipo.compare("Carpinteros")==0) {
		for(int i=0; i<cantidad; i++){
			Thread* t = new Carpintero(&stock,&puntos);
			//std::cout << "Creo carpintero\n";
			t->start();
			trabajadores.push_back(t);
		}
	} else if(tipo.compare("Armeros")==0) {
		for(int i=0; i<cantidad; i++){
			Thread* t = new Armero(&stock,&puntos);
			//std::cout << "Creo armero\n";
			t->start();
			trabajadores.push_back(t);
		}
	}
}

void Poblado::detenerTrabajadores() {
	for (int i = 0; i < (int)trabajadores.size(); ++i) {
		trabajadores[i]->join();
		delete trabajadores[i];
	}
}

void Poblado::imprimir() {
	this->stock.imprimir();
	this->puntos.imprimir();
}

void Poblado::split(std::string& str, std::vector<std::string>& tupla, char delim){
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		tupla.push_back(token);
	}
}
