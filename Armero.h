#ifndef ARMERO_H_
#define ARMERO_H_

#include "Productor.h"

class Armero: public Productor {
public:
	Armero(Inventario* inventario, Tablero* tablero);
	~Armero();
	void consumir() override;
	void sumarPuntos() override;
	bool controlarRecursos() override;
};

#endif /* ARMERO_H_ */
