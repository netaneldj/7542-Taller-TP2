#ifndef CARPINTERO_H_
#define CARPINTERO_H_

#include "Productor.h"

class Carpintero: public Productor {
public:
	Carpintero(Inventario* inventario, Tablero* tablero);
	 ~Carpintero();
	void consumir() override;
	void sumarPuntos() override;
	bool controlarRecursos() override;
};

#endif /* CARPINTERO_H_ */
