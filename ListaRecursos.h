#ifndef LISTARECURSOS_H_
#define LISTARECURSOS_H_

#include <map>

#include "Recurso.h"

class ListaRecursos {
public:
	ListaRecursos();
	~ListaRecursos();
	void asignarRecursos(int carbon, int hierro, int madera, int trigo);
	void reiniciar();
	bool estaVacia();
	bool falta(Recurso item);
	int cantidad(Recurso item);
	void consumir(Recurso item);

private:
	std::map<char, int> lista;
	int carbon, hierro, madera, trigo;

};

#endif /* LISTARECURSOS_H_ */
