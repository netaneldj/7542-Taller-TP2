#ifndef MINERO_H_
#define MINERO_H_

#include "Recolector.h"

class Minero: public Recolector {
public:
	Minero(ColaBloqueante* fuente, Inventario* inventario);
	~Minero();
};

#endif /* MINERO_H_ */
