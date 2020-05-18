#ifndef MINERO_H_
#define MINERO_H_

#include "Recolector.h"

class Minero: public Recolector {
public:
	Minero(ColaBloqueante* fuente, Inventario* inventario);
	~Minero();
	virtual void cerrarInventario() override;
};

#endif /* MINERO_H_ */
