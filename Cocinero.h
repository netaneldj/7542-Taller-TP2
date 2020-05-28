#ifndef COCINERO_H_
#define COCINERO_H_

#include "Productor.h"

class Cocinero: public Productor {
public:
	Cocinero(Inventario &inventario, Tablero &tablero);
	~Cocinero();
	void consumir() override;
	void sumarPuntos() override;
	bool controlarRecursos() override;
};

#endif /* COCINERO_H_ */
