#ifndef AGRICULTOR_H_
#define AGRICULTOR_H_

#include "Recolector.h"
#include "Trigo.h"


class Agricultor: public Recolector {
public:
	Agricultor(ColaBloqueante* fuente, Inventario* inventario);
	~Agricultor();
};

#endif /* AGRICULTOR_H_ */
