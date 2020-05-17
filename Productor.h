#ifndef PRODUCTOR_H_
#define PRODUCTOR_H_

#include "Recurso.h"
#include "Inventario.h"
#include "Thread.h"
#include "ListaRecursos.h"
#include "Tablero.h"
#include <mutex>
#include <map>



class Productor: public Thread {
public:
	Productor(Inventario* inventario, Tablero* tablero);
	virtual ~Productor();
	void trabajar();
	virtual void consumir();
	virtual void sumarPuntos();
	virtual bool controlarRecursos();
	void run() override;
	void consumirNecesario(Recurso item);
	bool establecerRecursos(int carbon, int hierro, int madera, int trigo);
	Inventario* inventario;
	Tablero* tablero;
	ListaRecursos lista;
	std::mutex m;
	std::condition_variable cv;
};

#endif /* PRODUCTOR_H_ */
