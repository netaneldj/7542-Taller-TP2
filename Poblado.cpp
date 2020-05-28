#include "Poblado.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>

Poblado::Poblado() {}

Poblado::~Poblado() {}

void Poblado::ingresarRecursos(std::string ruta){
	std::ifstream Mapa(ruta);
	std::string linea;

	while (not Mapa.eof()) {
		while (getline(Mapa,linea,'\n')) {
			for(char& c : linea) {
			    switch ((int)c) {
			      case (int)'C':
			      {
			    	  colaMinero.encolar('C');
			      }
			      break;
			      case (int)'H':
			      {
			    	  colaMinero.encolar('H');
			      }
			      break;
			      case (int)'M':
			      {
			    	  colaLeniador.encolar('M');
			      }
			      break;
			      case (int)'T':
			      {
			    	  colaAgricultor.encolar('T');
			      }
			      break;
			      default:
			          std::cerr << "Recurso desconocido " << c << "\n";
			    }
			}
		}
	}
	colaMinero.cerrar();
	colaLeniador.cerrar();
	colaAgricultor.cerrar();
}

void Poblado::ingresarTrabajadores(std::string ruta){
	std::ifstream Trabajadores(ruta);
	std::string linea, tipo;
	int cantidad;

	while(not Trabajadores.eof()){
		getline(Trabajadores,linea,'\n');
		if (linea.size()==0) break;
		std::vector<std::string> tupla;
		split(linea,tupla,'=');
		tipo = tupla.front();
		cantidad = (int)tupla.back().at(0)-48;
		crearTrabajadores(tipo,cantidad);
	}
}

void Poblado::crearTrabajadores(std::string tipo, int cantidad){
	if(tipo.compare("Agricultores")==0) {
		if (cantidad==0) {
			this->stock.cerrar('T');
		} else {
			for(int i=0; i<cantidad; i++){
				this->trabajadores.push_back (new Agricultor(colaAgricultor,stock));
				this->stock.incorporarTrabajador("Agricultor");
			}
		}
	} else if (tipo.compare("Leniadores")==0) {
		if (cantidad==0) {
			this->stock.cerrar('M');
		} else {
			for(int i=0; i<cantidad; i++){
				this->trabajadores.push_back(new Leniador(colaLeniador,stock));
				this->stock.incorporarTrabajador("Leniador");
			}
		}
	} else if (tipo.compare("Mineros")==0) {
		if (cantidad==0) {
			this->stock.cerrar('C');
			this->stock.cerrar('H');
		} else {
			for(int i=0; i<cantidad; i++){
				this->trabajadores.push_back(new Minero(colaMinero,stock));
				this->stock.incorporarTrabajador("Minero");
			}
		}
	} else if (tipo.compare("Cocineros")==0) {
		for(int i=0; i<cantidad; i++){
			this->trabajadores.push_back(new Cocinero(stock,puntos));
		}
	} else if (tipo.compare("Carpinteros")==0) {
		for(int i=0; i<cantidad; i++){
			trabajadores.push_back(new Carpintero(stock,puntos));
		}
	} else if (tipo.compare("Armeros")==0) {
		for(int i=0; i<cantidad; i++){
			trabajadores.push_back(new Armero(stock,puntos));
		}
	}
}

void Poblado::iniciarTrabajadores() {
	for (int i = 0; i < (int)trabajadores.size(); ++i) {
		trabajadores[i]->start();
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

void Poblado::split(std::string& str,
		std::vector<std::string>& tupla, char delim){
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		tupla.push_back(token);
	}
}
