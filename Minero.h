#ifndef MINERO_H_
#define MINERO_H_

#include "Recolector.h"
#include <string>

class Minero: public Recolector {
public:
	Minero(ColaBloqueante &fuente, Inventario &inventario);
	~Minero();
	virtual void cerrarInventario() override;
	virtual std::string trabajador() override;
};

#endif /* MINERO_H_ */
