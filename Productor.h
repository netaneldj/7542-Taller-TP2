#ifndef PRODUCTOR_H_
#define PRODUCTOR_H_

#include "Recurso.h"
#include "Inventario.h"
#include "Thread.h"
#include "Tablero.h"
#include <mutex>
#include <map>



class Productor: public Thread {
public:
	Productor(Inventario* stock, Tablero* puntos);
	virtual ~Productor();
	void trabajar();
	virtual void consumir();
	virtual void sumarPuntos();
	virtual bool controlarRecursos();
	void run() override;
	void consumirNecesario(Recurso item, int cantidad);
	Inventario* stock;
	Tablero* puntos;
};

#endif /* PRODUCTOR_H_ */
