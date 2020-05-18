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

Poblado::Poblado(std::mutex &ms,std::mutex &mp):puntos(mp),stock(ms) {
	// nada
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
	colaMinero.cerrar();
	colaLeniador.cerrar();
	colaAgricultor.cerrar();
}

void Poblado::ingresarTrabajadores(std::string ruta){
	std::ifstream Trabajadores(ruta);
	std::string linea, tipo;
	int cantidad;

	while(not Trabajadores.eof()){
		getline (Trabajadores, linea, '\n');
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
			Trigo t;
			this->stock.cerrar(t);
		} else {
			for(int i=0; i<cantidad; i++){
				this->trabajadores.push_back (new Agricultor(&colaAgricultor,&stock));
			}
		}
	} else if(tipo.compare("Leniadores")==0) {
		if (cantidad==0) {
			Madera n;
			this->stock.cerrar(n);
		} else {
			for(int i=0; i<cantidad; i++){
				this->trabajadores.push_back( new Leniador(&colaLeniador,&stock));
			}
		}
	} else if(tipo.compare("Mineros")==0) {
		if (cantidad==0) {
			Carbon c;
			Hierro h;
			this->stock.cerrar(c);
			this->stock.cerrar(h);
		} else {
			for(int i=0; i<cantidad; i++){
				this->trabajadores.push_back(new Minero(&colaMinero,&stock));
			}
		}
	} else if(tipo.compare("Cocineros")==0) {
		for(int i=0; i<cantidad; i++){
			this->trabajadores.push_back(new Cocinero(&stock,&puntos));
		}
	} else if(tipo.compare("Carpinteros")==0) {
		for(int i=0; i<cantidad; i++){
			trabajadores.push_back(new Carpintero(&stock,&puntos));
		}
	} else if(tipo.compare("Armeros")==0) {
		for(int i=0; i<cantidad; i++){
			trabajadores.push_back(new Armero(&stock,&puntos));
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

void Poblado::split(std::string& str, std::vector<std::string>& tupla, char delim){
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		tupla.push_back(token);
	}
}
